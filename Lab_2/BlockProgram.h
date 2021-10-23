#ifndef BLOCKPROGRAM_H
#define BLOCKPROGRAM_H

#include "Worker.h"
#include "R_W.h"
#include <map>
#include <utility>
#include <memory>

class BlockProgram
{
private:
    map<unsigned int, std::shared_ptr<Worker>> blocks;
    vector<int> queue;
public:
    BlockProgram(map<unsigned int, std::shared_ptr<Worker>> blocks_, vector<int> queue_) : blocks(
        move(blocks_)), queue(move(queue_)) {}
    ~BlockProgram();
    void exec();
};

#endif //BLOCKPROGRAM_H