#include <stdio.h>
#include <string.h>
#include "TDA_TRD.c"
#include "ListaSimple.h"


/*Definir un TDA TRADUCTOR. Este tipo de datos abstracto contiene traducciones de palabras en

varios idiomas. Su función es la de almacenar distintas palabras, en distintos idiomas y poder

responder a consultas relacionadas con esto.

La interfase es la siguiente:

Int TrdCrear( TDA_TRD * tda )

FUNCIÓN Crea el TDA TRD

PRE -

POST Traductor creado

PARÁMETROS Tda Puntero al Traductor
*/


int TrdCrear( TDA_TRD * tda );






/*

Int TrdAgregarTermino(TDA_TRD * tda , int idioma,id_palabra, char *palabra)

FUNCIÓN Agrega el termino en el idioma pasado por parámetro

PRE TRD creado

POST Se agrego el termino pasado al idioma especificado

PARÁMETROS Trd Puntero a trd

PARÁMETROS Idioma Puntero a set

PARÁMETROS palabra Id del termino y el termino
*/


int TrdAgregarTermino(TDA_TRD * tda , int idioma,int id_palabra, char *palabra);



/*
int TrdTraducir (TDA_TRD * tda, int idioma origen, int idioma destino, char *origen, char *

palabra destino)

FUNCIÓN Devuelve 1 si se encuentra la palabra a traducir

PRE Trd creado

POST Si la palabra se encuentra la devuelve en palabra destino en el idioma requerido

PARÁMETROS tda El parser
*/
int TrdTraducir (TDA_TRD * tda, int idiomaorigen, int idiomadestino, char *origen, char * palabradestino);

/*
int TrdTraducir idioma(TDA_TRD * tda, int idioma origen, int idioma destino,tda_lista *

lista_destino)

FUNCIÓN Devuelve 1 si se tradujo el idioma

PRE Trd creado

POST DEVUELVE una lista con cada palabra en el idioma origen y su traducción al

idioma destino La lista destino tendrá idioma origen, palabra , idioma destino,

palabra

PARÁMETROS tda El parser
*/

int TrdTraduciridioma(TDA_TRD * tda, int idiomaorigen, int idiomadestino,TListaSimple * lista_destino);


/*
Int TrdDestruir (TDA_TRD * tda )

FUNCIÓN Destruye el Traductor

PRE Traductor vacio

POST Devuelve 1 si pudo destruir el traductor, 0 en otro caso.

PARÁMETROS Tda Puntero Traductor

*/

int TrdDestruir (TDA_TRD * tda );


/******************************************************************************************************

3. Implementar un programa que, tenga que leer un archivo de palabras con el siguiente formato

Id_palabra;palabra_idioma1; palabra_idioma2; palabra_idioma3;…; palabra_idioma_n;

Ejemplo:

4534;perro;dog; chien;hund

4522;auto;car;voiture;auto

La primer línea de este archivo define los idiomas con el mismo formato siendo 0 el id

0;español;ingles;francés;alemán

Se deberá parsear con el TDA PARSER este archivo y cargar el TDA TRADUCTOR

Para este tp se deberá realizar un menú interactivo el cual pregunte para iniciar el archivo donde

residen las palabras (con el formato antes mencionado), cual es el carácter separador, carácter de

escape y carácter de comentario y la cantidad de idiomas incluidos en ese archivo.

Luego habrá un menú donde pueda solicite un idioma origen y una palabra y un idioma destino y

devuelva en pantalla la traducción.

Otra opción es optar por traducir un lenguaje entero de origen a uno de destino, el resultado se

guardara en un archivo que deberá ser ingresado.

*****************************************************************************************************/
