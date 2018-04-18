#ifndef DISMINUIRVELOCIDADX_H
#define DISMINUIRVELOCIDADX_H

#include <Command.h>
#include "Model.h"


class DisminuirVelocidadX : public Command
{
public:
    DisminuirVelocidadX(Model* model);
    virtual ~DisminuirVelocidadX();
    void execute();

protected:

private:
    Model* model;
};

#endif // DISMINUIRVELOCIDADX_H
