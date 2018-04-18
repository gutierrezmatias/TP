#include "Util_Configuracion.h"

#include <yaml-cpp/yaml.h>
#include  <yaml-cpp/exceptions.h>
#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>

Util_Parser parser;
const std::string pathDefaultConfig = "./Configs/config.yaml";


Util_Configuracion::Util_Configuracion(Model* model)
{
   Parametros parametros = parser.CrearSuperConfig();
   std::string pathIndicado = "./Configs/configIndicado.yaml"; //implementar metodo para levantar de consola

    if(!this->inicializar(pathDefaultConfig, pathIndicado))
    {
        printf( "Fallo al Inicializar!\n" );
        //loguear inicialzacion

    }
    else
    {
    parametros = parser.read_yaml_Parametros(pathIndicado,pathDefaultConfig, parametros);
    }


        this->model = model;
        this->model->setCasaca(GenerarCasaca(parametros.casaca));
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

Util_Configuracion::~Util_Configuracion()
{
    this->close();
}


bool Util_Configuracion::inicializar(std::string pathIndicado, std::string pathDefault)
{
 return ((parser.fileExists(pathDefault))||(parser.fileExists(pathIndicado)));
}


int Util_Configuracion::GenerarLevel(std::string &name)
{


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
        return 1;

    }

    if((strncasecmp(c1,c3,4))==0)
    {
        return 2;

    }

    if((strncasecmp(c1,c4,4))==0)
    {
        return 3;

    }

  return 0; //codigo de error

}

int Util_Configuracion::GenerarCasaca(std::string &name)
{

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
        return 0;
    }

    if((strncasecmp(c1,c3,2))==0)
    {
        name = "suplente";
        return 1;
    }

    return false;
}


void Util_Configuracion::close()
{

}
