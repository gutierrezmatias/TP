#ifndef VIEW_H
#define VIEW_H

#include "ViewModel.h"
#include "Model.h"
#include "Model_Jugador.h"
#include "../Utils/Util_LoggerSubject.h"

class View : public Util_LoggerSubject
{
public:
    View(Model* model);
    virtual ~View();
    void ajustarCamara();
    void render();
    bool inicializar();
    void close();
protected:

private:
    Model* model;
    Jugador* jugadorAnterior;
    ViewModel* viewModel;
    SDL_Rect* camara;
    SDL_Rect camaraStatic;
    SDL_Renderer* gRenderer;
    SDL_Window* window;
};

#endif // VIEW_H
