#pragma once

#include <iostream>
#include "ExternalSort.h"
#include "DynArray.h"
#include "clearScreen.h"

void choice(const int &c, DynArray &arr) {
    clearScreen();

    switch (c) {
        case 0: {
            const int size = arr.getLength();
            if (size < 1)
                std::cout << "Array is empty\n\n";
            else {
                for (int i = 0; i < size; ++i)
                    std::cout << arr.getValue(i) << " ";
                std::cout << "\n\n";
            }
            break;
        }

        case 1: {
            if (arr.getLength() != 0)
                arr.clear();

            int size, value;
            std::cout << "Enter array size: ";
            std::cin >> size;
            while (size < 1) {
                std::cout << "Invalid array size, try again: ";
                std::cin >> size;
            }

            arr.allocateMemory(size);
            std::cout << "Enter values: \n";
            for (int i = 0; i < size; ++i) {
                std::cin >> value;
                arr.setValue(i, value);
            }

            std::cout << "Created array.\n\n";
            break;
        }

        case 2: {
            if (arr.getLength() != 0)
                arr.clear();

            int size, min, max;
            std::cout << "Enter array size: ";
            std::cin >> size;
            while (size < 1) {
                std::cout << "Invalid array size, try again: ";
                std::cin >> size;
            }

            arr.allocateMemory(size);

            std::cout << "Enter random numbers range: ";
            std::cin >> min >> max;
            arr.randomise(min, max);

            std::cout << "Created random array.\n\n";
            break;
        }

        case 3: {
            if (arr.getLength() != 0)
                arr.clear();

            int size;
            std::cout << "Enter array size: ";
            std::cin >> size;
            while (size < 1) {
                std::cout << "Invalid array size, try again: ";
                std::cin >> size;
            }

            arr.allocateMemory(size);
            arr.randomiseDifferentValues();

            std::cout << "Created random array.\n\n";
            break;
        }

        case 4: {
            if (!arr.getLength())
                std::cout << "Array is empty.\n\n";
            else {
                arr.insertionSort();
                std::cout << "Sorted array.\n\n";
            }
            break;
        }

        case 5: {
            if (!arr.getLength())
                std::cout << "Array is empty.\n\n";
            else {
                arr.shellSort();
                std::cout << "Sorted array.\n\n";
            }
            break;
        }

        case 6: {
            const int size = arr.getLength();

            if (!size)
                std::cout << "Array is empty.\n\n";
            else {
                arr.quickSort(0, size - 1);
                std::cout << "Sorted array.\n\n";
            }
            break;
        }

        case 7: {
            if (!arr.getLength())
                std::cout << "Array is empty.\n\n";
            else {
                arr.countingSort();
                std::cout << "Sorted array.\n\n";
            }
            break;
        }

        case 8: {
            const int size = arr.getLength();
            if (!size)
                std::cout << "Array is empty.\n\n";
            else {
                DynArray a1(arr), a2(arr), a3(arr);

                std::ofstream out("times.txt");
                while (out.fail()) {
                    std::cout << "File didn't open, give me just a bit\n";
                    out.open("times.txt");
                }

                clock_t time = clock();
                arr.insertionSort();
                time = clock() - time;
                out << "Insertion sort: " << (double) time / CLOCKS_PER_SEC << "\n";

                time = clock();
                a1.shellSort();
                time = clock() - time;
                out << "Shell sort: " << (double) time / CLOCKS_PER_SEC << "\n";

                time = clock();
                a2.quickSort(0, size - 1);
                time = clock() - time;
                out << "Quick sort: " << (double) time / CLOCKS_PER_SEC << "\n";

                time = clock();
                a3.countingSort();
                time = clock() - time;
                out << "Counting sort: " << (double) time / CLOCKS_PER_SEC << "\n";

                out.close();
                std::cout << "Times saved.\n\n";
            }
            break;
        }

        case 9: {
            arr.save("arr.txt");
            std::ofstream out("times_external.txt");
            while (out.fail()) {
                std::cout << "File didn't open, give me just a bit\n";
                out.open("times_external.txt");
            }

            clock_t time = clock();
            int k = naturalSort("arr.txt");
            time = clock() - time;
            if (k == -1) {
                out << "File not found.\n";
                std::cout << "File not found.\n";
            } else {
                out << "Natural sort: " << (double) time / CLOCKS_PER_SEC << "; loops: " << k << "\n";
                std::cout << "Array sorted in " << k << " loops.\n\n";
            }

            out.close();
            std::cout << "Times saved.\n\n";

            break;
        }

        default:
            std::cout << "Invalid input, try again.\n\n";
            break;
    }
}

void menu(DynArray &arr) {
    short int c;
    while (true) {
        std::cout << "Options:\n\n";
        std::cout << "0. Print array\n";
        std::cout << "1. Enter array\n";
        std::cout << "2. Create random array\n";
        std::cout << "3. Create random array with different numbers\n";
        std::cout << "4. Sort array using insertion sort\n";
        std::cout << "5. Sort array using Shell sort\n";
        std::cout << "6. Sort array using quick sort\n";
        std::cout << "7. Sort array using counting sort\n";
        std::cout << "8. Get all sortings times\n";
        std::cout << "9. Sort array in arr.txt using natural sort (external), get time\n";

        std::cin >> c;

        choice(c, arr);
    }
}
