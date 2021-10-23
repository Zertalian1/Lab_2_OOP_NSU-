#include "Parser.h"
#include <iostream>


shared_ptr<Worker> parseBlock(ifstream& fis)
{
    string tmp0, tmp1;
    fis >> tmp0;

    if (tmp0 != "=")
        Validator::badFile("Haven't '=' at block part!");

    fis >> tmp0;
    shared_ptr<Worker> block;
    if (tmp0 == "readfile")// выбор операции
    {
        fis >> tmp1;
        block = make_shared<FileReaderBlock>(tmp1);
        return block;
    }
    else if (tmp0 == "writefile")
    {
        fis >> tmp1;
        block = make_shared<FileWriterBlock>(tmp1);
        return block;
    }
    else if (tmp0 == "grep")
    {
        fis >> tmp1;
        block = make_shared<GrepBlock>(tmp1);
        return block;
    }
    else if (tmp0 == "sort")
    {
        block = make_shared<SortBlock>();
        return block;
    }
    else if (tmp0 == "replace")
    {
        fis >> tmp0 >> tmp1;
        block = make_shared<ReplaceBlock>(tmp0, tmp1);
        return block;
    }
    else if (tmp0 == "dump")
    {
        fis >> tmp1;
        block = make_shared<DumpBlock>(tmp1);
        return block;
    }
    else
    {
        Validator::badFile("Bad block name: " + tmp0);
        return nullptr;
    }
}

bool parseBlockPart(map<unsigned int, shared_ptr<Worker>>& map, ifstream& fis)
{
    if (fis.eof()) {
        cerr << "EOF file!";
        return false;
    }
    string tmp0;
    fis >> tmp0;
    unsigned int index;
    if (tmp0 != "desc")
        Validator::badFile("Haven't 'desc' at block part!");

    while (true)
    {
        try
        {
            if (fis.eof())
                Validator::badFile("Bad end of block part! where is csed?");
            fis >> tmp0;
            if (tmp0 == "csed") // если конец блока функций, то выходим
                break;

            index = stoi(tmp0);
            if (map.count(index)) // заполняем массив: ключ-операция
                Validator::badFile("Index " + to_string(index) + " already exists!"); 
            else
                map[index] = parseBlock(fis);

        }
        catch (exception& e) {
            cerr << (e.what());
            return false;
        }
    }

    return true;
}

bool parseQueue(vector<int>& queue, ifstream& fis)
{
    if (fis.eof()) {
        cerr << "EOF file!";
        return false;
    }
    string tmp0;
    unsigned int index;
    while (true)
    {
        try
        {
            if (fis.eof())
                break;

            fis >> tmp0;
            index = stoi(tmp0);
            queue.push_back(index); // закинули число

            if (fis.eof())
                break;
            fis >> tmp0;
            if (tmp0 != "->") // избавились от ->
                Validator::badFile("Unknown symbol at queue part: " + tmp0); /////////////////////////////////////////////////
        }
        catch (exception& e) {
            cerr << e.what(); // перехват сообщения ошибки и вывод его
            return false;
        }
    }
    return true;
}

BlockProgram Parser::parseProgram(string file)   // основная часть, место, где происходит магия
{

    bool HaveError = false;
    ifstream fis(file);
    try
    {
        if (!fis.is_open())
            Validator::badFile("Unable to open the file: " + file);
    }
    catch (exception& e) {
        cerr << e.what(); // перехват сообщения ошибки и вывод его
        HaveError = true;
    }
    

    

    map<unsigned int, shared_ptr<Worker>> blocks; 
    if (!HaveError && !parseBlockPart(blocks, fis)) // создали map хранящий номер операции и соотв. команду
        HaveError = true;

    vector<int> queue;
    if (!HaveError && !parseQueue(queue, fis))// создали очередь вызова функций
        HaveError = true;


    fis.close();

    if (HaveError)
    {
        queue.clear();
        blocks.clear();


    }

    return BlockProgram(blocks, queue);
}
