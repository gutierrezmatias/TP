#ifndef VIEW_CANCHA_H_
#define VIEW_CANCHA_H_
#include <SDL2/SDL.h>
#include "../Model/LTexture.h"
#include "../Model/Model_Pelota.h"
#include "../Utils/Util_LoggerSubject.h"
class View_Cancha : public Util_LoggerSubject
{
public:
    View_Cancha();

    void initialize(SDL_Renderer * gRenderer);

    void render( SDL_Rect * camara,SDL_Renderer * gRenderer );

private:
    LTexture texturaCancha;
};

#endif
