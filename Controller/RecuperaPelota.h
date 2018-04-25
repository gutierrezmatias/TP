#ifndef RECUPERAPELOTA_H
#define RECUPERAPELOTA_H
#include <Command.h>
#include "Model.h"

class RecuperaPelota  : public Command
{
    public:
        RecuperaPelota(Model* model);
        virtual ~RecuperaPelota();
        void execute();
    protected:

    private:
        Model* model;
};

#endif // RECUPERAPELOTA_H
