#include "Desacelerar.h"
#include "Model_Jugador.h"
#include <stdio.h>

Desacelerar::Desacelerar(Model* model)
{
    this->model = model;
}

Desacelerar::~Desacelerar()
{
    //dtor
}

void Desacelerar::execute() {
    printf("desaceleAR");
    Jugador* jugador = this->model->getJugadorActivo();
    jugador->desacelerar();
}
