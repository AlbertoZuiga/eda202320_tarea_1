#ifndef SORT_UTILS_HPP
#define SORT_UTILS_HPP
#include <string>
namespace sort{
	float* createArray(int n);
	float* createRandomArray(int n);
	float* createRandomIntArray(int n, int minVal = 0, int maxVal = 100);
	void deleteArray(float* A);
	void printArray(float* A, int n);
	void setAll(float* A, int n, float value);
	void swap(float* A, int i, int j);
	int getRandomInt(int min, int max);
	int* linspace(int max, int n_parts);
	float* open_file(const std::string& nombreArchivo, int& tamano);
	bool save_file(const std::string& nombreArchivo, float* A, int tamano);
}

#endif
