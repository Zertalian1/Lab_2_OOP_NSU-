#include "BlockProgram.h"

void BlockProgram::exec()
{
    if (queue.empty() || blocks.empty())
        return;

  
    vector<string> textI;
    vector<string> textO;
    
    for (int i : queue)
    {
        blocks[i]->exec(&textI, &textO, i);
        textI = textO;
        
    }

}

BlockProgram::~BlockProgram()
{
    blocks.clear();
    queue.clear();
}
