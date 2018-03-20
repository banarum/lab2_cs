//
// Created by Sergey on 20.03.2018.
//

#include "BigData.hpp"

void BigData::generateData(int size, unsigned int seed) {
    std::srand(seed);
    for (int i=0;i<size;i++){
        this->data.push_back(static_cast<char>(std::rand()%('Z'-'A')+'A')); // NOLINT
    }
    this->seed = seed;
}

std::string BigData::getHash() {
    std::string result;
    for (int i=0;i<this->data.size();i+=this->data.size()/15){
        result+=this->data[i];
    }
    result+="&";
    result+=std::to_string(this->seed);
    return result;
}

int BigData::getSize() {
    return this->data.size();
}


