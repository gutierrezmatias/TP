#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <list>
#include <cstdio>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

#include "Util_Common.h"
Util_Common myUtil;

// Obtenemos la fecha con el siguiente formato -> YYYY-MM-DD.HH:mm:ss
string Util_Common::currentDateTime()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
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

void Util_Common::createFile()
{
    // Definimos un nombre para el Log de manera que sea UNIVOCO.-
    string actualLogName = "./Logs/Log.txt";

    // Creamos e inicializamos nunestro nuevo archivos de log.
    std::ofstream outfile (actualLogName);
    //outfile.open(getLogFile());
    outfile << "Archivo de Log inicializado: " << myUtil.currentDateTime() << std::endl;
    outfile << std::endl;
    outfile.close();

    //Chequeamos que haya sido creado exitosamente.
    if(!file_exists(actualLogName))
    {
        perror(("No existe el archivo de Log que se intento inicializar."));
        exit(1);
    }
}

void Util_Common::backupFile()
{
    string newFileName = "./Logs/Cerrado (" + myUtil.currentDateTime() + ") Log.txt";
    string oldFileName = "./Logs/Log.txt";
    int result = rename(oldFileName.c_str(), newFileName.c_str());
    if ( result == 0 ) puts ( "Hemos sobreescrito el nombre del archivo." );
    else perror( "No pudimos reescribir el nombre del archivo." );
}

