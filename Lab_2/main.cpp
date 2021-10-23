#include <iostream>
#include "Parser.h"

int main(int argc, char* argv[])
{
    //program.txt
    
    string File_name;
    cin >> File_name;
    Parser::parseProgram(File_name).exec(); 

    return 0;
}