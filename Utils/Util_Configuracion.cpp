#include "Util_Configuracion.h"
#include <yaml-cpp/yaml.h>
#include  <yaml-cpp/exceptions.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <boost/algorithm/string.hpp>

Util_Parser parser;
const std::string pathDefaultConfig = "./Configs/config.yaml";


Util_Configuracion::Util_Configuracion(Model* model, Util_LoggerObserver* loggerObserver)
{
   this->Attach(loggerObserver);
   parser.Attach(loggerObserver);
   try
   {
        Parametros parametros = parser.CrearSuperConfig();

        std::string pathIndicado = "./Configs/"; //implementar metodo para levantar de consola
        std::string nameIndicado = "configIndicado.yaml";
        std::string input = "";

        cout << "=================================================================\n";
        cout << " Ingrese el nombre del archivo de configuracion que corresponda: \n";
        cout << "=================================================================\n";
        cout << ">>> ";
        getline(cin, input);
        cout << "=================================================================\n";
        if(input != "")
        {
            nameIndicado = input;
        }

        std::stringstream ss;
        ss << pathIndicado << nameIndicado;
        std::string fullPath = ss.str();

        NotifyMessage("El siguiente es el path que escogió el usuario: ", "Util_Configuracion.cpp");
        NotifyMessage(fullPath, "Util_Configuracion.cpp");
        if(!this->inicializar(pathDefaultConfig, fullPath))
        {
           NotifyWarning("No se pudo levantar ningun archivo de configuración.", "Util_Configuracion.cpp");
        }
        else
        {
            NotifyMessage("Comenzamos el parseo propiamente dicho.", "Util_Configuracion.cpp");
            parametros = parser.read_yaml_Parametros(fullPath, pathDefaultConfig, parametros);
        }

        NotifyMessage("Hemos pasado la etapa de parseo.", "Util_Configuracion.cpp");
        this->model = model;

        NotifyMessage("El nivel de debug es: ", "Util_Configuracion.cpp");
        NotifyMessage(parametros.level, "Util_Configuracion.cpp");
        NotifyLevel(GenerarLevel(parametros.level));

        NotifyMessage("La casaca a usara es: ", "Util_Configuracion.cpp");
        NotifyMessage(parametros.casaca, "Util_Configuracion.cpp");
        this->model->setCasaca(parametros.casaca);

        //setear Formacion
        char c1[100];
        string form = parametros.formacion;
        for(unsigned i = 0; i<form.size(); i++)
        {
            c1[i] = form.at(i);
        }

        char c2[] = "3-3";
        char c3[] = "3-1-2";
        char c4[] = "3-2-1";

        NotifyMessage("Iniciamos el seteo de la formacion: ", "Util_Configuracion.cpp");
        if((strncasecmp(c1,c2, 3))==0)
        {
            NotifyMessage("Seteamos la formación: 3-3", "Util_Configuracion.cpp");
            this->model->setFormacion(&(this->formacion33));
        }

        if((strncasecmp(c1,c3, 3))==0)
        {
            NotifyMessage("Seteamos la formación: 3-1-2", "Util_Configuracion.cpp");
            this->model->setFormacion(&(this->formacion312));
        }

        if((strncasecmp(c1,c4, 3))==0)
        {
            NotifyMessage("Seteamos la formación: 3-2-1", "Util_Configuracion.cpp");
            this->model->setFormacion(&(this->formacion321));
        }
    }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "Util_Configuracion.cpp");
        NotifyError(re.what(), "Util_Configuracion.cpp");
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "Util_Configuracion.cpp");
        NotifyError(ex.what(), "Util_Configuracion.cpp");
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "Util_Configuracion.cpp");
    }
}

void Util_Configuracion::close()
{

}

Util_Configuracion::~Util_Configuracion()
{
    //this->close();
}


bool Util_Configuracion::inicializar(std::string pathIndicado, std::string pathDefault)
{
    bool result = false;
    try
    {
        NotifyMessage("Iniciando: Comprobando que exista un archivo de configuración", "Util_Configuracion.cpp");
        result = ((parser.fileExists(pathDefault))||(parser.fileExists(pathIndicado)));
    }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "Util_Configuracion.cpp");
        NotifyError(re.what(), "Util_Configuracion.cpp");
        result = false;
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "Util_Configuracion.cpp");
        NotifyError(ex.what(), "Util_Configuracion.cpp");
        result = false;
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "Util_Configuracion.cpp");
        result = false;
    }
    return result;
}


int Util_Configuracion::GenerarLevel(std::string &name)
{
    int result = 0;
    try
    {
        NotifyMessage("Transformamos el string que representa el level de debug en entero", "Util_Configuracion.cpp");
        char c1[100];
        for(unsigned i = 0; i<name.size(); i++)
        {
            name.at(i) = toupper(name.at(i));
            c1[i] = name.at(i);
        }

        char c2[] = "DEBUG";
        char c3[] = "INFO";
        char c4[] = "ERROR";

        if((strncasecmp(c1,c2,4))==0)
        {
            return 3;
        }

        if((strncasecmp(c1,c3,4))==0)
        {
            return 2;
        }

        if((strncasecmp(c1,c4,4))==0)
        {
            return 1;
        }
        throw(0);
    }
    catch (int ex)
    {
        NotifyError("Generar Level: error fatal al asignar formacion", "Util_Configuracion.cpp");
        result = ex;
    }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "Util_Configuracion.cpp");
        NotifyError(re.what(), "Util_Configuracion.cpp");
        result = 0;
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "Util_Configuracion.cpp");
        NotifyError(ex.what(), "Util_Configuracion.cpp");
        result = 0;
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "Util_Configuracion.cpp");
        result = 0;
    }
    return result;
}

int Util_Configuracion::GenerarCasaca(std::string &name)
{
    int result = 0;
    try
    {
        NotifyMessage("Generar Casaca: asignando casaca", "Util_Configuracion.cpp");
        char c1[100];
        for(unsigned i = 0; i<name.size(); i++)
        {
            name.at(i) = toupper(name.at(i));
            c1[i] = name.at(i);
        }

        char c2[] = "PRINCIPAL";
        char c3[] = "SUPLENTE";
        char c4[] = "AUXILIAR";

        if((strncasecmp(c1,c2,2))==0)
        {
            return 0;
        }

        if((strncasecmp(c1,c3,2))==0)
        {
            name = "suplente";
            return 1;
        }

        if((strncasecmp(c1,c4,2))==0)
        {
            //CHEQUEAR
            name = "auxiliar";
            return 1;
        }

        throw(-1);
    }
    catch (int ex)
    {
        NotifyError("Generar Casaca: error fatal al asignar casaca", "Util_Configuracion.cpp");
        result = ex; //codigo de error
    }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "Util_Configuracion.cpp");
        NotifyError(re.what(), "Util_Configuracion.cpp");
        result = 0;
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "Util_Configuracion.cpp");
        NotifyError(ex.what(), "Util_Configuracion.cpp");
        result = 0;
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "Util_Configuracion.cpp");
        result = 0;
    }
    return result;
}


