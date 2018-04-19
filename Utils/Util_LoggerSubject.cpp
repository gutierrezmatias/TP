#include "Util_LoggerSubject.h"
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void Util_LoggerSubject::Attach(Util_LoggerObserver* logger)
{
    list.push_back(logger);
}
void Util_LoggerSubject::Detach(Util_LoggerObserver* logger)
{
    list.erase(std::remove(list.begin(), list.end(), logger), list.end());
}

void Util_LoggerSubject::NotifyMessage(std::string message, std::string mvc)
{
    for(vector<Util_LoggerObserver*>::const_iterator iter = list.begin(); iter != list.end(); ++iter)
    {
        if(*iter != 0)
        {
            (*iter)->writeMessageLine(message, mvc);
        }
    }
}

void Util_LoggerSubject::NotifyWarning(std::string message, std::string mvc)
{
    for(vector<Util_LoggerObserver*>::const_iterator iter = list.begin(); iter != list.end(); ++iter)
    {
        if(*iter != 0)
        {
            (*iter)->writeWarningLine(message, mvc);
        }
    }
}

void Util_LoggerSubject::NotifyError(std::string message, std::string mvc)
{
    for(vector<Util_LoggerObserver*>::const_iterator iter = list.begin(); iter != list.end(); ++iter)
    {
        if(*iter != 0)
        {
            (*iter)->writeErrorLine(message, mvc);
        }
    }
}

void Util_LoggerSubject::NotifyLevel(int newLevel)
{
    for(vector<Util_LoggerObserver*>::const_iterator iter = list.begin(); iter != list.end(); ++iter)
    {
        if(*iter != 0)
        {
            (*iter)->updateLevel(newLevel);
        }
    }
}
