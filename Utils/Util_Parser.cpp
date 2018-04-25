#include <yaml-cpp/yaml.h>
#include  <yaml-cpp/exceptions.h>
#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>

using namespace std;

#include "Util_Parser.h"
//#include "Util_Logger.h"

std::vector<Equipo> equipos;
std::vector<Debug> debugs;

bool Util_Parser::fileExists(const std::string& name)
{
    try
    {
        NotifyMessage("FileExists: comprobando si existe archivo...", "Util_Parser.cpp");
        ifstream f(name.c_str());

        if (f.good())
        {
            f.seekg(0, ios::end); // va al final de archivo
            if(f.tellg()==0)
            {
                NotifyError("fileExists: archivo "+ name +" vacio", "Util_Parser.cpp");
                f.close();
                return false;
            }
            else
            {
                NotifyWarning("fileExists: archivo "+ name +" obtenido correctamente", "Util_Parser.cpp");
                f.close();
                return true;
            }
        }
        else
        {
            NotifyError("fileExists: archivo "+ name +" inválido", "Util_Parser.cpp");
            f.close();
            return false;
        }
    }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "Util_Parser.cpp");
        NotifyError(re.what(), "Util_Parser.cpp");
        return false;
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "Util_Parser.cpp");
        NotifyError(ex.what(), "Util_Parser.cpp");
        return false;
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "Util_Parser.cpp");
        return false;
    }
}

inline bool Util_Parser::levelValido(std::string &name)
{
    try
    {
        if (name.size() > 99 )
        {
            NotifyWarning("levelValido: valor de level demasiado largo", "Util_Parser.cpp");
            return false;
        }

        char c1[100];
        for(unsigned i = 0; i<name.size(); i++)
        {
            name.at(i) = toupper(name.at(i));
            c1[i] = name.at(i);
        }

        char c2[] = "DEBUG";
        char c3[] = "INFO";
        char c4[] = "ERROR";

        NotifyMessage("levelValido: obteniendo level ", "Util_Parser.cpp");
        if((strncasecmp(c1,c2,2))==0)
        {
            name = "debug";
            NotifyMessage("levelValido: level seteado:" + name, "Util_Parser.cpp");;
            return true;
        }

        if((strncasecmp(c1,c3,2))==0)
        {
            name = "info";
            NotifyMessage("levelValido: level seteado:" + name, "Util_Parser.cpp");
            return true;
        }

        if((strncasecmp(c1,c4,2))==0)
        {
            name = "error";
            NotifyMessage("levelValido: level seteado:" + name, "Util_Parser.cpp");
            return true;
        }

        name = "";
        NotifyWarning("levelValido: valor de level invalido", "Util_Parser.cpp");
        return false;
    }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "Util_Parser.cpp");
        NotifyError(re.what(), "Util_Parser.cpp");
        return false;
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "Util_Parser.cpp");
        NotifyError(ex.what(), "Util_Parser.cpp");
        return false;
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "Util_Parser.cpp");
        return false;
    }
}
//pasar por referencia
inline bool Util_Parser::casacaValido(std::string &name)
{
    try
    {
        if (name.size() > 99 )
        {
            NotifyWarning("casacaValido: valor de casaca demasiado largo", "Util_Parser.cpp");
            return false;
        }
        char c1[100];
        for(unsigned i = 0; i<name.size(); i++)
        {
            name.at(i) = toupper(name.at(i));
            c1[i] = name.at(i);
        }

        char c2[] = "PRINCIPAL";
        char c3[] = "SUPLENTE";
        char c4[] = "AUXILIAR";

        NotifyMessage("casacaValido: obteniendo casaca ", "Util_Parser.cpp");
        if((strncasecmp(c1,c2,2))==0)
        {
            name = "principal";
            NotifyMessage("casacaValido: casaca seteado:" + name, "Util_Parser.cpp");
            return true;
        }

        if((strncasecmp(c1,c3,2))==0)
        {
            name = "suplente";
            NotifyMessage("casacaValido: casaca seteado:" + name, "Util_Parser.cpp");
            return true;
        }

        if((strncasecmp(c1,c4,2))==0)
        {
            name = "auxiliar";
            NotifyWarning("casaca Auxiliar: casaca seteado:" + name, "Util_Parser.cpp");
            return true;
        }

        name = "";
        NotifyWarning("casacaValido: valor de casaca invalido", "Util_Parser.cpp");
        return false;
    }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "Util_Parser.cpp");
        NotifyError(re.what(), "Util_Parser.cpp");
        return false;
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "Util_Parser.cpp");
        NotifyError(ex.what(), "Util_Parser.cpp");
        return false;
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "Util_Parser.cpp");
        return false;
    }
}
//pasar por referencia
inline bool Util_Parser::formacionValido(std::string &name)
{
    try
    {
        if (name.size() > 99 )
        {
            NotifyWarning("formacionValido: valor de formacion demasiado largo", "Util_Parser.cpp");
            return false;
        }
        char c1[100];
        for(unsigned i = 0; i<name.size(); i++)
        {
            c1[i] = name.at(i);
        }
        char c2[] = "3-3";
        char c3[] = "3-1-2";
        char c4[] = "3-2-1";

        NotifyMessage("formacionValido: obteniendo formacion ", "Util_Parser.cpp");
        if((strncasecmp(c1,c2,3))==0)
        {
            name = "3-3";
            NotifyMessage("formacionValido: formacion seteado:" + name, "Util_Parser.cpp");
            return true;
        }

        if((strncasecmp(c1,c3,3))==0)
        {
            name = "3-1";
            NotifyMessage("formacionValido: formacion seteado:" + name, "Util_Parser.cpp");
            return true;
        }

        if((strncasecmp(c1,c4,3))==0)
        {
            name = "3-2-1";
            NotifyMessage("casacaValido: formacion seteado:" + name, "Util_Parser.cpp");
            return true;
        }
        name = "";
        NotifyWarning("formacionValido: valor de formacion invalido", "Util_Parser.cpp");
        return false;
    }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "Util_Parser.cpp");
        NotifyError(re.what(), "Util_Parser.cpp");
        return false;
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "Util_Parser.cpp");
        NotifyError(ex.what(), "Util_Parser.cpp");
        return false;
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "Util_Parser.cpp");
        return false;
    }
}

