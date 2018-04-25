#include "View.h"
#include "Model_Jugador.h"
#include <SDL2/SDL.h>

#define MARGEN 200
#define ANCHO_VENTANA 800
#define ALTO_VENTANA 600
#define CAMARAPOSICIONINICIALX (((ANCHO_NIVEL)/2)-((ANCHO_VENTANA)/2))
#define CAMARAPOSICIONINICIALY (((ALTO_NIVEL)/2)-((ALTO_VENTANA)/2))

View::View(Model* model)
{
    if(!this->inicializar())
    {
        printf( "Fallo al Inicializar!\n" );
    }
    else
    {
        this->model = model;
        this->camaraStatic = { CAMARAPOSICIONINICIALX,CAMARAPOSICIONINICIALY, ANCHO_VENTANA, ALTO_VENTANA };
        this->camara = &(this->camaraStatic);
        this->model->setCamara(this->camara);
        this->viewModel = new ViewModel(this->model, this->gRenderer, this->camara);
    }

}

View::~View()
{
    delete this->viewModel;
    this->close();
}

void View::ajustarCamara()
{
    try
    {
        NotifyMessage("Inicia: ajustarCamara", "View.cpp");
        Jugador* jugadorActual = this->model->getJugadorActivo();
        //Esto hacerlo con Patron Observer.
        // va a servir mas con los corners, saques de arco, y despues de los goles.
        /* if(this->jugadorAnterior != jugadorActual)
         {
             //Posiblemente esto solo se haga cada vez que se cambia de jugador
             this->camara->x = ( jugadorActual->getPosX() + Jugador::ANCHO_JUGADOR / 2 ) - ANCHO_VENTANA/ 2;
             this->camara->y = ( jugadorActual->getPosY() + Jugador::ALTO_JUGADOR / 2 ) - ALTO_VENTANA/ 2;

         }*/

        //Esto siempre
        //Center the this->camara->over the dot
        if ( (this->camara->x + ANCHO_VENTANA-MARGEN)<(jugadorActual->getPosX() + Jugador::ANCHO_JUGADOR / 2 ))
        {
            this->camara->x +=Jugador::VELOCIDAD_JUGADOR*this->model->getJugadorActivo()->getAceleracion(); //=( jugador.getPosX() + Jugador::ANCHO_JUGADOR / 2 ) - ANCHO_VENTANA/ 2;
        }
        if ( (this->camara->x + MARGEN)>(jugadorActual->getPosX() + Jugador::ANCHO_JUGADOR / 2 ))
        {
            this->camara->x -=Jugador::VELOCIDAD_JUGADOR*this->model->getJugadorActivo()->getAceleracion();// ( jugador.getPosX() + Jugador::ANCHO_JUGADOR / 2 ) - ANCHO_VENTANA/ 2;
        }

        if ((this->camara->y + ALTO_VENTANA-MARGEN)<(jugadorActual->getPosY() + Jugador::ALTO_JUGADOR / 2 ))
        {
            this->camara->y +=Jugador::VELOCIDAD_JUGADOR*this->model->getJugadorActivo()->getAceleracion();//= ( jugador.getPosY() + Jugador::ALTO_JUGADOR / 2 ) - ALTO_VENTANA / 2;
        }
        if ((this->camara->y + MARGEN)>(jugadorActual->getPosY() + Jugador::ALTO_JUGADOR / 2 ))
        {
            this->camara->y -=Jugador::VELOCIDAD_JUGADOR*this->model->getJugadorActivo()->getAceleracion();//= ( jugador.getPosY() + Jugador::ALTO_JUGADOR / 2 ) - ALTO_VENTANA / 2;
        }
        //Keep the this->camara->in bounds
        if( this->camara->x < 0 )
        {
            this->camara->x = 0;
        }
        if( this->camara->y < 0 )
        {
            this->camara->y = 0;
        }
        if( this->camara->x > ANCHO_NIVEL - this->camara->w )
        {
            this->camara->x = ANCHO_NIVEL - this->camara->w;
        }
        if( this->camara->y > ALTO_NIVEL - this->camara->h )
        {
            this->camara->y = ALTO_NIVEL - this->camara->h;
        }
        this->jugadorAnterior = jugadorActual;
        NotifyMessage("Finaliza: ajustarCamara", "View.cpp");
    }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "View.cpp");
        NotifyError(re.what(), "View.cpp");
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "View.cpp");
        NotifyError(ex.what(), "View.cpp");
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "View.cpp");
    }
}

void View::render()
{
    try
    {
        NotifyMessage("Inicia: render", "View.cpp");
        this->ajustarCamara();
        SDL_SetRenderDrawColor( this->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( this->gRenderer );

        this->viewModel->render();

        //Update screen
        SDL_RenderPresent( this->gRenderer );
        NotifyMessage("Finaliza: render", "View.cpp");
    }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "View.cpp");
        NotifyError(re.what(), "View.cpp");
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "View.cpp");
        NotifyError(ex.what(), "View.cpp");
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "View.cpp");
    }
}

bool View::inicializar()
{
    bool exito = true;
    try
    {
        NotifyMessage("Inicia: inicializar", "View.cpp");

        if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
        {
            printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
            NotifyError("SDL could not initialize! SDL Error: ", "View.cpp");
            NotifyError(SDL_GetError(), "View.cpp");
            exito = false;
        }
        else
        {
            if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
            {
                printf( "Warning: Linear texture filtering not enabled!" );
                NotifyWarning("Warning: Linear texture filtering not enabled!", "View.cpp");
            }

            //Create window
            this->window = SDL_CreateWindow( "Taller de Programacion - Correlatividad", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ANCHO_VENTANA, ALTO_VENTANA, SDL_WINDOW_SHOWN );
            if( this->window == NULL )
            {
                printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
                NotifyError("Window could not be created! SDL Error: ", "View.cpp");
                NotifyError(SDL_GetError(), "View.cpp");
                exito = false;
            }
            else
            {
                //Create vsynced renderer for this->window
                this->gRenderer = SDL_CreateRenderer( this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
                if( this->gRenderer == NULL )
                {
                    printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                    NotifyError("Renderer could not be created! SDL Error: ", "View.cpp");
                    NotifyError(SDL_GetError(), "View.cpp");
                    exito = false;
                }
                else
                {
                    //Initialize renderer color
                    SDL_SetRenderDrawColor( this->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                    //Initialize PNG loading
                    int imgFlags = IMG_INIT_PNG;
                    if( !( IMG_Init( imgFlags ) & imgFlags ) )
                    {
                        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                        NotifyError("SDL_image could not initialize! SDL_image Error: ", "View.cpp");
                        NotifyError(IMG_GetError(), "View.cpp");
                        exito = false;
                    }
                }
            }
        }
        NotifyMessage("Finaliza: inicializar", "View.cpp");
    }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "View.cpp");
        NotifyError(re.what(), "View.cpp");
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "View.cpp");
        NotifyError(ex.what(), "View.cpp");
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "View.cpp");
    }
    return exito;
}

void View::close()
{
    try
    {
        NotifyMessage("Inicia: close", "View.cpp");
        //Destroy this->window}
        SDL_DestroyRenderer( this->gRenderer );
        SDL_DestroyWindow( this->window );

        this->gRenderer = NULL;
        this->window = NULL;

        //Quit SDL subsystems
        IMG_Quit();
        SDL_Quit();
        NotifyMessage("Finaliza: close", "View.cpp");
    }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "View.cpp");
        NotifyError(re.what(), "View.cpp");
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "View.cpp");
        NotifyError(ex.what(), "View.cpp");
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "View.cpp");
    }
}
