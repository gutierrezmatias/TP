#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model.h"
#include "Command.h"
#include <vector>
#include "../Utils/Util_LoggerSubject.h"


class Controller : public Util_LoggerSubject
{
public:
    Controller(Model* model);
    virtual ~Controller();
    Command* handleEvent(SDL_Event& e);
    void processInput();
    bool quitPressed();

protected:

private:
    Model* model;
    std::vector<Command*> commands;
    bool quit;
    SDL_Event e;
};

#endif // CONTROLLER_H
