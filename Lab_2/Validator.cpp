#include "Validator.h"

void Validator::badFile(const string& file)
{
    throw invalid_argument("Bad program file! " + file);
}