Equipo Util_Parser::read_yaml_Equipo(std::vector<YAML::Node> baseNode)
{
    try
    {
        equipos.clear();
        for (auto &document : baseNode)
        {
            equipos.emplace_back(document["equipo"]);
        }
    }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "Util_Parser.cpp");
        NotifyError(re.what(), "Util_Parser.cpp");
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "Util_Parser.cpp");
        NotifyError(ex.what(), "Util_Parser.cpp");
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "Util_Parser.cpp");
    }
    return equipos.at(0);
}

Debug Util_Parser::read_yaml_Debug(std::vector<YAML::Node> baseNode)
{
    try
    {
        debugs.clear();
        for (auto &document : baseNode)
        {
            debugs.emplace_back(document["debug"]);
        }
    }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "Util_Parser.cpp");
        NotifyError(re.what(), "Util_Parser.cpp");
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "Util_Parser.cpp");
        NotifyError(ex.what(), "Util_Parser.cpp");
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "Util_Parser.cpp");
    }
    return debugs.at(0);
}

void Util_Parser::mezclar(Parametros &resultado, Parametros parametro)
{
   try
   {
        NotifyMessage("mezclar: obteniendo parametros de memoria", "Util_Parser.cpp");
        if(!levelValido(resultado.level))
        {
            resultado.level = parametro.level;
        }

        if(!formacionValido( resultado.formacion))
        {
            resultado.formacion = parametro.formacion;
        }

        if(!casacaValido( resultado.casaca))
        {
            resultado.casaca = parametro.casaca;
        }
    }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "Util_Parser.cpp");
        NotifyError(re.what(), "Util_Parser.cpp");
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "Util_Parser.cpp");
        NotifyError(ex.what(), "Util_Parser.cpp");
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "Util_Parser.cpp");
    }
}

