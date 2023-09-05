#include "sort/sort.hpp"
#include "sort/utils.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc == 2 && string(argv[1]) == "tiempo_ejecucion") {
        string files[] = {"ruts_100.txt", "ruts_1000.txt", "ruts_10000.txt", "ruts_50000.txt", "ruts_100000.txt", "ruts_500000.txt", "ruts_1000000.txt", "ruts_10000000.txt", "ruts_50000000.txt", "ruts_100000000.txt"};        
        int numFiles = sizeof(files) / sizeof(files[0]);

        int n;
        float* A;
        double x;

        cout << "Archivo |\tInsertSort |\tMergeSort |\tQuickSort |\tRadixSort" << endl;
        cout << "------------------------------------------------------------" << endl;
        for (int i = 0; i < numFiles; ++i) {
            cout << files[0] << " |\t";
            A = sort::open_file(files[i], n);
            x = sort::insertTime(A, n);
            cout << x << " |\t";
            x = sort::mergeTime(A, n);
            cout << x << " |\t";
            x = sort::quickTime(A, n);
            cout << x << " |\t";
            x = sort::radixTime(A, n);
            cout << x << endl;
            delete[] A;
        }
        cout << "------------------------------------------------------------" << endl;
        return 0;
    }

    if (argc != 3) {
        cerr << "Error: faltan argumentos" << endl;
        return 1;
    }

    string nombreArchivo = argv[1];
    char caracter = argv[2][0];

    int tamano;
    float* arreglo = sort::open_file(nombreArchivo, tamano);

    if (!arreglo) {
        cerr << "Error: el archivo '" << nombreArchivo << "' no existe o no se encuentra en la ruta especificada" << endl;
        delete[] arreglo;
        return 2;
    }

    switch (caracter) {
        case 'I':
            cout << "Ordenado con: InsertSort" << endl;
            sort::insertSort(arreglo, tamano); // Ordena el arreglo con InsertSort
            break;
        case 'M':
            cout << "Ordenado con: MergeSort" << endl;
            sort::mergeSort(arreglo, 0, tamano - 1); // Ordena el arreglo con MergeSort
            break;
        case 'Q':
            cout << "Ordenado con: QuickSort" << endl;
            sort::quickSort(arreglo, tamano); // Ordena el arreglo con QuickSort
            break;
        case 'R':
            cout << "Ordenado con: RadixSort" << endl;
            sort::radixSort(arreglo, tamano); // Ordena el arreglo con RadixSort
            break;
        default:
            cerr << "Error: Carácter no permitido. Debe ser I, M, Q, o R." << endl;
            delete[] arreglo;
            return 3;
    }

    if (sort::save_file(nombreArchivo, arreglo, tamano)) {
        cout << "Archivo generado: " << nombreArchivo << ".sorted" << endl;
    } else {
        cerr << "Error al guardar el archivo ordenado." << endl;
    }

    delete[] arreglo;
    return 0;
}
