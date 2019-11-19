# priority_parallel_queue

A priority queue that contains queues.

## Requirements

- C++11 or higher

## Example

For example, push some values with priority, like this.

```c++
class message
{
public:
    explicit message(std::string text) {
        this->text = text;
    }
    
    message(const message &m) = default;
    message(message&& m) = default;
    message& operator=(message&&) = default;
    message& operator=(message const&) = default;
    
    std::string text;
};

int main()
{
    auto q = m2d::priority_parallel_queue<message>();
    q.push(message("11"), 1);
    q.push(message("12"), 1);
    
    q.push(message("21"), 2);
    q.push(message("22"), 2);
    
    q.push(message("13"), 1);
    q.push(message("14"), 1);
    
    q.push(message("23"), 2);
    q.push(message("24"), 2);
    
    q.push(message("31"), 3);
    q.push(message("32"), 3);
    
    q.push(message("33"), 3);
    q.push(message("25"), 2);
    q.push(message("15"), 1);
    
    q.push(message("34"), 3);
    q.push(message("35"), 3);
    
    while(!q.empty()) {
        auto m = q.top();
        std::cout << m.text << std::endl;
        q.pop();
    }

    return 0;
}
```

A result of the eample shows as follows.

```
31
32
33
34
35
21
22
23
24
25
11
12
13
14
15
```
