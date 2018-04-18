#ifndef CONTROLLER_JUGADOR_H_
#define CONTROLLER_JUGADOR_H_
#include <SDL2/SDL.h>
#include "../Model/LTexture.h"
#include "../View/View_Jugador.h"
#include "../Model/Model_Jugador.h"

class Controller_Jugador
{
public:
    //The dimensions of the dot
    static const int ANCHO_JUGADOR = 45;
    static const int ALTO_JUGADOR = 45;

    //Maximum axis velocity of the dot
    static const int VELOCIDAD_JUGADOR = 3;


    Controller_Jugador(  Jugador *model,  View_Jugador *view) ;

    void SetModel(  Jugador *model);

    void SetView( View_Jugador *view);

    void handleEvent( SDL_Event& e );

private:

    Jugador *jugador;
    View_Jugador *vista;
};

#endif
