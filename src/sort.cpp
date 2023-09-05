#include <iostream>
#include <chrono>
#include <cstring>
#include "sort/sort.hpp"
#include "sort/utils.hpp"

namespace sort{
	void insertSort(float* A, int n){
		for (int i=1; i<n; i++){
			float elem = A[i];
			int j = i-1;
		
			while (j >= 0 && A[j] > elem){
				A[j+1] = A[j];
				j--;
			}

			A[j+1] = elem;
		}
	}

	void merge(float* A, int left, int middle, int right) {
		int n1 = middle - left + 1;
		int n2 = right - middle;

		// Crear arreglos temporales para almacenar los subarreglos
		float* leftArr = new float[n1];
		float* rightArr = new float[n2];

		// Copiar datos a los arreglos temporales leftArr[] y rightArr[]
		for (int i = 0; i < n1; i++) {
			leftArr[i] = A[left + i];
		}
		for (int i = 0; i < n2; i++) {
			rightArr[i] = A[middle + 1 + i];
		}

		// Fusionar los arreglos temporales de nuevo en arr[left...right]
		int i = 0, j = 0, k = left;
		while (i < n1 && j < n2) {
			if (leftArr[i] <= rightArr[j]) {
				A[k] = leftArr[i];
				i++;
			} else {
				A[k] = rightArr[j];
				j++;
			}
			k++;
		}

		// Copiar los elementos restantes de leftArr[], si los hay
		while (i < n1) {
			A[k] = leftArr[i];
			i++;
			k++;
		}

		// Copiar los elementos restantes de rightArr[], si los hay
		while (j < n2) {
			A[k] = rightArr[j];
			j++;
			k++;
		}

		// Liberar la memoria de los arreglos temporales
		delete[] leftArr;
		delete[] rightArr;
	}

	void mergeSort(float* A, int left, int right) {
		if (left < right) {
			// Encuentra el punto medio del arreglo
			int middle = left + (right - left) / 2;

			// Ordena la primera mitad
			mergeSort(A, left, middle);

			// Ordena la segunda mitad
			mergeSort(A, middle + 1, right);

			// Fusiona las dos mitades ordenadas
			merge(A, left, middle, right);
		}
	}

	int split_qs(float* A, int i, int j){
		/***
		 * split for quicksort
		 * i,j are the endpoints
		 */
		int p = getRandomInt(i, j);

		while (i  < j) {

			while ( i < p && A[i] <= A[p]){
				i = i + 1;
			}

			while ( j > p && A[j] >= A[p]){
				j = j - 1;
			}

			swap(A, i, j);

			if (i == p){
				p = j;
			}
			else if (j == p){
				p = i;
			}
		}
		return p;
	}

	void quickSort(float* A, int i, int j){
		if (i < j){
			int k = split_qs(A, i, j);
			quickSort(A, i, k-1);
			quickSort(A, k + 1, j);
		}
	}

	void quickSort(float* A, int n){
		quickSort(A, 0, n - 1);
	}

	float findMax(float* arr, int n) {
		float max = arr[0];
		for (int i = 1; i < n; i++) {
			if (arr[i] > max) {
				max = arr[i];
			}
		}
		return max;
	}

	void countingSort(float* arr, int n, int exp) {
		const int radix = 10;
		float output[n];
		int count[radix] = {0};

		for (int i = 0; i < n; i++) {
			int index = static_cast<int>(arr[i] / exp) % radix;
			count[index]++;
		}

		for (int i = 1; i < radix; i++) {
			count[i] += count[i - 1];
		}

		for (int i = n - 1; i >= 0; i--) {
			int index = static_cast<int>(arr[i] / exp) % radix;
			output[count[index] - 1] = arr[i];
			count[index]--;
		}

		for (int i = 0; i < n; i++) {
			arr[i] = output[i];
		}
	}

	void radixSort(float* arr, int n) {
		float max = findMax(arr, n);

		for (int exp = 1; max / exp > 0.1; exp *= 10) {
			countingSort(arr, n, exp);
		}
	}

	double insertTime(float* A, int n) {
		float* copiaA = new float[n];

		std::memcpy(copiaA, A, sizeof(float) * n);

		auto start = std::chrono::high_resolution_clock::now();
		sort::insertSort(copiaA, n);
		auto end = std::chrono::high_resolution_clock::now();
		
		std::chrono::duration<double> duration = end - start;
		
		double tiempoEnMilisegundos = duration.count() * 1000.0;
		delete[] copiaA;
		return tiempoEnMilisegundos;
	}

	double mergeTime(float* A, int n) {
		float* copiaA = new float[n];

		std::memcpy(copiaA, A, sizeof(float) * n);

		auto start = std::chrono::high_resolution_clock::now();
		sort::mergeSort(copiaA, 0, n - 1);
		auto end = std::chrono::high_resolution_clock::now();
		
		std::chrono::duration<double> duration = end - start;
		
		double tiempoEnMilisegundos = duration.count() * 1000.0;
		delete[] copiaA;
		return tiempoEnMilisegundos;
	}

	double quickTime(float* A, int n) {
		float* copiaA = new float[n];

		std::memcpy(copiaA, A, sizeof(float) * n);

		auto start = std::chrono::high_resolution_clock::now();
		sort::quickSort(copiaA, n);
		auto end = std::chrono::high_resolution_clock::now();
		
		std::chrono::duration<double> duration = end - start;
		
		double tiempoEnMilisegundos = duration.count() * 1000.0;
		delete[] copiaA;
		return tiempoEnMilisegundos;
	}

	double radixTime(float* A, int n) {
		float* copiaA = new float[n];

		std::memcpy(copiaA, A, sizeof(float) * n);

		auto start = std::chrono::high_resolution_clock::now();
		sort::radixSort(copiaA, n);
		auto end = std::chrono::high_resolution_clock::now();
		
		std::chrono::duration<double> duration = end - start;
		
		double tiempoEnMilisegundos = duration.count() * 1000.0;
		delete[] copiaA;
		return tiempoEnMilisegundos;
	}
}

