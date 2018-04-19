#include "DesminuirVelocidadY.h"
#include "Model_Jugador.h"

DesminuirVelocidadY::DesminuirVelocidadY(Model* model)
{
    this->model = model;
}

DesminuirVelocidadY::~DesminuirVelocidadY()
{
    //dtor
}

void DesminuirVelocidadY::execute() {
    Jugador* jugador = this->model->getJugadorActivo();
    jugador->disminuirVelocidadY();
    jugador->move();
    return;
}


