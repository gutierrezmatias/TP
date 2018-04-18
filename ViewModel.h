#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "View_Pelota.h"
#include "View_Jugador.h"
#include "View_Cancha.h"
#include "Model.h"

class ViewModel
{
public:
    ViewModel(Model* model, SDL_Renderer* gRenderer, SDL_Rect* camara);
    virtual ~ViewModel();
    void render();
protected:

private:
    View_Pelota viewPelota;
    View_Jugador* viewJugadores;
    View_Cancha viewCancha;
    SDL_Rect* camara;
    SDL_Renderer* gRenderer;
};

#endif // VIEWMODEL_H
