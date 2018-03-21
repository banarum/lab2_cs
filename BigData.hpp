//
// Created by Sergey on 20.03.2018.
//

#ifndef LAB_2_BIGDATA_HPP
#define LAB_2_BIGDATA_HPP


#include <vector>
#include <string>

class BigData {
private:
    std::vector<char> data;
    unsigned int seed;
public:
    void generateData(int size, unsigned int seed);
    int getSize();
    std::string getHash();
    BigData();
    BigData(const BigData& bigData);
    BigData &operator=(const BigData& bigData);
};


#endif //LAB_2_BIGDATA_HPP
