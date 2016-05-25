#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TDA_TRD.h"
#include "ListaSimple.c"
#include "parser.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define ESC 27
#define cero 48
#define uno 49
#define dos 50
#define tres 51
#define cuatro 52
#define cinco 53
#define seis 54
#define siete 55

int existearchivo(const char *filename) {
    struct stat st;
    int result = stat(filename, &st);
    return result == 0;
}

char archivo1[20],archivo2[20]; // archivos usados
char palabraorigen[20],palabradestino[20];//palabras por teclado para el traductor
char separador,escape,comentario; //caracteres especiales del parser
int cantidadidiomas,idiomaorigen,idiomadestino;
tda_parser parser;
TDA_TRD traductor;
TListaSimple lista;

int main(void) {

   char key;
    do {
	system ("clear");
	printf("\n\n\t\t\t\t Traductor \n\n") ;
	printf("-------------------------------------------------------------------------\n\n") ;
	printf("\t Opcion: 0 | Cargar Traductor \n\n") ;
	printf("\t Opcion: 1 | Traducir Palabra \n\n") ;
	printf("\t Opcion: 2 | Traducir Lenguaje \n\n") ;
	printf("\t Opcion: 3 | Mostrar Estado del Traductor \n\n\n") ;
	printf("\t\t\t Presione Esc para salir \n\n\n") ;	
	printf("-------------------------------------------------------------------------\n\n") ;
	printf("Ingresar Opcion: ") ;
      scanf(" %c",&key);;
         switch (key) {
            case cero: {	
			system ("clear");
			printf("\n\n\t\t\t     Traductor \n\n") ;
			printf("-------------------------------------------------------------------------\n\n") ;
			printf(" Cargar Traductor \n\n") ;
			printf("\t Ingresar Archivo de de Palabras:");
			
			scanf(" %s", archivo1);
				if (existearchivo(archivo1)){

					getchar();	
					printf("\t Ingresar Caracter Separador:");
					scanf(" %c",&separador);
					printf("\t Ingresar Caracter de Escape:");
					scanf(" %c",&escape);
					printf("\t Ingresar Caracter de Comentario:");
					scanf(" %c",&comentario);	
					printf("\t Ingrese Numero de Idiomas:");//lo podria sacar...
					scanf(" %i",&(cantidadidiomas));
					parsercrear (&parser,  separador,  escape, comentario,archivo1);
					parserSiguiente(&parser);
					traductor.cantidad = parsercantcampos(&parser);
					TrdCrear(&traductor);
					printf("\n\ttraductor creado\n");
					int ididioma;
					char valor[20];
					for (ididioma=1;ididioma<(parsercantcampos(&parser));ididioma++){
						parserCampo(&parser,ididioma,valor);
						cargaridiomas(&traductor,valor,ididioma);
					}
					printf("\tidiomas cargados\n");
					while (parserSiguiente(&parser)){
						char id_palabra[20];
						parserCampo(&parser,0,id_palabra);
						for (int i=1;i<(parsercantcampos(&parser));i++){
							parserCampo(&parser,i,valor);
							TrdAgregarTermino(&traductor , i,atoi(id_palabra), valor);
						}

					}
				}else{printf("\nEl Archivo no existe!!!");getchar();getchar();}
			}; break;
            case uno: {
			system ("clear");
			printf("\n\n\t\t\t     Traductor \n\n") ;
			printf("-------------------------------------------------------------------------\n\n") ;
			if (existearchivo(archivo1)){			
				printf(" Traducir Palabra \n\n") ;
				printf("\t Idioma de Origen:");
				scanf(" %i",&idiomaorigen);
				getchar();
				printf("\t Palabra:");
				scanf(" %s", palabraorigen);
				getchar();
				printf("\t Idioma de Destino:");
				scanf(" %i",&idiomadestino);
				getchar();
				TrdTraducir (&traductor,idiomaorigen,idiomadestino,palabraorigen,palabradestino);
				printf("\t Traduccion:%s",palabradestino);
				getchar();
			}else{printf("\nEl Archivo no existe!!!");getchar();getchar();}
			}; break;
            case dos: {	
			system ("clear");
			printf("\n\n\t\t\t     Traductor \n\n") ;
			printf("-------------------------------------------------------------------------\n\n") ;
			if (existearchivo(archivo1)){					
				printf(" Traducir Lenguaje \n\n") ;	
				printf("\t Idioma de Origen:");
				scanf(" %i",&idiomaorigen);
				getchar();
				printf("\t Idioma de Destino:");
				scanf(" %i",&idiomadestino);
				getchar();
				TrdTraduciridioma(&traductor,idiomaorigen,idiomadestino,&lista);
				printf("\t Archivo de lenguaje traducido creado\n\n");
				////muestro como se cargo la lista			
				telemento elemento;
				ls_MoverCorriente(&lista, LS_PRIMERO);
				do{
					ls_ElemCorriente(lista,&elemento);
					printf("%i %s %i %s \n",elemento.idiomaorigen,elemento.palabraorigen,elemento.idiomadestino,elemento.palabradestino);
				}while (ls_MoverCorriente(&lista, LS_SIGUIENTE));
				getchar();
			}else{printf("\nEl Archivo no existe!!!");getchar();getchar();}
			}; break;
            
	    case tres: {	
			system ("clear");
			printf("\n\n\t\t\t     Traductor \n\n") ;
			printf("-------------------------------------------------------------------------\n\n") ;
			if (existearchivo(archivo1)){					
				printf(" Estado del Traductor:\n\n") ;	
				lIdioma idiomas;
				lTerminos termino;
				ls_MoverCorriente(traductor.idiomas, LS_PRIMERO);
				do{
					ls_ElemCorriente(*(traductor.idiomas),&idiomas);			
					printf("%i : ",idiomas.ididioma);
					printf(" %s \t\n",idiomas.idioma);
					ls_MoverCorriente(idiomas.terminos, LS_PRIMERO);
						do {
							ls_ElemCorriente(*(idiomas.terminos),&termino);	
							printf("\t\t\t %i : ",termino.ID);
							printf(" palabra: %s\n\n",termino.palabra);
						} while (ls_MoverCorriente(idiomas.terminos, LS_SIGUIENTE));	
				}while(ls_MoverCorriente(traductor.idiomas, LS_SIGUIENTE));
			getchar();getchar();
			}else{printf("\nEl Archivo no existe!!!");getchar();getchar();}
			}; break;
            	

            default:  ; break;
     
      }
      if(key == ESC) {
	system("clear");
	printf("\n\n\t\t\t      Hasta Luego! \n\n") ;
        putchar('\n');
      }
      else {
         printf("Key: %c", key);
         putchar('\n');
      }
   }while (key != ESC); 
 
	TrdDestruir(&traductor);
	parserDestruir(&parser);
	ls_Vaciar(&lista);
   return 0;
}



