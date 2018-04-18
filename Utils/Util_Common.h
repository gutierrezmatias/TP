#ifndef UTIL_COMMON_H_
#define UTIL_COMMON_H_

#include <iostream>
#include <string>
using namespace std;

class Util_Common
{
public:
    string currentDateTime();
    void createFile();
    void backupFile();
};



#endif /* UTIL_COMMON_H_ */
