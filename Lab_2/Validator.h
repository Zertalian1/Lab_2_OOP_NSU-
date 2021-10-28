#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include <sys/stat.h>
#include <stdexcept>


using namespace std;

class Validator
{
public:
    static void badFile(const string& file);
};


#endif
