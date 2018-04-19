#ifndef ACELERAR_H
#define ACELERAR_H

#include <Command.h>
#include "Model.h"


class Acelerar : public Command
{
public:
    Acelerar(Model* model);
    virtual ~Acelerar();
    void execute();


protected:

private:
    Model* model;
};

#endif // ACELERAR_H
