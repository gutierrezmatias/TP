#include "View_Cancha.h"

View_Cancha::View_Cancha()
{
}

View_Cancha::View_Cancha(SDL_Renderer * gRenderer)
{
    if( !texturaCancha.loadFromFile( "Images/canchafubol.jpg",gRenderer) )
    {
        printf( "Failed to load dot texture!\n" );
        // success = false;
    }
}

void View_Cancha::initialize(SDL_Renderer * gRenderer)
{
    if( !texturaCancha.loadFromFile( "Images/canchafubol.jpg",gRenderer) )
    {
        printf( "Failed to load dot texture!\n" );
        // success = false;
    }
}


void View_Cancha::render( SDL_Rect * camara,SDL_Renderer * gRenderer )
{
    //Show the dot relative to the camera
    this->texturaCancha.render( 0, 0,camara,0.0,NULL,SDL_FLIP_NONE,gRenderer);
}


