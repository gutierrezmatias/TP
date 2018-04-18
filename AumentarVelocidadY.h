#ifndef AUMENTARVELOCIDADY_H
#define AUMENTARVELOCIDADY_H

#include <Command.h>
#include "Model.h"


class AumentarVelocidadY : public Command
{
public:
    AumentarVelocidadY(Model* model);
    virtual ~AumentarVelocidadY();
    void execute();


protected:

private:
    Model* model;
};

#endif // AUMENTARVELOCIDADY_H
