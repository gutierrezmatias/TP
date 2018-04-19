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
parser.Attach(loggerObserver);
   Parametros parametros = parser.CrearSuperConfig();
   std::string pathIndicado = "./Configs/"; //implementar metodo para levantar de consola
   std::string nameIndicado = "configIndicado.yaml";
   std::string input = "";

    // How to get a string/sentence with spaces
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

    if(!this->inicializar(pathDefaultConfig, fullPath))
    {
       NotifyWarning("Inicia: no se pudo levantar ningun archivo", "UTILS");
    }
    else
    {
        parametros = parser.read_yaml_Parametros(fullPath,pathDefaultConfig, parametros);
    }
  NotifyLevel(GenerarLevel(parametros.level));

    this->model = model;
    this->model->setCasaca(parametros.casaca);
    //setear Formacion
    char c1[100];
    string form = parametros.formacion;
    for(int i = 0; i<form.size(); i++)
    {
        c1[i] = form.at(i);
    }

    char c2[] = "3-3";
    char c3[] = "3-1-2";
    char c4[] = "3-2-1";


    NotifyMessage("Inicia: setendo formacion...", "UTILS");
    if((strncasecmp(c1,c2, 3))==0)
    {
        this->model->setFormacion(&(this->formacion33));
    }

    if((strncasecmp(c1,c3, 3))==0)
    {
        this->model->setFormacion(&(this->formacion312));
    }

    if((strncasecmp(c1,c4, 3))==0)
    {
        this->model->setFormacion(&(this->formacion321));
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
    NotifyMessage("Iniciando: Comprobando que exista un archivo de configuración", "UTILS");
    return ((parser.fileExists(pathDefault))||(parser.fileExists(pathIndicado)));
}


int Util_Configuracion::GenerarLevel(std::string &name)
{
    try
    {
        NotifyMessage(" Generar Level: asignando nivel", "UTILS");
        char c1[100];
        for(int i = 0; i<name.size(); i++)
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
        NotifyError("Generar Level: error fatal al asignar formacion", "UTILS");
        return ex; //codigo de error
    }
}

int Util_Configuracion::GenerarCasaca(std::string &name)
{
    try
    {
        NotifyMessage("Generar Casaca: asignando casaca", "UTILS");
        char c1[100];
        for(int i = 0; i<name.size(); i++)
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
        NotifyError("Generar Casaca: error fatal al asignar casaca", "UTILS");
        return ex; //codigo de error
    }
}


