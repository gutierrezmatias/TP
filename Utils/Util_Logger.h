#ifndef UTIL_LOGGER_H_
#define UTIL_LOGGER_H_

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Util_Logger
{
private:
    string loggerName;
    string loggerPath;
    unsigned short loggerLevel;
public:
    unsigned short getLoggerLevel();
    void setLoggerLevel(unsigned short  newLevel);
    string getLoggerName();
    void setLoggerName(string newName);
    string getLoggerPath();
    void setLoggerPath(string newPath);
    string getLogFile();

    // Escribe una linea dentro del archivo para logueo.
    void writeMessageLine(string line);
    // Escribe una linea dentro del archivo para logueo de advertencias.
    void writeWarningLine(string line);
    // Escribe una linea dentro del archivo para logueo de errores.
    void writeErrorLine(string line);
    void writeSingleLine(string line, string type);
    // DE momento no tiene uso.-
    void deleteLine();
    // Escribe las lineas pasadas en la lista dentro del archivo para logueo.
    void writeBlock(list<string> lineList);
    // DE momento no tiene uso.-
    void deleteBlock();
    // Genera un nuevo archivo de log y hace un resguardo del anterior si existiese.-
    void createFile(unsigned short  level);
    // DE momento no tiene uso.-
    void deleteFile();
};

#endif
