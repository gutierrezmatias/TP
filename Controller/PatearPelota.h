#ifndef PATEARPELOTA_H
#define PATEARPELOTA_H
#include <Command.h>
#include "Model.h"
#include "iostream"

class PatearPelota : public Command
{
    public:
        PatearPelota(Model* model);
        virtual ~PatearPelota();
        void execute();

    protected:

    private:
        Model* model;
};

#endif // PATEARPELOTA_H
