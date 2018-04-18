#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <list>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

#include "Util_LoggerObserver.h"
#include "Util_Common.h"

Util_Common utils;

Util_LoggerObserver::Util_LoggerObserver(int myLevel)
{
    this->level = myLevel;
}

int Util_LoggerObserver::getLoggerLevel()
{
    return this->level;
}

std::string Util_LoggerObserver::getLogFile()
{
    string fullPathString = "./Logs/Log.txt";
    return fullPathString;
}

void Util_LoggerObserver::writeSingleLine(string line, string type, string mvc)
{
    printf((line + "\n").c_str());
    ofstream log_file(getLogFile(), ios_base::out | ios_base::app );
    log_file << utils.currentDateTime() + " || " + type + " || " + mvc + " || " << line << endl;
    log_file.close();
}

void Util_LoggerObserver::writeMessageLine(std::string line, std::string mvc)
{
    if(getLoggerLevel() >= 3)
    {
        writeSingleLine(line, "MESSAGE", mvc);
    }
}

void Util_LoggerObserver::writeWarningLine(std::string line, std::string mvc)
{
    if(getLoggerLevel() >= 2)
    {
        writeSingleLine(line, "WARNING", mvc);
    }
}

void Util_LoggerObserver::writeErrorLine(std::string line, std::string mvc)
{
    if(getLoggerLevel() >= 1)
    {
        writeSingleLine(line, "ERROR", mvc);
    }
}
