#include <yaml-cpp/yaml.h>
#include  <yaml-cpp/exceptions.h>
#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>


using namespace std;

#include "Util_Parser.h"
#include "Util_Logger.h"

std::vector<Equipo> equipos;
std::vector<Debug> debugs;


inline bool Util_Parser::fileExists(const std::string& name)
{
NotifyMessage("FileExists: comprobando si existe archivo...", "UTILS");
    ifstream f(name.c_str());
    if (f.good())
    {
        f.close();
        return true;
    }
    else
    {
        f.close();
        return false;
    }
}

inline bool Util_Parser::levelValido(std::string &name)
{

if (name.size() > 99 )
{
NotifyWarning("levelValido: valor de level demasiado largo", "UTILS");
return false;
}

    char c1[100];
    for(int i = 0; i<name.size(); i++)
    {
        name.at(i) = toupper(name.at(i));
        c1[i] = name.at(i);
    }

    char c2[] = "DEBUG";
    char c3[] = "INFO";
    char c4[] = "ERROR";

NotifyMessage("levelValido: obteniendo level ", "UTILS");
    if((strncasecmp(c1,c2,2))==0)
    {
        name = "debug";
        NotifyMessage("levelValido: level seteado:" + name, "UTILS");;
        return true;
    }

    if((strncasecmp(c1,c3,2))==0)
    {
        name = "info";
        NotifyMessage("levelValido: level seteado:" + name, "UTILS");
        return true;
    }

    if((strncasecmp(c1,c4,2))==0)
    {
        name = "error";
        NotifyMessage("levelValido: level seteado:" + name, "UTILS");
        return true;
    }

    name = "";
    NotifyWarning("levelValido: valor de level invalido", "UTILS");
    return false;

}
//pasar por referencia
inline bool Util_Parser::casacaValido(std::string &name)
{
if (name.size() > 99 )
{
NotifyWarning("casacaValido: valor de casaca demasiado largo", "UTILS");
return false;
}
    char c1[100];
    for(int i = 0; i<name.size(); i++)
    {
        name.at(i) = toupper(name.at(i));
        c1[i] = name.at(i);
    }

    char c2[] = "PRINCIPAL";
    char c3[] = "SUPLENTE";
    char c4[] = "AUXILIAR";

    NotifyMessage("casacaValido: obteniendo casaca ", "UTILS");
    if((strncasecmp(c1,c2,2))==0)
    {
        name = "principal";
        NotifyMessage("casacaValido: casaca seteado:" + name, "UTILS");
        return true;
    }

    if((strncasecmp(c1,c3,2))==0)
    {
        name = "suplente";
         NotifyMessage("casacaValido: casaca seteado:" + name, "UTILS");
        return true;
    }
    if((strncasecmp(c1,c4,2))==0)
    {
        name = "auxiliar";
        NotifyWarning("casaca Auxiliar: casaca seteado:" + name, "UTILS");
        return true;
    }
    name = "";
    NotifyWarning("casacaValido: valor de casaca invalido", "UTILS");
    return false;
}
//pasar por referencia
inline bool Util_Parser::formacionValido(std::string &name)
{
if (name.size() > 99 )
{
NotifyWarning("formacionValido: valor de formacion demasiado largo", "UTILS");
return false;
}
    char c1[100];
    for(int i = 0; i<name.size(); i++)
    {
        c1[i] = name.at(i);
    }
    char c2[] = "3-3";
    char c3[] = "3-1-2";
    char c4[] = "3-2-1";
    NotifyMessage("formacionValido: obteniendo formacion ", "UTILS");
    if((strncasecmp(c1,c2,3))==0)
    {
        name = "3-3";
        NotifyMessage("formacionValido: formacion seteado:" + name, "UTILS");
        return true;
    }

    if((strncasecmp(c1,c3,3))==0)
    {
        name = "3-1";
        NotifyMessage("formacionValido: formacion seteado:" + name, "UTILS");
        return true;
    }

    if((strncasecmp(c1,c4,3))==0)
    {
        name = "3-2-1";
         NotifyMessage("casacaValido: formacion seteado:" + name, "UTILS");
        return true;
    }
    name = "";
     NotifyWarning("formacionValido: valor de formacion invalido", "UTILS");
    return false;
}

