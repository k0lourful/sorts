#include <iostream>
#include "DynArray.h"

int main() {
	DynArray a(6);
//	int in;

//	for (int i = 0; i < 6; ++i) {
//		std::cin >> in;
//		a.setValue(i, in);
//	}
	a.randomise();
    for (int i = 0; i < 6; ++i)
        std::cout << a.getValue(i) << " ";
    std::cout << std::endl;
	a.shellSort();
	for (int i = 0; i < 6; ++i)
		std::cout << a.getValue(i) << " ";

	return 0;
}