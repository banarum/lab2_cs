//
// Created by Sergey on 12.03.2018.
//

#ifndef LAB_2_GUARDEDSTACK_HPP
#define LAB_2_GUARDEDSTACK_HPP

#include <stack>
#include <mutex>
#include <memory>

template<class T>
class GuardedStack {
private:
    std::stack<T> stack;
    std::mutex _m;
public:
    void push(T obj) {
        std::lock_guard<std::mutex> lock(_m);
        stack.push(obj);
    }

    void pop_top(T& bigData) {
        std::lock_guard<std::mutex> lock(_m);
        if (!stack.empty()){
            bigData = stack.top();
            stack.pop();
        }
    }

    bool empty() {
        return stack.empty();
    }

    int size() {
        return stack.size();
    }

};


#endif //LAB_2_GUARDEDSTACK_HPP
