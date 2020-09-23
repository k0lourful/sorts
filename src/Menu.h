#pragma once

#include <iostream>
#include "DynArray.h"
#include "clearScreen.h"

void choice(const int &c, DynArray &arr) {
    clearScreen();

    switch (c) {
        case 0: {
            int size = arr.getLength();
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
            if(arr.getLength() != 0)
                arr.clear();

            int size, value;
            std::cout << "Enter array size: ";
            std::cin >> size;
            while(size < 1) {
                std::cout << "Invalid array size, try again: ";
                std::cin >> size;
            }

            arr.allocateMemory(size);
            std::cout << "Enter values: \n";
            for(int i = 0; i < size; ++i){
                std::cin >> value;
                arr.setValue(i, value);
            }

            std::cout << "Created array.\n\n";
            break;
        }

        case 2: {
            if(arr.getLength() != 0)
                arr.clear();

            int size;
            std::cout << "Enter array size: ";
            std::cin >> size;
            while(size < 1) {
                std::cout << "Invalid array size, try again: ";
                std::cin >> size;
            }

            arr.allocateMemory(size);
            arr.randomise();

            std::cout << "Created random array.\n\n";
            break;
        }

        case 3: {
            if(!arr.getLength())
                std::cout << "Array is empty.\n\n";
            else{
                arr.insertionSort();
                std::cout << "Sorted array.\n\n";
            }
            break;
        }

        case 4: {
            if(!arr.getLength())
                std::cout << "Array is empty.\n\n";
            else{
                arr.shellSort();
                std::cout << "Sorted array.\n\n";
            }
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
        std::cout << "3. Sort array using insertion sort\n";
        std::cout << "4. Sort array using Shell sort\n";

        std::cin >> c;

        choice(c, arr);
    }
}
