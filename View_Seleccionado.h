#ifndef VIEW_PELOTA_H_
#define VIEW_PELOTA_H_
#include <SDL2/SDL.h>
#include "../Model/LTexture.h"
#include "../Model/Model_Pelota.h"

class View_Pelota
{
public:

    View_Pelota( Pelota * model,SDL_Renderer * gRenderer);
    View_Pelota();

    void SetModel( Pelota * model);
    void initialize(Pelota * model,SDL_Renderer * gRenderer);

    //esto va a la vista
    void render( int camX, int camY,SDL_Renderer * gRenderer );

private:
    Pelota *model;
    LTexture texturaPelota;
    int frame = 4;
    double direccion=90.0;
    //  int WALKING_ANIMATION_FRAMES = 4;
    SDL_Rect gSpriteClips[ 4 ];
};

#endif