void Util_Parser::llenarParametrosObtenidos( std::vector<YAML::Node> baseNode, Parametros &parametrosObtenidos)
{
    try
    {
        Debug debugParseado = read_yaml_Debug(baseNode);
        parametrosObtenidos.level = debugParseado.get_level();
        if(levelValido( parametrosObtenidos.level))
        {
            NotifyMessage("llenarParametrosObtenidos: level obtenido", "Util_Parser.cpp");
        }
        else
        {
            NotifyWarning("llenarParametrosObtenidos: level invalido", "Util_Parser.cpp");
            parametrosObtenidos.esValido = 0;
        }
    }
    catch(YAML::Exception ex)
    {
        NotifyError("llenarParametrosObtenidos: no se pudo obtener el nodo Debug", "Util_Parser.cpp");
        parametrosObtenidos.esValido = 0;
    }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "Util_Parser.cpp");
        NotifyError(re.what(), "Util_Parser.cpp");
        parametrosObtenidos.esValido = 0;
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "Util_Parser.cpp");
        NotifyError(ex.what(), "Util_Parser.cpp");
        parametrosObtenidos.esValido = 0;
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "Util_Parser.cpp");
        parametrosObtenidos.esValido = 0;
    }

    try
    {
        Equipo equipoParseado  = read_yaml_Equipo(baseNode);
        parametrosObtenidos.casaca = equipoParseado.get_casaca();
        if(casacaValido(parametrosObtenidos.casaca))
        {
            NotifyMessage("llenarParametrosObtenidos: casaca obtenido", "Util_Parser.cpp");
        }
        else
        {
            NotifyWarning("llenarParametrosObtenidos: casaca invalido", "Util_Parser.cpp");
            parametrosObtenidos.esValido = 0;
        }
        parametrosObtenidos.formacion = equipoParseado.get_formacion();
        if(formacionValido(parametrosObtenidos.formacion))
        {
            NotifyMessage("llenarParametrosObtenidos: formacion obtenido", "Util_Parser.cpp");
        }
        else
        {
            NotifyWarning("llenarParametrosObtenidos: formacion invalido", "Util_Parser.cpp");
            parametrosObtenidos.esValido = 0;
        }
    }
    catch(YAML::Exception ex)
    {
        NotifyError("llenarParametrosObtenidos: no se pudo obtener el nodo Equipo", "Util_Parser.cpp");
        parametrosObtenidos.esValido = 0;
    }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "Util_Parser.cpp");
        NotifyError(re.what(), "Util_Parser.cpp");
        parametrosObtenidos.esValido = 0;
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "Util_Parser.cpp");
        NotifyError(ex.what(), "Util_Parser.cpp");
        parametrosObtenidos.esValido = 0;
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "Util_Parser.cpp");
        parametrosObtenidos.esValido = 0;
    }
}

Parametros Util_Parser::read_yaml_Parametros(std::string pathIndicado, std::string pathDefault, Parametros superParametros)
{
    try
    {
        std::vector<YAML::Node> baseNode;

        Parametros parametrosObtenidosIndicado = Parametros("","",""); //se crea como valido
        Parametros parametrosObtenidosDefault = Parametros("","",""); //se crea como valido

        if (fileExists(pathIndicado))
        {
            NotifyMessage("read_yaml_Parametros: cargar path indicado por parametro", "Util_Parser.cpp");
            baseNode = YAML::LoadAllFromFile(pathIndicado);
        }
        else
        {
            if(fileExists(pathDefault))
            {
                NotifyMessage("read_yaml_Parametros: cargar path indicado por default", "Util_Parser.cpp");
                baseNode = YAML::LoadAllFromFile(pathDefault);
            }
        }
        llenarParametrosObtenidos(baseNode, parametrosObtenidosIndicado);

        if (parametrosObtenidosIndicado.esValido == 0)
        {
            NotifyWarning("read_yaml_Parametros: parametros obtenidos invalidos", "Util_Parser.cpp");
            baseNode = YAML::LoadAllFromFile(pathDefault);
            llenarParametrosObtenidos(baseNode, parametrosObtenidosDefault);
            mezclar (parametrosObtenidosIndicado, parametrosObtenidosDefault);
            mezclar(parametrosObtenidosIndicado, superParametros);
        }

        return parametrosObtenidosIndicado;
    }
    catch(YAML::Exception ex)
    {
        NotifyError("read_yaml_Parametros: parametros obtenidos invalidos", "Util_Parser.cpp");
        return superParametros;
    }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "Util_Parser.cpp");
        NotifyError(re.what(), "Util_Parser.cpp");
        return superParametros;
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "Util_Parser.cpp");
        NotifyError(ex.what(), "Util_Parser.cpp");
        return superParametros;
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "Util_Parser.cpp");
        return superParametros;
    }
}

Parametros Util_Parser::CrearSuperConfig()
{
    NotifyMessage("Creamos una configuración por si todos los archivos de configuración fallan.", "Util_Parser.cpp");
    return Parametros("debug","3-3","auxiliar");
}
