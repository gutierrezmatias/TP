#include "Formacion321.h"

Formacion321::Formacion321()
{
    //ctor
}

Formacion321::~Formacion321()
{
    //dtor
}

void Formacion321::setPosicionInicial(Jugador* jugadores)
{
    int posX;
    int posY;
    int posicionesX[] = {1, 4, 3, 4, 6, 6, 9};
    int posicionesY[] = {3, 1, 3, 5, 2, 4, 3};

    for(int i = 0; i < CANTJUGADORES; ++i) {
        posX = (posicionesX[i] * ANCHO_NIVEL) / CANTDIVANCHO;
        posY = (posicionesY[i] * ALTO_NIVEL) / CANTDIVALTO;
        jugadores[i].setPosInitX(posX);
        jugadores[i].setPosInitY(posY);
        jugadores[i].setPosX(posX);
        jugadores[i].setPosY(posY);
    }
}
