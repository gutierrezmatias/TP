#include "View_Jugador.h"

View_Jugador::View_Jugador()
{

}

View_Jugador::View_Jugador( Jugador *model,SDL_Renderer * gRenderer)
{
    this->model = model;
    if( !texturaJugador.loadFromFile( "Images/spritejugador.png",gRenderer) )
    {
        printf( "Failed to load dot texture!\n" );
        // success = false;
    }
    else
    {
        int offset = 0;
        if (!model->casacaPrincipal())
        {
            offset = 256;
        }
        //Set sprite clips
        gSpriteClips[ 0 ].x =   offset+0; //si sumo 256 en X tengo la otra camiseta
        gSpriteClips[ 0 ].y =   128;
        gSpriteClips[ 0 ].w =  62;
        gSpriteClips[ 0 ].h = 62;

        gSpriteClips[ 1 ].x =  offset+64;
        gSpriteClips[ 1 ].y =  128;
        gSpriteClips[ 1 ].w =  62;
        gSpriteClips[ 1 ].h = 62;

        gSpriteClips[ 2 ].x = offset+128;
        gSpriteClips[ 2 ].y =   128;
        gSpriteClips[ 2 ].w =  62;
        gSpriteClips[ 2 ].h = 62;

        gSpriteClips[ 3 ].x = offset+192;
        gSpriteClips[ 3 ].y =   128;
        gSpriteClips[ 3 ].w =  62;
        gSpriteClips[ 3 ].h = 62;

    }
}

void View_Jugador::initialize(Jugador *model,SDL_Renderer * gRenderer)
{
    this->model = model;
    if( !texturaJugador.loadFromFile( "Images/spritejugador.png",gRenderer) )
    {
        printf( "Failed to load dot texture!\n" );
        // success = false;
    }else{
    if( !texturaSeleccionado.loadFromFile( "Images/jugadorseleccionado.png",gRenderer) )
    {
        printf( "Failed to load dot texture!\n" );
        // success = false;
    }
    else
    {   texturaSeleccionado.setAlpha(200);
        texturaSeleccionado.setColor(150,100,150);
        int offset = 0;
        if (!model->casacaPrincipal())
        {
            offset = 256;
        }
        //Set sprite clips
        gSpriteClips[ 0 ].x =   offset+0; //si sumo 256 en X tengo la otra camiseta
        gSpriteClips[ 0 ].y =   128;
        gSpriteClips[ 0 ].w =  62;
        gSpriteClips[ 0 ].h = 62;

        gSpriteClips[ 1 ].x =  offset+64;
        gSpriteClips[ 1 ].y =  128;
        gSpriteClips[ 1 ].w =  62;
        gSpriteClips[ 1 ].h = 62;

        gSpriteClips[ 2 ].x = offset+128;
        gSpriteClips[ 2 ].y =   128;
        gSpriteClips[ 2 ].w =  62;
        gSpriteClips[ 2 ].h = 62;

        gSpriteClips[ 3 ].x = offset+192;
        gSpriteClips[ 3 ].y =   128;
        gSpriteClips[ 3 ].w =  62;
        gSpriteClips[ 3 ].h = 62;

    }}
}

void View_Jugador::SetModel( Jugador * model)
{
    this->model = model;
}
void View_Jugador::render( int camX, int camY,SDL_Renderer * gRenderer )
{
    SDL_Rect* currentClip = &gSpriteClips[frame / 4 ];

    if ((*this->model).getVelX()>0)
    {
        ++frame;
        direccion = 90;
        if ((*this->model).getVelY()>0)
        {
            direccion += 45;
        }
        if ((*this->model).getVelY()<0)
        {
            direccion -= 45;
        }
        if (frame / 4 >= 4)
        {
            frame = 0;
        }
    }

    if ((*this->model).getVelX()<0)
    {
        ++frame;
        direccion = 270;
        if ((*this->model).getVelY()<0)
        {
            direccion += 45;
        }
        if ((*this->model).getVelY()>0)
        {
            direccion -= 45;
        }
        if (frame / 4 >= 4)
        {
            frame = 0;
        }
    }


    if ((((*this->model).getVelX()==0) )&& (((*this->model).getVelY()!=0)))
    {
        ++frame;
        direccion = 90;
        if ((*this->model).getVelY()<0)
        {
            direccion -= 90;
        }
        if ((*this->model).getVelY()>0)
        {
            direccion += 90;
        }
        if (frame / 4 >= 4)
        {
            frame = 0;
        }
    }

    //Show the dot relative to the camera
    if ((this->model)->estaActivo()){
        this->texturaSeleccionado.render( (*this->model).getPosX() - camX, (*this->model).getPosY() - camY,NULL,direccion,NULL,SDL_FLIP_NONE,gRenderer);
    }
    this->texturaJugador.render( (*this->model).getPosX() - camX, (*this->model).getPosY() - camY,currentClip,direccion,NULL,SDL_FLIP_NONE,gRenderer);

}


