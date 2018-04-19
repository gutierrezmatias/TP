#include "StopJugador.h"
#include "Model_Jugador.h"

StopJugador::StopJugador(Model* model)
{
    this->model = model;
}

StopJugador::~StopJugador()
{

}

void StopJugador::execute() {
    Jugador* jugador = this->model->getJugadorActivo();
    jugador->detenerVelocidad();
    return;
}
