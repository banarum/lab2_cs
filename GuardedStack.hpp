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

    void pop_top(T& typeObject) {
        std::lock_guard<std::mutex> lock(_m);
        if (!stack.empty()){
            typeObject = stack.top();
            stack.pop();
        }
    }

    std::shared_ptr<T> pop_top() {
        std::lock_guard<std::mutex> lock(_m);
        std::shared_ptr<T> complexObject = nullptr;
        if (!stack.empty()){
            //complexObject = std::shared_ptr<T>(new T(stack.top()));
            complexObject = std::make_shared<T>(stack.top());
            stack.pop();
        }
        return complexObject;
    }

    bool empty() {
        return stack.empty();
    }

    int size() {
        return stack.size();
    }

};


#endif //LAB_2_GUARDEDSTACK_HPP
