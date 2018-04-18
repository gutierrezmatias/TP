#ifndef MODEL_H
#define MODEL_H

#include "Model_Pelota.h"
#include "Model_Jugador.h"
#include "Command.h"
#include "Formacion.h"
#include "../Utils/Util_LoggerSubject.h"

#include <list>

class Model : public Util_LoggerSubject
{
public:
    Model();
    virtual ~Model();
    Pelota* getPelota();
    Jugador* getJugadorNro(int i);
    Jugador* getJugadorActivo();
    void addCommand(Command* command);
    void cambiarJugadorActivo();
    //void detenerJugadores();
    void update();
    void setCamara(SDL_Rect * camara);
    void setFormacion(Formacion* formacion);
    void setCasaca(int i);

protected:

private:
    Pelota pelota;
    Jugador* jugadores;
    SDL_Rect * camara;
    int nroJugadorActivo;
    std::list<Command*> commandsToApply;
};

#endif // MODEL_H
