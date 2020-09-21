#include <iostream>
#include "DynArray.h"

int main() {
	DynArray a(6);
	int in;

	for (int i = 0; i < 6; ++i) {
		std::cin >> in;
		a.setValue(i, in);
	}
	a.shellSort();
	for (int i = 0; i < 6; ++i)
		std::cout << a.getValue(i) << " ";

	return 0;
}