//всё будет запускаться отсюда all will start fom hear

#ifndef PARSER_H
#define PARSER_H

#include "BlockProgram.h"
#include "Validator.h"
#include "Operateons.h"
#include "R_W.h"
#include <utility>
#include <fstream>

class Parser
{
public:
    static BlockProgram parseProgram(string file);
};


#endif //PARSER_H