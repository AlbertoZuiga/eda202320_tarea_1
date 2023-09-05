#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>

#include "sort/utils.hpp"

namespace sort{
	float* createArray(int n){
		return new float[n];
	}

	float* createRandomArray(int n){
		float* A = createArray(n);
		for (int i = 0; i < n; i++){
			A[i] =  std::rand() / static_cast<float>(RAND_MAX);
		}
		return A;
	}

	float* createRandomIntArray(int n, int minVal, int maxVal){
		float* A = createArray(n);
		for (int i = 0; i < n; i++){
			A[i] = getRandomInt(minVal, maxVal);
		}
		return A;
	}

	void deleteArray(float* A){
		delete[] A;
	}

	void printArray(float* A, int n){
		for (int i = 0; i < n; i++){
			std::cout<<A[i]<<" ";
		}
		std::cout<<std::endl;
	}

	void setAll(float* A, int n, float value){
		for (int i = 0; i < n; i++){
			A[i] =  value;
		}
	}

	void swap(float* A, int i, int j){
		float aux = A[i];
		A[i] = A[j];
		A[j] = aux;
	}

	int getRandomInt(int min, int max){
		float a = rand() / static_cast<float>(RAND_MAX);
		return static_cast<int>(a * (max - min) + min + 0.5);
	}

	int* linspace(int max, int n_parts){
		int* V = new int[n_parts];
		int part_size = max / n_parts;
		for(int i = 1; i <= n_parts; i++){
			V[i - 1] = part_size * i;
		}
		return V;
	}

	float* open_file(const std::string& nombreArchivo, int& tamano) {
		std::string rutaArchivo = "../datos/" + nombreArchivo;
		std::ifstream archivo(rutaArchivo);

		if (!archivo) {
			return nullptr;
		}

		std::vector<float> valores;
		float valor;

		while (archivo >> valor) {
			valores.push_back(valor);
		}

		archivo.close();

		tamano = valores.size();

		float* A = new float[tamano];
		for (int i = 0; i < tamano; i++) {
			A[i] = valores[i];
		}

		return A;
	}

	bool save_file(const std::string& nombreArchivo, float* A, int tamano) {
		std::string rutaArchivo = "../datos_sorted/" + nombreArchivo + ".sorted";
		std::ofstream archivo(rutaArchivo);

		if (!archivo) {
			std::cerr << "No se pudo crear el archivo." << std::endl;
			return false;
		}

		for (int i = 0; i < tamano; i++) {
			int numeroEntero = static_cast<int>(A[i]);
			archivo << numeroEntero << "\n";
		}

		archivo.close();
		return true; // Retorna true si se escribió con éxito
	}
}