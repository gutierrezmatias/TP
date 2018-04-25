#ifndef VIEW_JUGADOR_H_
#define VIEW_JUGADOR_H_
#include <SDL2/SDL.h>
#include "../Model/LTexture.h"
#include "../Model/Model_Jugador.h"
#include "../Utils/Util_LoggerSubject.h"
class View_Jugador : public Util_LoggerSubject
{
public:

    View_Jugador( Jugador *model);
    View_Jugador();

    void initialize(Jugador *model,SDL_Renderer * gRenderer);
    void SetModel( Jugador *model);
    void render( int camX, int camY,SDL_Renderer * gRenderer );

private:
    Jugador *model;
    LTexture texturaJugador;
    LTexture texturaSeleccionado;
    int frame = 4;
    double direccion;
    SDL_Rect gSpriteClips[ 4 ];
};

#endif
