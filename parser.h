#include"parser.c"


int parsercrear (tda_parser * tda, char separador, char escape, char comentario, char * archivo);

int parserDestruir (tda_parser * tda);

int parserSiguiente(tda_parser * tda);

int parsercantcampos(tda_parser * tda);

int parserCampo (tda_parser * tda, int n, char* valor);

