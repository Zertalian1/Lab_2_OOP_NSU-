#ifndef R_W
#define R_W
#include "Worker.h"
#include "Validator.h"
#include <fstream>

class FileWriterBlock : public Worker
{
private:
    std::string File_name;
public:
    FileWriterBlock(string);
    
    bool exec(vector<string>* input, vector<string>* output, unsigned int index) override;
};

class FileReaderBlock : public Worker
{
private:
    std::string File_name;
public:
    FileReaderBlock(string);
    
    bool exec(vector<string>* input, vector<string>* output, unsigned int index) override;

};
#endif //R_W