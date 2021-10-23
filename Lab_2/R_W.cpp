#include "R_W.h"
#include <iostream>

FileReaderBlock::FileReaderBlock(string inputFile)
{
    File_name = inputFile;
}

bool FileWriterBlock::exec(vector<string>* input, vector<string>* output, unsigned int index)
{

    ofstream fos(File_name);

    if (!fos)
    {
        cerr << ("File " + File_name + " cannot opened!");
        return false;
    }

    for (const auto& i : *input)
        fos << i << endl;

    fos.close();

    return true;
}

FileWriterBlock::FileWriterBlock(string inputFile)
{
    File_name = inputFile;
}


bool FileReaderBlock::exec(vector<string>* input, vector<string>* output, unsigned int index)
{
    

    string line;
    ifstream fis(File_name);

    if (!fis)
    {
        cerr << ("File " + File_name + " cannot opened!");
        return false;
    }

    while (getline(fis, line))
        output->push_back(line);

    fis.close();


    return true;
}

