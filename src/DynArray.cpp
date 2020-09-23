#include "DynArray.h"
#include <random>
#include <chrono>

DynArray::DynArray() : arr(nullptr), len(0) {}

DynArray::DynArray(const int &size) : len(size) {
    arr = new int[size];
}

DynArray::~DynArray() {
    delete[] arr;
    len = 0;
}

void DynArray::allocateMemory(const int &size) {
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
//		return INT_MAX;
        return INT32_MAX;
    return arr[ind];
}

void DynArray::randomise() {
    for (int i = 0; i < len; ++i) {
        arr[i] = i + 1;
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(arr, arr + len, std::default_random_engine(seed));
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
    //for (int d = len / 2; d > 0; d /= 2) {
    //	for (int i = d; i < len; ++i) {
    //		for (int j = i - d; j >= 0 && getValue(j) > getValue(j + d); j -= d) {
    //			int tmp = getValue(j);
    //			setValue(j, getValue(j + d));
    //			setValue(j + d, tmp);
    //		}
    //	}
    //}
    for (int i = 0; i < len; ++i) {
        for (int j = i; j < len; ++j) {
            int k, tmp = arr[j];
            for (k = j; k >= i && arr[k - i] > tmp; k -= i)
                arr[k] = arr[k - i];
            arr[k] = tmp;
        }
    }
}
