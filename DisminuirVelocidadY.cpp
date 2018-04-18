#include "DisminuirVelocidadY.h"
#include "Model_Jugador.h"

DisminuirVelocidadY::DisminuirVelocidadY(Model* model)
{
    this->model = model;
}

DisminuirVelocidadY::~DisminuirVelocidadY()
{
    //dtor
}

void DisminuirVelocidadY::execute()
{
    Jugador* jugador = this->model->getJugadorActivo();
    jugador->disminuirVelocidadY();
    return;
}
