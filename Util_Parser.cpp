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

//TODO: hacer alguna comprobacion para el size.
//tu upper
    char c1[100];
    for(int i = 0; i<name.size(); i++)
    {
        name.at(i) = toupper(name.at(i));
        c1[i] = name.at(i);
    }

    char c2[] = "DEBUG";
    char c3[] = "INFO";
    char c4[] = "ERROR";

    if((strncasecmp(c1,c2,2))==0)
    {
        name = "debug";
        return true;
    }

    if((strncasecmp(c1,c3,2))==0)
    {
        name = "info";
        return true;
    }

    if((strncasecmp(c1,c4,2))==0)
    {
        name = "error";
        return true;
    }

    name = "";
    return false;

}
//pasar por referencia
inline bool Util_Parser::casacaValido(std::string &name)
{
//TODO: hacer alguna comprobacion para el size.
//tu upper
    char c1[100];
    for(int i = 0; i<name.size(); i++)
    {
        name.at(i) = toupper(name.at(i));
        c1[i] = name.at(i);
    }

    char c2[] = "PRINCIPAL";
    char c3[] = "SUPLENTE";
    if((strncasecmp(c1,c2,2))==0)
    {
        name = "principal";
        return true;
    }

    if((strncasecmp(c1,c3,2))==0)
    {
        name = "suplente";
        return true;
    }
    name = "";
    return false;
}
//pasar por referencia
inline bool Util_Parser::formacionValido(std::string &name)
{
//TODO: hacer alguna comprobacion para el size.
//tu upper
    char c1[100];
    for(int i = 0; i<name.size(); i++)
    {
        c1[i] = name.at(i);
    }
    char c2[] = "3-3";
    char c3[] = "3-1";
    char c4[] = "3-2-1";
    if((strncasecmp(c1,c2,3))==0)
    {
        name = "3-3";
        return true;
    }

    if((strncasecmp(c1,c3,3))==0)
    {
        name = "3-1";
        return true;
    }

    if((strncasecmp(c1,c4,3))==0)
    {
        name = "3-2-1";
        return true;
    }
    name = "";
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


void Util_Parser::mezclar(Parametros &resultado, Parametros superParametros)
{
    if(!levelValido( resultado.level))
    {
        resultado.level = superParametros.level;
    }

    if(!formacionValido( resultado.formacion))
    {
        resultado.formacion = superParametros.formacion;
    }

    if(!casacaValido( resultado.casaca))
    {
        resultado.casaca = superParametros.casaca;
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

            //loguar level obtenido
        }
        else
        {
            //loguar level invalido
            parametrosObtenidos.esValido = 0;
        }
    }
    catch(YAML::Exception ex)
    {
        //loguear que no se pudo obtener el nodo Debug
        parametrosObtenidos.esValido = 0;
    }


    try
    {
        Equipo equipoParseado  = read_yaml_Equipo(baseNode);
        parametrosObtenidos.casaca = equipoParseado.get_casaca();
        if(casacaValido(parametrosObtenidos.casaca))
        {
            //loguar casaca obtenido
        }
        else
        {
            //loguar que no se pudo obtener casaca
            parametrosObtenidos.esValido = 0;
        }
        parametrosObtenidos.formacion = equipoParseado.get_formacion();
        if(formacionValido(parametrosObtenidos.formacion))
        {
            //loguar formacion obtenido
        }
        else
        {
            parametrosObtenidos.esValido = 0;
            //loguear que no se pudo obtener formacion
        }
    }
    catch(YAML::Exception ex)
    {
//     loguear que no se pudo obtener el nodo
        //  probar con ddbug defualt
        parametrosObtenidos.esValido = 0;

    }


}

Parametros Util_Parser::read_yaml_Parametros(std::string pathIndicado, std::string pathDefault, Parametros superParametros)
{
    try
    {
        std::vector<YAML::Node> baseNode;

        Parametros parametrosObtenidos = Parametros("","","");

        if (fileExists(pathIndicado))
        {
            //loguear levantar path indicado
            baseNode = YAML::LoadAllFromFile(pathIndicado);

        }
        else
        {
            if(fileExists(pathDefault))
            {
                //loguear levantar path deafult
                baseNode = YAML::LoadAllFromFile(pathDefault);
            }

        }
        llenarParametrosObtenidos(baseNode, parametrosObtenidos);


        if (parametrosObtenidos.esValido == 0)
        {
            //hacer lo mismo para el nodo defaul
            //intenta llenar con defaul
            baseNode = YAML::LoadAllFromFile(pathDefault);
            llenarParametrosObtenidos(baseNode, parametrosObtenidos);
            mezclar(parametrosObtenidos, superParametros);
        }

        return parametrosObtenidos;
    }
    catch(YAML::Exception ex)
    {
        return superParametros;
    }
}

Parametros Util_Parser::CrearSuperConfig()
{
    //loguar carga de superconfig
    return Parametros("debug","3-3","Principal");
}
