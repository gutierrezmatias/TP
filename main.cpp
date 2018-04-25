#include <iostream>

#include "Utils/Util_LoggerObserver.h"
#include "Utils/Util_Configuracion.h"
#include "Utils/Util_Common.h"
#include "Utils/IObserver.h"
#include "Model.h"
#include "Controller.h"
#include "View.h"

using namespace std;

Util_Common common;

int main(int argc, char* args[])
{
    // Hacemos un backup del log de la ejecucion anterior.
    common.backupFile();
    // Hacemos un log de la ejecucion anterior.
    common.createFile();
    // Creamos el logger con el nivel más bajo.
    Util_LoggerObserver* loggerObserver = new Util_LoggerObserver(3);

    Model model;
    model.Attach(loggerObserver);

    Util_Configuracion configuracion(&model, loggerObserver);

    View view(&model);
    view.Attach(loggerObserver);

    Controller controller(&model);
    controller.Attach(loggerObserver);

    while( !controller.quitPressed() )
    {
        controller.processInput();
        model.update();
        view.render();
    }
    delete loggerObserver;
    return 0;
}

