#ifndef OPER_H
#define OPER_H
#include "Worker.h"
#include <algorithm>
#include <fstream>
#include "Validator.h"

class SortBlock : public Worker
{
public:
    bool exec(vector<string>* input, vector<string>* output,  unsigned int index) override;// èíäåêñ äëÿ íàâèãàöèè
};

class ReplaceBlock : public Worker
{
private:
    string word1_;
    string word2_;
public:
    ReplaceBlock(const string& word1,const string& word2);
    bool exec(vector<string>* input, vector<string>* output, unsigned int index) override;
};

class GrepBlock : public Worker
{
private:
    string word_;
public:
    GrepBlock(const string& word);
    bool exec(vector<string>* input, vector<string>* output, unsigned int index) override;
};

class DumpBlock : public Worker
{
private:
    string filename_;
public:
    DumpBlock(const string& filename);
    bool exec(vector<string>* input, vector<string>* output, unsigned int index) override;
};

#endif //OPER_H
