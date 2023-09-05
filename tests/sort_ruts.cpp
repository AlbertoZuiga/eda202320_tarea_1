#include "sort/sort.hpp"
#include "sort/utils.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    if (argc == 2 && std::string(argv[1]) == "tiempo_ejecucion") {
        std::string files[] = {"ruts_100.txt", "ruts_1000.txt", "ruts_10000.txt", "ruts_50000.txt", "ruts_100000.txt", "ruts_500000.txt", "ruts_1000000.txt", "ruts_10000000.txt", "ruts_50000000.txt", "ruts_100000000.txt"};        
        int numFiles = sizeof(files) / sizeof(files[0]);

        int n;
        float* A;

        for (int i = 0; i < numFiles; ++i) {
            A = sort::open_file(files[i], n);
            double x = sort::insertTime(A, n);
            std::cout << "Insert: "<< x << std::endl;
            x = sort::mergeTime(A, n);
            std::cout << "Merge: "<< x << std::endl;
            x = sort::quickTime(A, n);
            std::cout << "Quick: "<< x << std::endl;
            x = sort::radixTime(A, n);
            std::cout << "Radix: "<< x << std::endl;
            delete[] A;
        }

        return 6;
    }

    if (argc != 3) {
        std::cerr << "Error: faltan argumentos" << std::endl;
        return 1;
    }

    std::string nombreArchivo = argv[1];
    char caracter = argv[2][0];

    int tamano;
    float* arreglo = sort::open_file(nombreArchivo, tamano);

    if (!arreglo) {
        std::cerr << "Error: el archivo '" << nombreArchivo << "' no existe o no se encuentra en la ruta especificada" << std::endl;
        delete[] arreglo;
        return 2;
    }

    switch (caracter) {
        case 'I':
            std::cout << "Ordenado con: InsertSort" << std::endl;
            sort::insertSort(arreglo, tamano); // Ordena el arreglo con InsertSort
            break;
        case 'M':
            std::cout << "Ordenado con: MergeSort" << std::endl;
            sort::mergeSort(arreglo, 0, tamano - 1); // Ordena el arreglo con MergeSort
            break;
        case 'Q':
            std::cout << "Ordenado con: QuickSort" << std::endl;
            sort::quickSort(arreglo, tamano); // Ordena el arreglo con QuickSort
            break;
        case 'R':
            std::cout << "Ordenado con: RadixSort" << std::endl;
            sort::radixSort(arreglo, tamano); // Ordena el arreglo con RadixSort
            break;
        default:
            std::cerr << "Error: Carácter no permitido. Debe ser I, M, Q, o R." << std::endl;
            delete[] arreglo;
            return 3;
    }

    if (sort::save_file(nombreArchivo, arreglo, tamano)) {
        std::cout << "Archivo generado: " << nombreArchivo << ".sorted" << std::endl;
    } else {
        std::cerr << "Error al guardar el archivo ordenado." << std::endl;
    }

    delete[] arreglo;
    return 0;
}
