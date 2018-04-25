#include "View_Cancha.h"

View_Cancha::View_Cancha() {}


void View_Cancha::initialize(SDL_Renderer * gRenderer)
{
    if( !texturaCancha.loadFromFile( "Images/canchafubol.jpg",gRenderer) )
    {
        NotifyError("No se pudo cargar la Imagen de la cancha, se usara una imagen por defecto", "View_Jugador");
        texturaCancha.loadFromFile("Images/pelota.png",gRenderer);
    }
}


void View_Cancha::render( SDL_Rect * camara,SDL_Renderer * gRenderer )
{
    this->texturaCancha.render( 0, 0,camara,0.0,NULL,SDL_FLIP_NONE,gRenderer);
}


