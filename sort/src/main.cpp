#include <iostream>
#include <array>
#include <algorithm>
#include <random>
#include "SortTools.hpp"
#include "Sort.hpp"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::array<int, 10> array({0});

    SortTools::generate(array);
    SortTools::printContainer(array);

//    Sort::HeapSort(&array[0], 10);
    Sort::QuickSort(array, 0, 9);
    SortTools::printContainer(array);
    //mergeSort
    //Sort::MergeSort(array, 0, 9);
    //SortTools::printContainer(array);

//    Sort::PopSort(array);
//    SortTools::printContainer(array);
//    random_device rd;
//    mt19937 g(rd());
//    shuffle(array.begin(), array.end(), g);

//    SortTools::printContainer(array);
//    Sort::InsertSort(array);
//    SortTools::printContainer(array);

//    shuffle(array.begin(), array.end(), g);
//    SortTools::printContainer(array);
    return 0;
}
