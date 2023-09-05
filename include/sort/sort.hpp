#ifndef SORT_SORT_HPP
#define SORT_SORT_HPP

namespace sort {
	void insertSort(float* A, int n);
	void merge(float* A, int left, int middle, int right);
	void mergeSort(float* A, int left, int right);
	int split_qs(float* A, int i, int j);
	void quickSort(float* A, int i, int j);
	void quickSort(float* A, int n);
	float findMax(float* arr, int n);
	void countingSort(float* arr, int n, int exp);
	void radixSort(float* arr, int n);
	double insertTime(float* A, int n);
	double mergeTime(float* A, int n);
	double quickTime(float* A, int n);
	double radixTime(float* A, int n);
}

#endif