#include "RecuperaPelota.h"
#include "Model_Jugador.h"


RecuperaPelota::RecuperaPelota(Model* model)
{
    this->model=model;
}

RecuperaPelota::~RecuperaPelota()
{
    //dtor
}

void RecuperaPelota ::execute()//La mantiene en su pie
{
    Pelota*  pelota = this->model->getPelota();
    Jugador* jugador = this->model->getJugadorActivo();
    jugador->recuperaPelota(pelota);


    return;
}
