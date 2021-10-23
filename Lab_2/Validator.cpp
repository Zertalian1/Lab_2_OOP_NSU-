#include "Validator.h"

void Validator::badFile(string file)
{
    throw invalid_argument("Bad program file! " + file);
}