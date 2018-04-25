#include "PatearPelota.h"
#include "Model_Jugador.h"

PatearPelota::PatearPelota(Model *model)
{
    this->model=model;
}

PatearPelota::~PatearPelota()
{
    //dtor
}

void PatearPelota ::execute()
{
        Pelota*  pelota = this->model->getPelota();

    Jugador* jugador = this->model->getJugadorActivo();
     jugador->patearPelota(pelota);


    return;
}
