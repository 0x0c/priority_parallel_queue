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
    auto q = m2d::priority_parallel_queue<message>();
    q.push(message("a1"), 1);
    q.push(message("b1"), 1);
    
    q.push(message("a2"), 2);
    q.push(message("b2"), 2);
    
    q.push(message("c1"), 1);
    q.push(message("a3"), 3);
    q.push(message("c2"), 2);
    
    q.push(message("b3"), 3);
    q.push(message("d2"), 2);
    q.push(message("d1"), 1);
    
    q.push(message("c3"), 3);
    q.push(message("d3"), 3);
    
    while(!q.empty()) {
        auto m = q.pop();
        std::cout << m.text << std::endl;
    }
    
    return 0;
}
