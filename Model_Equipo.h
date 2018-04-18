#ifndef MODEL_EQUIPO_H_
#define MODEL_EQUIPO_H_
#include <SDL2/SDL.h>
#include "LTexture.h"
#include <iostream>
#include <list>
#include "Model_Jugador.h"
class Equipo
{
public:

    //Initializes the variables
    Equipo();

    int agregarJugador(Jugador jugador);

private:

    std::list<Jugador> jugadores;
};

#endif
