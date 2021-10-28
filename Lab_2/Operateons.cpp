#include "Operateons.h"

bool SortBlock::exec(vector<string>* input, vector<string>* output, unsigned int index)
{

    (*output) = (*input);
    if (input->empty())
        return true;

    sort((*output).begin(), (*output).end());

    return true;
}

ReplaceBlock::ReplaceBlock(const string& word1,const string& word2)
{
    word1_ = word1;
    word2_ = word2;
}

bool ReplaceBlock::exec(vector<string>* input, vector<string>* output, unsigned int index)   
{


    (*output) = (*input);
    if (input->empty())
        return true;

    size_t index_;
    for (string& i : *output)
        while ((index_ = i.find(word1_)) != string::npos)  
            i.replace(index_, word1_.size(), word2_);

    return true;
}

GrepBlock::GrepBlock(const string& word)
{
    word_ = word;
}

bool GrepBlock::exec(vector<string>* input, vector<string>* output, unsigned int index)
{

    if (input->empty())
    {
        (*output) = (*input);
        return true;
    }

    (*output).clear();

    for (const auto& i : *input)
        if (i.find(word_) != string::npos)
            output->push_back(i);

    return true;
}

DumpBlock::DumpBlock(const string& filename)
{
    filename_ = filename;
}

bool DumpBlock::exec(vector<string>* input, vector<string>* output, unsigned int index)
{


    (*output) = (*input);
    ofstream fos(filename_);

    if (!fos)
    {
        Validator::badFile("File " + filename_ + " cannot opened!");
        return false;
    }

    for (const auto& i : *input)
        fos << i << endl;

    fos.close();


    return true;
}

