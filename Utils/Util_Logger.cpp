#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <list>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

#include "Util_Logger.h"
#include "Util_Common.h"

Util_Common util;

unsigned short  Util_Logger::getLoggerLevel()
{
    return this->loggerLevel;
}

void Util_Logger::setLoggerLevel(unsigned short  newLevel)
{
    this->loggerLevel = newLevel;
}

string Util_Logger::getLoggerName()
{
    return this->loggerName;
}

void Util_Logger::setLoggerName(string newName)
{
    this->loggerName = newName;
}

string Util_Logger::getLoggerPath()
{
    return this->loggerPath;
}

void Util_Logger::setLoggerPath(string newPath)
{
    this->loggerPath = newPath;
}

string Util_Logger::getLogFile()
{
    string fullPathString = getLoggerPath() + getLoggerName();
    return fullPathString;
}

void Util_Logger::writeSingleLine(string line, string type)
{
    printf((line + "\n").c_str());
    ofstream log_file(getLogFile(), ios_base::out | ios_base::app );
    log_file << util.currentDateTime() + " || " + type + " || " << line << endl;
    log_file.close();
}

void Util_Logger::writeMessageLine(string line)
{
    if(getLoggerLevel() >= 3)
    {
        writeSingleLine(line, "MESSAGE");
    }
}

void Util_Logger::writeWarningLine(string line)
{
    if(getLoggerLevel() >= 2)
    {
        writeSingleLine(line, "WARNING");
    }
}

void Util_Logger::writeErrorLine(string line)
{
    if(getLoggerLevel() >= 1)
    {
        writeSingleLine(line, "ERROR");
    }
}

void Util_Logger::deleteLine()
{
    // TODO: De momento no tiene un uso determinado.-
}

void Util_Logger::writeBlock(list<string> lineList)
{
    std::ofstream log_file(getLogFile(), std::ios_base::out | std::ios_base::app );
    list<string>::iterator pos;
    pos = lineList.begin();
    while( pos != lineList.end())
    {
        cout << *pos;
        log_file << std::endl;
        log_file << util.currentDateTime() + " || " << *pos << std::endl;
        pos++;
    }
    log_file.close();
}

void Util_Logger::deleteBlock()
{
    // TODO: De momento no tiene un uso determinado.-
}

// Chequeamos que el archivo exista.
inline bool file_exists (const std::string& name)
{
    ifstream f(name.c_str());
    if (f.good())
    {
        f.close();
        return true;
    }
    else
    {
        f.close();
        return false;
    }
}

void Util_Logger::createFile(unsigned short  newLevel)
{
    // Definimos un nombre para el Log de manera que sea UNIVOCO.-
    string fileDate = "(" + util.currentDateTime() + ") Log.txt";

    // Actualizamos la configuración básico del logger.
    setLoggerLevel(newLevel);
    setLoggerPath("./Logs/");
    setLoggerName(fileDate.c_str());

    // Creamos e inicializamos nunestro nuevo archivos de log.
    std::ofstream outfile (getLogFile());
    //outfile.open(getLogFile());
    outfile << "Archivo de Log inicializado: " << util.currentDateTime() << std::endl;
    outfile << std::endl;
    outfile.close();

    //Chequeamos que haya sido creado exitosamente.
    if(!file_exists(getLogFile()))
    {
        perror(("No existe el archivo de Log que se intento inicializar."));
        exit(1);
    }
}

void Util_Logger::deleteFile()
{
    // TODO: De momento no tiene un uso determinado.-
}