Equipo Util_Parser::read_yaml_Equipo(std::vector<YAML::Node> baseNode)
{
    equipos.clear();
    for (auto &document : baseNode)
    {
        equipos.emplace_back(document["equipo"]);
    }
    return equipos.at(0);
}

Debug Util_Parser::read_yaml_Debug(std::vector<YAML::Node> baseNode)
{
    debugs.clear();
    for (auto &document : baseNode)
    {
        debugs.emplace_back(document["debug"]);
    }
    return debugs.at(0);

}


void Util_Parser::mezclar(Parametros &resultado, Parametros parametro)
{
   NotifyMessage("mezclar: obteniendo parametros de memoria", "UTILS");
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

void Util_Parser::llenarParametrosObtenidos( std::vector<YAML::Node> baseNode, Parametros &parametrosObtenidos)
{

//obtener debug
    try
    {
        Debug debugParseado = read_yaml_Debug(baseNode);
        parametrosObtenidos.level = debugParseado.get_level();
        if(levelValido( parametrosObtenidos.level))
        {
            NotifyMessage("llenarParametrosObtenidos: level obtenido", "UTILS");

        }
        else
        {
            NotifyWarning("llenarParametrosObtenidos: level invalido", "UTILS");
            parametrosObtenidos.esValido = 0;
        }
    }
    catch(YAML::Exception ex)
    {
            NotifyError("llenarParametrosObtenidos: no se pudo obtener el nodo Debug", "UTILS");
            parametrosObtenidos.esValido = 0;
    }


    try
    {
        Equipo equipoParseado  = read_yaml_Equipo(baseNode);
        parametrosObtenidos.casaca = equipoParseado.get_casaca();
        if(casacaValido(parametrosObtenidos.casaca))
        {
             NotifyMessage("llenarParametrosObtenidos: casaca obtenido", "UTILS");
        }
        else
        {
            NotifyWarning("llenarParametrosObtenidos: casaca invalido", "UTILS");
            parametrosObtenidos.esValido = 0;
        }
        parametrosObtenidos.formacion = equipoParseado.get_formacion();
        if(formacionValido(parametrosObtenidos.formacion))
        {
            NotifyMessage("llenarParametrosObtenidos: formacion obtenido", "UTILS");
        }
        else
        {
            NotifyWarning("llenarParametrosObtenidos: formacion invalido", "UTILS");
            parametrosObtenidos.esValido = 0;

        }
    }
    catch(YAML::Exception ex)
    {
    NotifyError("llenarParametrosObtenidos: no se pudo obtener el nodo Equipo", "UTILS");
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
            NotifyMessage("read_yaml_Parametros: cargar path indicado por parametro", "UTILS");
            baseNode = YAML::LoadAllFromFile(pathIndicado);

        }
        else
        {
            if(fileExists(pathDefault))
            {
               NotifyMessage("read_yaml_Parametros: cargar path indicado por default", "UTILS");
                baseNode = YAML::LoadAllFromFile(pathDefault);
            }

        }
        llenarParametrosObtenidos(baseNode, parametrosObtenidosIndicado);


        if (parametrosObtenidosIndicado.esValido == 0)
        {
            NotifyWarning("read_yaml_Parametros: parametros obtenidos invalidos", "UTILS");
            //intenta llenar con defaul
            baseNode = YAML::LoadAllFromFile(pathDefault);
            llenarParametrosObtenidos(baseNode, parametrosObtenidosDefault);

            mezclar (parametrosObtenidosIndicado, parametrosObtenidosDefault);
            mezclar(parametrosObtenidosIndicado, superParametros);
        }

        return parametrosObtenidosIndicado;
    }
    catch(YAML::Exception ex)
    {
   NotifyError("read_yaml_Parametros: parametros obtenidos invalidos", "UTILS");
        return superParametros;
    }
}

Parametros Util_Parser::CrearSuperConfig()
{
    //loguar carga de superconfig
    return Parametros("debug","3-3","auxiliar");
}
