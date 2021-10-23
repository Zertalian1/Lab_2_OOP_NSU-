#ifndef WORKER_H
#define WORKER_H

#include <string>
#include <vector>
#include <stdexcept>


using namespace std;

class Worker
{

public:
    virtual ~Worker() = default;
    virtual bool exec(vector<string>* input, vector<string>* output, unsigned int index) = 0;
};
#endif //WORKER_H    // интерфейс