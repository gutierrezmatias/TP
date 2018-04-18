#ifndef CAMBIARJUGADOR_H
#define CAMBIARJUGADOR_H

#include <Command.h>
#include "Model.h"

class CambiarJugador : public Command
{
public:
    CambiarJugador(Model* model);
    virtual ~CambiarJugador();
    void execute();

protected:

private:
    Model* model;
};

#endif // CAMBIARJUGADOR_H
