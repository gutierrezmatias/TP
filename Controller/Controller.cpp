#include "Controller.h"

#include "DisminuirVelocidadY.h"
#include "AumentarVelocidadY.h"
#include "DisminuirVelocidadX.h"
#include "AumentarVelocidadX.h"
#include "CambiarJugador.h"
#include "StopJugador.h"
#include "Acelerar.h"
#include "Desacelerar.h"

#define CANTCOMMANDS 8


enum IDCommand {DECVELX, DECVELY, INCVELX, INCVELY, CAMBJUG, STOPJUG, ACCJUG, DESJUG};

Controller::Controller(Model* model)
{
    this->model = model;
    this->commands = std::vector<Command*>(CANTCOMMANDS);
    this->commands[DECVELX] = new DisminuirVelocidadX(model);
    this->commands[DECVELY] = new DisminuirVelocidadY(model);
    this->commands[INCVELX] = new AumentarVelocidadX(model);
    this->commands[INCVELY] = new AumentarVelocidadY(model);
    this->commands[CAMBJUG] = new CambiarJugador(model);
    this->commands[STOPJUG] = new StopJugador(model);
    this->commands[ACCJUG] = new Acelerar(model);
    this->commands[DESJUG] = new Desacelerar(model);

    this->quit = false;
}

Controller::~Controller()
{
    for(unsigned i = 0; i < CANTCOMMANDS; ++i)
    {
        delete this->commands[i];
    }
}

bool Controller::quitPressed()
{
    return this->quit;
}

void Controller::processInput()
{
    NotifyMessage("Inicia: processInput", "CONTROLLER");
    while( SDL_PollEvent( &(this->e) ) != 0 )
    {
        if( this->e.type == SDL_QUIT )
        {
            this->quit = true;
        }
        this->model->addCommand(this->handleEvent(this->e));
    }
    NotifyMessage("Inicia: processInput", "CONTROLLER");
}

Command* Controller::handleEvent(SDL_Event& e)
{
    NotifyMessage("Inicia: handleEvent", "CONTROLLER");
    Command* command = nullptr;

    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        NotifyMessage("Chequeamos: SDL_KEYDOWN", "CONTROLLER");
        switch( e.key.keysym.sym )
        {
        case SDLK_UP:
            command = this->commands[DECVELY];
            break;
        case SDLK_DOWN:
            command = this->commands[INCVELY];
            break;
        case SDLK_LEFT:
            command = this->commands[DECVELX];
            break;
        case SDLK_RIGHT:
            command = this->commands[INCVELX];
            break;
        case SDLK_SPACE:
            command = this->commands[CAMBJUG];
            break;
        case SDLK_f:
            command = this->commands[ACCJUG];
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {

        NotifyMessage("Chequeamos: SDL_KEYUP", "CONTROLLER");
        switch( e.key.keysym.sym )
        {
        case SDLK_UP:
            command = this->commands[STOPJUG];
            break;
        case SDLK_DOWN:
            command = this->commands[STOPJUG];
            break;
        case SDLK_LEFT:
            command = this->commands[STOPJUG];
            break;
        case SDLK_RIGHT:
            command = this->commands[STOPJUG];
            break;
        case SDLK_f:
            command = this->commands[DESJUG];
        }
    }
    NotifyMessage("Finaliza: handleEvent", "CONTROLLER");
    return command;
}
