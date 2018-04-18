#ifndef DISMINUIRVELOCIDADY_H
#define DISMINUIRVELOCIDADY_H

#include "Command.h"
#include "Model.h"


class DisminuirVelocidadY : public Command
{
public:
    DisminuirVelocidadY(Model* model);
    virtual ~DisminuirVelocidadY();
    void execute();

protected:

private:
    Model* model;
};

#endif // DISMINUIRVELOCIDADY_H
