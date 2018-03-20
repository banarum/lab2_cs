//
// Created by Sergey on 01.03.2018.
//

#ifndef LAB_1_THREADGUARD_HPP
#define LAB_1_THREADGUARD_HPP

#include <thread>
#include <vector>

using namespace std;

class ThreadGuard {
private:
    vector<thread> threads;
public:
    explicit ThreadGuard();

    void addThread(thread t);

    void join();

    ~ThreadGuard();

    ThreadGuard &operator=(ThreadGuard &obj) = delete;
};


#endif //LAB_1_THREADGUARD_HPP
