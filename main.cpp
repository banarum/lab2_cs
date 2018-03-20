#include <iostream>
#include <fstream>

#include "GuardedStack.hpp"
#include "ThreadGuard.hpp"
#include "BigData.hpp"

const int DATA_SIZE = 1024*1024*10;

void printStack(GuardedStack<BigData>& stack) {
    while (!stack.empty()) {
        shared_ptr<BigData> data(new BigData());
        stack.pop_top(data);
        std::cout << (*data).getHash() << std::endl;
    }
}

std::string executeCommand(GuardedStack<BigData> &stack, std::string& cmd, unsigned int seed) {
    std::string result;
    if (cmd == "push") {
        BigData data = BigData();
        data.generateData(DATA_SIZE, seed);
        stack.push(data);
    } else if (cmd == "pop_top") {
        shared_ptr<BigData> data(new BigData());
        stack.pop_top(data);
        if ((*data).getSize()>0){
            result = (*data).getHash();
        }
    }
    return result;
}

void processCommands(const std::string &pathIn, const std::string &pathOut, GuardedStack<BigData>& stack) {
    std::ifstream in(pathIn);
    std::ofstream out(pathOut);
    while (!in.eof()) {
        std::string buffer;
        std::string cmd;
        unsigned int seed;
        in >> cmd;
        in >> seed;
        buffer = executeCommand(stack, cmd, seed);
        out << buffer;
        if (!buffer.empty()) out << std::endl;
    }
}

int main() {
    GuardedStack<BigData> stack;

    ThreadGuard motherShip;

    for (int i = 0; i < 3; i++) {
        std::string name = std::string("../cmds_part_") + std::to_string(i + 1);
        thread drone(processCommands, name + std::string(".in"), name + std::string(".out"), ref(stack));
        motherShip.addThread(move(drone));
    }

    motherShip.join();

    printStack(stack);

    return 0;
}