#include "DesminuirVelocidadY.h"
#include "Model_Jugador.h"

DesminuirVelocidadY::DesminuirVelocidadY()
{
    //ctor
}

DesminuirVelocidadY::~DesminuirVelocidadY()
{
    //dtor
}

void DesminuirVelocidadY::execute() {
    Jugador* jugador = this->model.getActivePlayer();
    jugador->disminuirVelocidadY();
    jugador->move();
    return;
}

void DesminuirVelocidadY::setModel(Model& model) {
    this->model = model;
}
