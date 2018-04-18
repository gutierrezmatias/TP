#include "AumentarVelocidadY.h"
#include "Model_Jugador.h"

AumentarVelocidadY::AumentarVelocidadY(Model* model)
{
    this->model = model;
}

AumentarVelocidadY::~AumentarVelocidadY()
{
    //dtor
}

void AumentarVelocidadY::execute()
{
    Jugador* jugador = this->model->getJugadorActivo();
    jugador->aumentarVelocidadY();
    return;
}
