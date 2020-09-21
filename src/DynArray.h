#pragma once
class DynArray {
private:
	int *arr;
	int len;

public:
	DynArray();
	DynArray(const int &len);
	~DynArray();
	void allocateMemory(const int &len);
	int getLength() const;
	void setValue(const int &ind, const int &val);
	int getValue(const int &ind) const;
	void randomise();
	void insertionSort();
	void shellSort();
};