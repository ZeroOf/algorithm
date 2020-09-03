//
// Created by god on 2019/12/3.
//

#ifndef SORT_SORTTOOLS_HPP
#define SORT_SORTTOOLS_HPP

#include <array>
#include <random>
#include <iostream>

class SortTools {
public:
    template<size_t n> static void generate(std::array<int,n>&);
    template<size_t n> static void printContainer(std::array<int,n>&);

private:
    static std::random_device de;
    static std::minstd_rand randomEnerge;
    static std::uniform_int_distribution<int> dis;
};

std::random_device SortTools::de;
std::minstd_rand SortTools::randomEnerge(de());
std::uniform_int_distribution<int> SortTools::dis(-100, 100);

template<size_t n>
void SortTools::generate(std::array<int, n> &container) {
    for(int i = 0; i < n; ++i){
        container[i] = dis(randomEnerge);
    }
}

template<size_t n>
void SortTools::printContainer(std::array<int, n> &container) {
    for( auto &element : container){
        std::cout << element << "\t";
    }
    std::cout << std::endl;
}




#endif //SORT_SORTTOOLS_HPP
