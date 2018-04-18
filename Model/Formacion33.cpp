#include "Formacion33.h"

Formacion33::Formacion33()
{

}

Formacion33::~Formacion33()
{
    //dtor
}

void Formacion33::setPosicionInicial(Jugador* jugadores)
{
    int posX;
    int posY;
    int posicionesX[] = {1, 4, 3, 4, 9, 8, 9};
    int posicionesY[] = {3, 1, 3, 5, 1, 3, 5};

    for(int i = 0; i < CANTJUGADORES; ++i) {
        posX = (posicionesX[i] * ANCHO_NIVEL) / CANTDIVANCHO;
        posY = (posicionesY[i] * ALTO_NIVEL) / CANTDIVALTO;
        jugadores[i].setPosInitX(posX);
        jugadores[i].setPosInitY(posY);
        jugadores[i].setPosX(posX);
        jugadores[i].setPosY(posY);
    }
}
