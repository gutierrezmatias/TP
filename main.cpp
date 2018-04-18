#include <iostream>

#include "Utils/Util_LoggerObserver.h"
#include "Utils/Util_Configuracion.h"
#include "Utils/Util_Common.h"
#include "Model.h"
#include "Controller.h"
#include "View.h"
//Solo para probar hasta que pueda manejar el logg y parser

#include "Utils/IObserver.h"



//unsigned short logLevel;
using namespace std;
//Util_Logger logger;

Util_Common common;

int main(int argc, char* args[])
{
    // Hacemos un backup del log de la ejecucion anterior.
    common.backupFile();
    // Hacemos un log de la ejecucion anterior.
    common.createFile();

    // Iniciar el logger con el nivel que corresponda segun configuracion.
    Util_LoggerObserver* loggerObserver = new Util_LoggerObserver(3);
    Model model;
    model.Attach(loggerObserver);
    //Solo hasta que pueda manejar logger, esto es un asco.
    Util_Configuracion configuracion(&model);
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


    return 0;

}

