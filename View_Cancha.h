#ifndef VIEW_CANCHA_H_
#define VIEW_CANCHA_H_
#include <SDL2/SDL.h>
#include "../Model/LTexture.h"
#include "../Model/Model_Pelota.h"

class View_Cancha
{
public:
    View_Cancha();
    View_Cancha(SDL_Renderer * gRenderer);

    void initialize(SDL_Renderer * gRenderer);
    //esto va a la vista
    void render( SDL_Rect * camara,SDL_Renderer * gRenderer );

private:
    LTexture texturaCancha;
};

#endif
