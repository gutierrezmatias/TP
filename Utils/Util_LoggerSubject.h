#pragma once
#include <vector>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include "Util_LoggerObserver.h"

class Util_LoggerSubject
{
    std::vector<Util_LoggerObserver*> list;

public:
    void Attach(Util_LoggerObserver* logger);
    void Detach(Util_LoggerObserver* logger);
    void NotifyMessage(std::string message, std::string mvc);
    void NotifyWarning(std::string message, std::string mvc);
    void NotifyError(std::string message, std::string mvc);
    void NotifyLevel(int newLevel);
};

