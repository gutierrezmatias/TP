#ifndef FORMACION_H
#define FORMACION_H

#include "Model_Jugador.h"

#define CANTDIVANCHO 12
#define CANTDIVALTO 6
#define CANTJUGADORES 7
class Formacion
{
public:
    Formacion();
    virtual ~Formacion();
    virtual void setPosicionInicial(Jugador* jugadores) = 0;

protected:

private:
};

#endif // FORMACION_H
