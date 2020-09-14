#ifndef SORT_SORT_HPP
#define SORT_SORT_HPP

#include <array>

class Sort {
public:
    template<size_t n>
    static void PopSort(std::array<int, n> &container);

    template<size_t n>
    static void InsertSort(std::array<int, n> &container);

    //merge sort
    template<size_t n>
    static void Merge(std::array<int, n> &container, int head, int mid, int tear);

    template<size_t n>
    static void MergeSort(std::array<int, n> &container, int head, int tail);

    //heap sort
    static void Heapify(int container[], size_t size, int pos);

    static void BuildHeap(int container[], size_t size);

    static void HeapSort(int container[], size_t size);

    //quick sort
    template<size_t n>
    static void QuickSort(std::array<int, n> &container, int front, int back);

    template<size_t n>
    static size_t ParTition(std::array<int, n> &container, int front, int back);
};

template<size_t n>
void Sort::PopSort(std::array<int, n> &container) {
    for (int i = 1; i < n; ++i) {
        bool isChange = false;
        for (int j = 1; j < n - i + 1; ++j) {
            if (container[j] < container[j - 1]) {
                std::swap(container[j], container[j - 1]);
                isChange = true;
            }
        }
        if (!isChange) {
            break;
        }
    }
}

template<size_t n>
void Sort::InsertSort(std::array<int, n> &container) {
    for (int i = 1; i < n; ++i) {
        int temp = container[i];
        int j = i - 1;
        while (j >= 0 && container[j] > temp) {
            container[j + 1] = container[j];
            --j;
        }
        container[j + 1] = temp;
    }
}

template<size_t n>
void Sort::MergeSort(std::array<int, n> &container, int head, int tail) {
    int mid = head + (tail - head >> 1);
    if (head < tail) {
        MergeSort(container, head, mid);
        MergeSort(container, mid + 1, tail);
        Merge(container, head, mid, tail);
    }
}

template<size_t n>
void Sort::Merge(std::array<int, n> &container, int head, int mid, int tail) {
    int size1 = mid - head + 1;
    int size2 = tail - mid;
    int array1[size1 + 1];
    int array2[size2 + 1];

    for (int i = 0; i < size1; ++i) {
        array1[i] = container[head + i];
    }
    array1[size1] = INT32_MAX;

    for (int i = 0; i < size2; ++i) {
        array2[i] = container[mid + i + 1];
    }
    array2[size2] = INT32_MAX;

    int index1 = 0;
    int index2 = 0;
    for (int i = head; i <= tail; ++i) {
        if (array1[index1] < array2[index2]) {
            container[i] = array1[index1++];
        } else {
            container[i] = array2[index2++];
        }
    }
}

void Sort::Heapify(int *container, size_t size, int pos) {
    int left = pos * 2 + 1;
    int right = pos * 2 + 2;
    int maxIndex = pos;

    if (left < size && container[left] > container[maxIndex]) {
        maxIndex = left;
    }
    if (right < size && container[right] > container[maxIndex]) {
        maxIndex = right;
    }
    if (maxIndex == pos) {
        return;
    }

    std::swap(container[maxIndex], container[pos]);
    Heapify(container, size, maxIndex);
}

void Sort::BuildHeap(int *container, size_t size) {
    for (int i = (size - 2) / 2; i >= 0; --i) {
        Heapify(container, size, i);
    }
}

void Sort::HeapSort(int *container, size_t size) {
    BuildHeap(container, size);
    for (int i = size - 1; i > 0; --i) {
        std::swap(container[0], container[i]);
        Heapify(container, i, 0);
    }
}

template<size_t n>
size_t Sort::ParTition(std::array<int, n> &container, int front, int back) {
    int sentry = container[back];
    while (front < back) {
        while (front < back && container[front] < sentry) {
            ++front;
        }
        container[back] = container[front];
        while (back > front && container[back] > sentry) {
            --back;
        }
        container[front] = container[back]
    }
    container[back] = sentry;
    return back;
}

template<size_t n>
void Sort::QuickSort(std::array<int, n> &container, int front, int back) {
    size_t partition = ParTition(container, front, back);
    QuickSort(container, front, partition-1);
    QuickSort(container,partition+1, back);
}


#endif //SORT_SORT_HPP
