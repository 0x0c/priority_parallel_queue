#pragma once

#include <queue>
#include <tuple>

namespace m2d
{
template <typename T>
bool operator< (const std::tuple<int, int, T> &t1, const std::tuple<int, int, T> &t2){
    int priority1 = std::get<0>(t1);
    int counter1 = std::get<1>(t1);
    int priority2 = std::get<0>(t2);
    int counter2 = std::get<1>(t1);
    
    return (priority1 < priority2) && (counter1 < counter2);
};

template <typename T>
class priority_parallel_queue
{
private:
    using Q = std::tuple<int, int, T>;
    
    std::priority_queue<Q> queue;
    int counter = 0;
    
public:
    void push(T value, int priority)
    {
        queue.push(std::make_tuple(priority, counter, value));
        counter++;
    }
    
    T top()
    {
        auto value = queue.top();
        return std::get<2>(value);
    }
    
    void pop()
    {
        queue.pop();
    }
    
    bool empty()
    {
        return queue.empty();
    }
};
} // namespace m2d
