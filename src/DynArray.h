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

	bool isSorted();
	void allocateMemory(const int &len);
	int getLength() const;
	void setValue(const int &ind, const int &val);
	int getValue(const int &ind) const;
	void randomise(const int& min, const int& max);
	void randomiseDifferentValues();
	void clear();
	void save(const char* fileName);

	void insertionSort();
	void shellSort();
    void quickSort(const int& min, const int& max);
    void countingSort();

    int interpolationSearch(const int& target, int min, int max);
    int interpolativeHuntAndSearch(const int& target1, const int& target2);
};