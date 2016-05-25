#include <stdio.h>
#include <string.h>
#include "ListaSimple.h"

typedef struct lTerminos{
	int ID;//Identificador de termino en todos los idiomas
	char palabra[20];//palabra en el idioma
}lTerminos;

typedef struct lIdioma{
	int ididioma;
	char idioma[20];//nombre del idioma
	TListaSimple * terminos;//Lista de terminos en el idioma
}lIdioma;

typedef struct TDA_TRD{ 
	int cantidad;//cantidad de idiomas
	TListaSimple * idiomas;//puuntero a lista de idiomas
}TDA_TRD;

typedef struct telemento{////elemento con el que cargo la lista de resultado del traductor
int idiomaorigen;
char palabraorigen[20];
int idiomadestino;
char palabradestino[20];
}telemento;



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


int TrdCrear( TDA_TRD * tda ){
tda->cantidad=0;
tda->idiomas=(TListaSimple*)malloc(sizeof(TListaSimple));
ls_Crear(tda->idiomas,sizeof(lIdioma));
};



/*

Int TrdAgregarTermino(TDA_TRD * tda , int idioma,id_palabra, char *palabra)

FUNCIÓN Agrega el termino en el idioma pasado por parámetro

PRE TRD creado

POST Se agrego el termino pasado al idioma especificado

PARÁMETROS Trd Puntero a trd

PARÁMETROS Idioma Puntero a set

PARÁMETROS palabra Id del termino y el termino
*/


int TrdAgregarTermino(TDA_TRD * tda , int idioma,int id_palabra, char *palabra){
lIdioma listaidioma;	
lTerminos termino ;
ls_MoverCorriente(tda->idiomas, LS_PRIMERO);
	do{
	ls_ElemCorriente(*(tda->idiomas),&listaidioma);
	}while ((listaidioma.ididioma != idioma) && (ls_MoverCorriente(tda->idiomas, LS_SIGUIENTE)));
		if (listaidioma.ididioma == idioma){	
			termino.ID = id_palabra;
			strcpy(termino.palabra,palabra);	
			ls_Insertar(listaidioma.terminos, LS_SIGUIENTE, &termino);			
		}

};



/*
int TrdTraducir (TDA_TRD * tda, int idioma origen, int idioma destino, char *origen, char *

palabra destino)

FUNCIÓN Devuelve 1 si se encuentra la palabra a traducir

PRE Trd creado

POST Si la palabra se encuentra la devuelve en palabra destino en el idioma requerido

PARÁMETROS tda El parser
*/
int TrdTraducir (TDA_TRD * tda, int idiomaorigen, int idiomadestino, char *origen, char * palabradestino){

lIdioma listaidioma;	
lTerminos termino;
int id_palabra;

ls_MoverCorriente(tda->idiomas, LS_PRIMERO);
	do{
		ls_ElemCorriente(*(tda->idiomas),&listaidioma);
	}while ((listaidioma.ididioma != idiomaorigen) && (ls_MoverCorriente(tda->idiomas, LS_SIGUIENTE)));
		if (listaidioma.ididioma == idiomaorigen) {
			ls_MoverCorriente(listaidioma.terminos, LS_PRIMERO);
				do {
					ls_ElemCorriente(*(listaidioma.terminos),&termino);				
				} while ((strcmp(termino.palabra,origen) != 0) && ls_MoverCorriente(listaidioma.terminos, LS_SIGUIENTE));			
					if(strcmp(termino.palabra,origen) == 0){
						id_palabra = termino.ID;  
					}else{return 0;}
		}else{return 0;}

ls_MoverCorriente(tda->idiomas, LS_PRIMERO);		
	do{
		ls_ElemCorriente(*(tda->idiomas),&listaidioma);
	}while ((listaidioma.ididioma != idiomadestino) && (ls_MoverCorriente(tda->idiomas, LS_SIGUIENTE)));
		if (listaidioma.ididioma == idiomadestino) {
			ls_MoverCorriente(listaidioma.terminos, LS_PRIMERO);
				do {
					ls_ElemCorriente(*(listaidioma.terminos),&termino);	
				} while ((termino.ID != id_palabra) && ls_MoverCorriente(listaidioma.terminos, LS_SIGUIENTE));	
					if((termino.ID == id_palabra)){
						strcpy(palabradestino,termino.palabra);
					}else{ return 0;}
		}else{return 0;}
};

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

int TrdTraduciridioma(TDA_TRD * tda, int idiomaorigen, int idiomadestino,TListaSimple * lista_destino){

lIdioma listaidioma;	
lTerminos termino;
int id_palabra;
telemento elemento;
char palabradestino[20];
ls_Crear(lista_destino,sizeof(elemento));

ls_MoverCorriente(tda->idiomas, LS_PRIMERO);
	do{
		ls_ElemCorriente(*(tda->idiomas),&listaidioma);
	}while ((listaidioma.ididioma != idiomaorigen) && (ls_MoverCorriente(tda->idiomas, LS_SIGUIENTE)));
		if (listaidioma.ididioma == idiomaorigen) {
			ls_MoverCorriente(listaidioma.terminos, LS_PRIMERO);
				do {
					ls_ElemCorriente(*(listaidioma.terminos),&termino);
					TrdTraducir (tda, idiomaorigen, idiomadestino, termino.palabra, palabradestino)	;
					elemento.idiomaorigen=idiomaorigen;
					strcpy(elemento.palabraorigen,termino.palabra);
					elemento.idiomadestino=idiomadestino;
					strcpy(elemento.palabradestino,palabradestino);
					ls_Insertar(lista_destino, LS_SIGUIENTE, &elemento);	
				} while (ls_MoverCorriente(listaidioma.terminos, LS_SIGUIENTE));			
		}
return 1;
};




/*
Int TrdDestruir (TDA_TRD * tda )

FUNCIÓN Destruye el Traductor

PRE Traductor vacio

POST Devuelve 1 si pudo destruir el traductor, 0 en otro caso.

PARÁMETROS Tda Puntero Traductor

*/

int TrdDestruir(TDA_TRD * tda ){

	lIdioma idiomas;
	ls_MoverCorriente(tda->idiomas, LS_PRIMERO);
		do{
			ls_ElemCorriente(*(tda->idiomas),&idiomas);	
			ls_Vaciar(idiomas.terminos);
			free(idiomas.terminos);			
		}while(ls_MoverCorriente(tda->idiomas, LS_SIGUIENTE));
	ls_Vaciar(tda->idiomas);
	free(tda->idiomas);
};


/* inicializa las listas de idioma desde el archivo de texto */
void cargaridiomas(TDA_TRD * tda,char* valor, int id){
	
	lIdioma idioma;	
	strcpy(idioma.idioma,valor);
	idioma.ididioma=id;	
	idioma.terminos=(TListaSimple*)malloc(sizeof(TListaSimple));
	ls_Crear(idioma.terminos,sizeof(lTerminos));		
	ls_Insertar(tda->idiomas, LS_SIGUIENTE, &idioma);
	tda->cantidad++;		
};


