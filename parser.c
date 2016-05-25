#include <string.h>
#include <stdbool.h>
typedef struct parser
	{	char separador;
		char escape;
		char comentario;
		char** linea;
		int campos;
		FILE * archivo;
	}tda_parser;

int parsercrear (tda_parser * tda, char separador, char escape, char comentario, char * archivo){
	
FILE *texto;
tda->separador = separador;
tda->escape=escape;
tda->comentario=comentario;
tda->linea=NULL;
tda->archivo = fopen(archivo,"r");
tda->campos=0;
if(!tda->archivo){
	return 0;
}
return 1;
}

int parserDestruir (tda_parser * tda){
	tda->separador = ' ';
	tda->escape=' ';
	tda->comentario=' ';
	tda->campos=0;
	free(tda->linea);
	tda->archivo=NULL;
};

int parserSiguiente(tda_parser * tda){
tda->campos=0;
char * palabra = NULL;
char caracter;
int numcaracteres =0;
int numpalabras =0;
int commenton=0;
int finlinea = 0;
int hayescape=0;
while (EOF!=(caracter=fgetc(tda->archivo)) && finlinea==0 ){
	if (caracter == tda->comentario){
		if (commenton == 1) {
			commenton=0;
		}else{
			commenton=1;	
		}
	}
	if(caracter==tda->escape && hayescape==0 && commenton==0){
		hayescape=1;	
	}	
	if (caracter==tda->separador && commenton==0 && hayescape==0 || caracter=='\n' && commenton==0 && hayescape == 0){
			numcaracteres++;
			palabra=realloc(palabra,numcaracteres);
			palabra[numcaracteres-1] = '\0';			
			numpalabras++;
			tda->linea=realloc(tda->linea,sizeof(char*)*numpalabras);
			tda->linea[numpalabras-1]=palabra;
			numcaracteres=0;
			palabra=malloc(0);
			if (caracter=='\n'){
				finlinea=1;
			}
		}
		if(caracter!=tda->separador && caracter!='\n' && caracter !='\r' && commenton==0 && caracter!=tda->comentario || caracter!='\n' && caracter !='\r' && caracter !='\0' && commenton==0 && hayescape==1){
			numcaracteres++;
			palabra=realloc(palabra,numcaracteres);
			palabra[numcaracteres-1] = caracter;
			if(hayescape=1){
				hayescape=0;	
			}
		}	

}
tda->campos=numpalabras;
if (caracter==EOF && finlinea == 0){
			return 0;
		};
return 1;
}

int parsercantcampos(tda_parser * tda){
return tda->campos;
};

int parserCampo (tda_parser * tda, int n, char* valor){	
if(tda->campos>=n){
		strcpy(valor, tda->linea[n]);		
	return 1;
	}
return 0;
};



