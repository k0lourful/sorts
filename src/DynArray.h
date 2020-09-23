#pragma once
class DynArray {
private:
	int *arr;
	int len;

public:
	DynArray();
	explicit DynArray(const int &len);
	~DynArray();

	void allocateMemory(const int &len);
	[[nodiscard]] int getLength() const;
	void setValue(const int &ind, const int &val);
	[[nodiscard]] int getValue(const int &ind) const;
	void randomise();
	void insertionSort();
	void shellSort();
};