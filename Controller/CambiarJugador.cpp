#include "CambiarJugador.h"

CambiarJugador::CambiarJugador(Model* model)
{
    this->model = model;
}

CambiarJugador::~CambiarJugador()
{
    //dtor
}

void CambiarJugador::execute()

{
    //this->model->detenerJugadores();

    this->model->cambiarJugadorActivo();
}
