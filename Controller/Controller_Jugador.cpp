#include "Controller_Jugador.h"
#include "Model_Pelota.h"

Controller_Jugador::Controller_Jugador( Jugador *model,  View_Jugador *view)
{
    this->SetModel(model);
    this->SetView(view);
}
void Controller_Jugador::SetModel( Jugador *model)
{
    this->jugador = model;
}
void Controller_Jugador::SetView( View_Jugador *view)
{
    this->vista = view;
}

//Takes key presses and adjusts the dot's velocity
void Controller_Jugador::handleEvent( SDL_Event& e )
{
     Pelota* pelota=NULL;
    //Jugador jugador = (*this->jugador);
    //If a key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
        case SDLK_s:
             (*this->jugador).recuperaPelota(pelota);
            break;
        case SDLK_d:
             (*this->jugador).patearPelota(pelota);
            break;
        case SDLK_UP:
            (*this->jugador).disminuirVelocidadY();
            break;
        case SDLK_DOWN:
            (*this->jugador).aumentarVelocidadY();
            break;
        case SDLK_LEFT:
            (*this->jugador).disminuirVelocidadX();
            break;
        case SDLK_RIGHT:
            (*this->jugador).aumentarVelocidadX();
            break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
        case SDLK_UP:
            (*this->jugador).aumentarVelocidadY();
            break;
        case SDLK_DOWN:
            (*this->jugador).disminuirVelocidadY();
            break;
        case SDLK_LEFT:
            (*this->jugador).aumentarVelocidadX();
            break;
        case SDLK_RIGHT:
            (*this->jugador).disminuirVelocidadX();
            break;
        }
    }

}


