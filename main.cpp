#include <iostream>
#include <fstream>
#include <map>

#include "GuardedStack.hpp"
#include "ThreadGuard.hpp"
#include "BigData.hpp"

const int DATA_SIZE = 1024*10;

enum CMD {PUSH = 0, POPTOP = 1};

std::map<int, std::string> COMMANDS {
        {CMD::PUSH, "push"},
        {CMD::POPTOP, "pop_top"}
};

void printStack(GuardedStack<BigData>& stack) {
    while (!stack.empty()) {
        std::shared_ptr<BigData> bigData;
        bigData = stack.pop_top();
        std::cout << bigData->getHash() << std::endl;
    }
}

std::string executeCommand(GuardedStack<BigData> &stack, std::string& cmd, unsigned int seed) {
    std::string result;
    if (cmd == COMMANDS[CMD::PUSH]) {
        BigData data = BigData();
        data.generateData(DATA_SIZE, seed);
        stack.push(data);
    } else if (cmd == COMMANDS[CMD::POPTOP]) {
        std::shared_ptr<BigData> data;
        data = stack.pop_top();
        if (data!= nullptr){
            result = data->getHash();
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