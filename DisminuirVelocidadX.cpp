#include "DisminuirVelocidadX.h"
#include "Model_Jugador.h"

DisminuirVelocidadX::DisminuirVelocidadX(Model* model)
{
    this->model = model;
}

DisminuirVelocidadX::~DisminuirVelocidadX()
{
    //dtor
}

void DisminuirVelocidadX::execute()
{
    Jugador* jugador = this->model->getJugadorActivo();
    jugador->disminuirVelocidadX();
    return;
}
