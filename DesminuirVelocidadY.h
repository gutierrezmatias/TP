#ifndef DESMINUIRVELOCIDADY_H
#define DESMINUIRVELOCIDADY_H

#include <Command.h>
#include <Model.h>


class DesminuirVelocidadY : public Command
{
    public:
        DesminuirVelocidadY();
        virtual ~DesminuirVelocidadY();
        void execute();
        void setModel(Model& model);

    protected:

    private:
        Model model;
};

#endif // DESMINUIRVELOCIDADY_H
