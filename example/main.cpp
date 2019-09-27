#include <iostream>
#include "../include/priority_parallel_queue.h"

using namespace std;

class message
{
public:
    message(std::string text) {
        this->text = text;
    }
    
    std::string text;
};

int main()
{
    auto q = m2d::priority_parallel_queue<std::string>();
    q.push("11", 1);
    q.push("12", 1);
    
    q.push("21", 2);
    q.push("22", 2);
    
    q.push("13", 1);
    q.push("14", 1);
    
    q.push("23", 2);
    q.push("24", 2);
    
    q.push("31", 3);
    q.push("32", 3);
    
    q.push("33", 3);
    q.push("25", 2);
    q.push("15", 1);
    
    q.push("34", 3);
    q.push("35", 3);
    
    while(!q.empty()) {
        auto m = q.top();
        std::cout << m << std::endl;
        q.pop();
    }

    return 0;
}
