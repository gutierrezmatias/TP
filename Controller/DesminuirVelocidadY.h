#ifndef DESMINUIRVELOCIDADY_H
#define DESMINUIRVELOCIDADY_H

#include <Command.h>
#include <Model.h>


class DesminuirVelocidadY : public Command
{
    public:
        DesminuirVelocidadY(Model* model);
        virtual ~DesminuirVelocidadY();
        void execute();

    protected:

    private:
        Model* model;
};

#endif // DESMINUIRVELOCIDADY_H
