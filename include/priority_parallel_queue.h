#pragma once

#include <queue>
#include <functional>
#include <vector>

namespace m2d
{
template <typename T>
class weighted_queue : public std::queue<T>
{
public:
    int weight;
};

template <typename T>
bool operator< (const weighted_queue<T> &q1, const weighted_queue<T> &q2){
    return q1.weight < q2.weight;
};

template <typename T>
class priority_parallel_queue
{
private:
    using Q = weighted_queue<T>;

    std::priority_queue<Q*> queues;

public:
    priority_parallel_queue() {}

    bool empty()
    {
        return queues.empty();
    }
    
    T pop()
    {
        auto q = queues.top();
        auto value = q->front();
        q->pop();
        if (q->empty()) {
            queues.pop();
            delete q;
        }
        return value;
    }

    void push(T value, int priority)
    {
        std::vector<Q*> tmp;
        while(!queues.empty()) {
            auto q = queues.top();
            if (q->weight == priority) {
                q->push(value);
                this->restore(tmp);
                return;
            }
            else {
                tmp.push_back(q);
                queues.pop();
            }
        }
        
        auto new_queue = new Q;
        new_queue->weight = priority;
        new_queue->push(value);
        queues.push(new_queue);
        this->restore(tmp);
    }
    
    void restore(std::vector<Q*> elements)
    {
        for (auto t : elements) {
            queues.push(t);
        }
    }
};

} // namespace m2d
