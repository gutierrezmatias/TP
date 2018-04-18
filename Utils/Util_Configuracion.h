#ifndef UTIL_CONFIGURACION_H_
#define UTIL_CONFIGURACION_H_

#include "Model/Model.h"
#include "Model_Jugador.h"
#include "Formacion312.h"
#include "Formacion33.h"
#include "Formacion321.h"
#include "Util_Parser.h"

#include <iostream>
#include <string>
#include <list>



using namespace std;


class Util_Configuracion
{
	public:
         Util_Configuracion(Model* model);
         virtual ~Util_Configuracion();
         bool inicializar(std::string pathIndicado, std::string pathDefault);
         int GenerarLevel(std::string &name); //1=Debug, 2=Info, 3=Error
         int GenerarCasaca(std::string &name); //0 principal o 1 para la suplente
         void close();

    private:
        Model* model;
        Formacion312 formacion312;
        Formacion33 formacion33;
        Formacion321 formacion321;


};

#endif
