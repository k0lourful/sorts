#include "DynArray.h"
#include <random>
#include <chrono>
#include <fstream>

DynArray::DynArray() : arr(nullptr), len(0) {}

DynArray::DynArray(const int &size) : len(size) {
    arr = new int[size];
}

DynArray::DynArray(DynArray &copy) : len(copy.len) {
    arr = new int[len];
    std::copy(copy.arr, copy.arr + len, arr);
}

DynArray::~DynArray() {
    delete[] arr;
    len = 0;
}

void DynArray::allocateMemory(const int &size) {
    if (len) delete[] arr;
    len = size;
    arr = new int[size];
}

int DynArray::getLength() const { return len; }

void DynArray::setValue(const int &ind, const int &val) {
    if (ind < 0 || ind >= len)
        return;
    arr[ind] = val;
}

int DynArray::getValue(const int &ind) const {
    if (ind < 0 || ind >= len)
        return INT32_MAX;
    return arr[ind];
}

void DynArray::randomise(const int &min, const int &max) {
    // C++11 methods of rng
    std::random_device dev;
    std::mt19937 engine(dev());
    std::uniform_int_distribution<int> uid(min, max);
    for (int i = 0; i < len; ++i)
        arr[i] = uid(engine);
}

void DynArray::randomiseDifferentValues() {
    for (int i = 0; i < len; ++i)
        arr[i] = i;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(arr, arr + len, std::default_random_engine(seed));
}

void DynArray::clear() {
    delete[] arr;
    len = 0;
}

void DynArray::save(const char* fileName){
    std::fstream file(fileName, std::ios::out);
    while(file.fail())
        file.open(fileName, std::ios::out);

    for(int i = 0; i < len; ++i)
        file << arr[i] << " ";
    file.close();
}

void DynArray::insertionSort() {
    for (int i = 1; i < len; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void DynArray::shellSort() {
    int i;
    for (i = 1; 3 * i + 1 <= len / 9; ++i);
    int *h = new int[i];
    for (int j = 0; j < i; ++j)
        h[j] = 3 * j + 1;

    for (--i; i >= 0; --i) {
        for (int j = h[i]; j < len; ++j) {
            int k = j, v = arr[j];
            while (k >= h[i] && v < arr[k - h[i]]) {
                arr[k] = arr[k - h[i]];
                k -= h[i];
            }
            arr[k] = v;
        }
    }

    delete[] h;
}

void DynArray::quickSort(const int &min, const int &max) {
    if (min >= max) return;

    int medVal = arr[min];
    int lo = min, hi = max;

    while (true) {
        while (arr[hi] >= medVal) {
            --hi;
            if (hi <= lo)break;
        }
        if (hi <= lo) {
            arr[lo] = medVal;
            break;
        }
        arr[lo] = arr[hi];

        ++lo;
        while (arr[lo] < medVal) {
            ++lo;
            if (lo >= hi) break;
        }
        if (lo >= hi) {
            lo = hi;
            arr[hi] = medVal;
            break;
        }
        arr[hi] = arr[lo];
    }

    quickSort(min, lo - 1);
    quickSort(lo + 1, max);
}

void DynArray::countingSort() {
    int min = arr[0], max = arr[0];
    for (int i = 0; i < len; ++i) {
        if (min > arr[i]) min = arr[i];
        if (max < arr[i]) max = arr[i];
    }

    int *counts = new int[max - min + 1];

    for (int i = 0; i <= max - min; ++i)
        counts[i] = 0;

    for (int i = 0; i < len; ++i)
        ++counts[arr[i] - min];

    for (int i = 0, k = 0; i <= max - min; ++i)
        for (int j = 0; j < counts[i]; ++j)
            arr[k++] = i + min;
    delete[] counts;
}
