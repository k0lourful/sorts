#pragma once
class DynArray {
private:
	int *arr;
	int len;

public:
	DynArray();
	explicit DynArray(const int &len);
	DynArray(DynArray& copy);
	~DynArray();

	void allocateMemory(const int &len);
	int getLength() const;
	void setValue(const int &ind, const int &val);
	int getValue(const int &ind) const;
	void randomise(const int& min, const int& max);
	void randomiseDifferentValues();
	void clear();

	void insertionSort();
	void shellSort();
    void quickSort(const int& min, const int& max);
    void countingSort();
};