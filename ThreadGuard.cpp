//
// Created by Sergey on 01.03.2018.
//

#include "ThreadGuard.hpp"

ThreadGuard::ThreadGuard() {
}

ThreadGuard::~ThreadGuard() {
    this->join();
}

void ThreadGuard::addThread(thread t) {
    this->threads.push_back(move(t));
}

void ThreadGuard::join() {
    for(int i=0;i<threads.size();i++){ // NOLINT
        if (threads[i].joinable()) threads[i].join();
    }
}
