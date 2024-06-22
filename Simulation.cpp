#include "Simulation.h"
#include <iostream>
#include "Algorithm.h"
#include "Table.h"
#include <filesystem>
#include <chrono>
#include <functional>

using namespace std;
namespace fs = filesystem;

void Simulation::simulation() {
    string filename;

    Algorithm<int> intAlgorithm;
    Algorithm<float> floatAlgorithm;
    Algorithm<char> charAlgorithm;

    //Wektor funckji dla int
    vector<function<void(int* tab, int, const string&)>> sortingAlgorithmsint = {
            [&](int* arr, int size, const string& filename) {
                intAlgorithm.insertionSort(arr, filename);
            },
            [&](int* arr, int size, const string& filename) {
                intAlgorithm.insertionSortBin(arr, filename);
            },
            [&](int* arr, int size, const string& filename) {
                intAlgorithm.heapSort(arr, filename);
            },
            [&](int* arr, int size, const string& filename) {
                auto start = chrono::high_resolution_clock::now();
                intAlgorithm.quickSort(arr, 0, size - 1, filename);
                auto end = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed = end - start;
                intAlgorithm.saveResult(elapsed.count(), filename);
            }
    };

    //Wektor funckji dla float
    vector<function<void(float*, int, const string&)>> sortingAlgorithmsfloat = {
            [&](float* arr, int size, const string& filename) {
                floatAlgorithm.insertionSort(arr, filename);
            },
            [&](float* arr, int size, const string& filename) {
                floatAlgorithm.insertionSortBin(arr, filename);
            },
            [&](float* arr, int size, const string& filename) {
                floatAlgorithm.heapSort(arr, filename);
            },
            [&](float* arr, int size, const string& filename) {
                auto start = chrono::high_resolution_clock::now();
                floatAlgorithm.quickSort(arr, 0, size - 1, filename);
                auto end = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed = end - start;
                floatAlgorithm.saveResult(elapsed.count(), filename);
            }
    };

    //Wektor funckji dla char
    vector<function<void(char*, int, const string&)>> sortingAlgorithmschar = {
            [&](char* arr, int size, const string& filename) {
                charAlgorithm.insertionSort(arr, filename);
            },
            [&](char* arr, int size, const string& filename) {
                charAlgorithm.insertionSortBin(arr, filename);
            },
            [&](char* arr, int size, const string& filename) {
                charAlgorithm.heapSort(arr, filename);
            },
            [&](char* arr, int size, const string& filename) {
                auto start = chrono::high_resolution_clock::now();
                charAlgorithm.quickSort(arr, 0, size - 1, filename);
                auto end = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed = end - start;
                charAlgorithm.saveResult(elapsed.count(), filename);
            }
    };

    for (int size : {10000, 20000, 30000, 40000, 50000, 60000, 70000}) {

        for (int i = 0; i < 100; ++i) {
            intAlgorithm.initialize(Table<int>::generateIntArray(size));


            filename = fs::current_path().string() + "\\Files\\int_" + to_string(size) + "k_" + "iS" + ".txt";
            sortingAlgorithmsint[0](intAlgorithm.tab, size, filename);

            filename = fs::current_path().string() + "\\Files\\int_" + to_string(size) + "k_" + "iSB" + ".txt";
            sortingAlgorithmsint[1](intAlgorithm.tab1, size, filename);

            filename = fs::current_path().string() + "\\Files\\int_" + to_string(size) + "k_" + "hS" + ".txt";
            sortingAlgorithmsint[2](intAlgorithm.tab2, size, filename);

            filename = fs::current_path().string() + "\\Files\\int_" + to_string(size) + "k_" + "qS" + ".txt";
            sortingAlgorithmsint[1](intAlgorithm.tab3, size, filename);

        }

        for (int i = 0; i < 100; ++i) {
            floatAlgorithm.initialize(Table<float>::generateFloatArray(size));


            filename = fs::current_path().string() + "\\Files\\float_" + to_string(size) + "k_" + "iS" + ".txt";
            sortingAlgorithmsfloat[0](floatAlgorithm.tab, size, filename);

            filename = fs::current_path().string() + "\\Files\\float_" + to_string(size) + "k_" + "iSB" + ".txt";
            sortingAlgorithmsfloat[1](floatAlgorithm.tab1, size, filename);

            filename = fs::current_path().string() + "\\Files\\float_" + to_string(size) + "k_" + "hS" + ".txt";
            sortingAlgorithmsfloat[2](floatAlgorithm.tab2, size, filename);

            filename = fs::current_path().string() + "\\Files\\float_" + to_string(size) + "k_" + "qS" + ".txt";
            sortingAlgorithmsfloat[3](floatAlgorithm.tab3, size, filename);

        }

        for (int i = 0; i < 100; ++i) {
            charAlgorithm.initialize(Table<char>::generateCharArray(size));


            filename = fs::current_path().string() + "\\Files\\char_" + to_string(size) + "k_" + "iS" + ".txt";
            sortingAlgorithmschar[0](charAlgorithm.tab, size, filename);

            filename = fs::current_path().string() + "\\Files\\char_" + to_string(size) + "k_" + "iSB" + ".txt";
            sortingAlgorithmschar[1](charAlgorithm.tab1, size, filename);

            filename = fs::current_path().string() + "\\Files\\char_" + to_string(size) + "k_" + "hS" + ".txt";
            sortingAlgorithmschar[2](charAlgorithm.tab2, size, filename);

            filename = fs::current_path().string() + "\\Files\\char_" + to_string(size) + "k_" + "qS" + ".txt";
            sortingAlgorithmschar[3](charAlgorithm.tab3, size, filename);
        }



        for (int i = 0; i < 100; ++i) {
            intAlgorithm.initialize(Table<int>::generateSorted(size));


            filename = fs::current_path().string() + "\\Files\\int_" + to_string(size) + "k_" + "iSSorted" + ".txt";
            sortingAlgorithmsint[0](intAlgorithm.tab, size, filename);

            filename = fs::current_path().string() + "\\Files\\int_" + to_string(size) + "k_" + "iSBSorted" + ".txt";
            sortingAlgorithmsint[1](intAlgorithm.tab1, size, filename);

            filename = fs::current_path().string() + "\\Files\\int_" + to_string(size) + "k_" + "hSSorted" + ".txt";
            sortingAlgorithmsint[2](intAlgorithm.tab2, size, filename);

            filename = fs::current_path().string() + "\\Files\\int_" + to_string(size) + "k_" + "qSSorted" + ".txt";
            sortingAlgorithmsint[1](intAlgorithm.tab3, size, filename);

        }
        for (int i = 0; i < 100; ++i) {
            intAlgorithm.initialize(Table<int>::generateReverse(size));


            filename = fs::current_path().string() + "\\Files\\int_" + to_string(size) + "k_" + "iSReverse" + ".txt";
            sortingAlgorithmsint[0](intAlgorithm.tab, size, filename);

            filename = fs::current_path().string() + "\\Files\\int_" + to_string(size) + "k_" + "iSBReverse" + ".txt";
            sortingAlgorithmsint[1](intAlgorithm.tab1, size, filename);

            filename = fs::current_path().string() + "\\Files\\int_" + to_string(size) + "k_" + "hSReverse" + ".txt";
            sortingAlgorithmsint[2](intAlgorithm.tab2, size, filename);

            filename = fs::current_path().string() + "\\Files\\int_" + to_string(size) + "k_" + "qSReverse" + ".txt";
            sortingAlgorithmsint[1](intAlgorithm.tab3, size, filename);

        }

        for (int i = 0; i < 100; ++i) {
            intAlgorithm.initialize(Table<int>::generate33(size));


            filename = fs::current_path().string() + "\\Files\\int_" + to_string(size) + "k_" + "iS33" + ".txt";
            sortingAlgorithmsint[0](intAlgorithm.tab, size, filename);

            filename = fs::current_path().string() + "\\Files\\int_" + to_string(size) + "k_" + "iSB33" + ".txt";
            sortingAlgorithmsint[1](intAlgorithm.tab1, size, filename);

            filename = fs::current_path().string() + "\\Files\\int_" + to_string(size) + "k_" + "hS33" + ".txt";
            sortingAlgorithmsint[2](intAlgorithm.tab2, size, filename);

            filename = fs::current_path().string() + "\\Files\\int_" + to_string(size) + "k_" + "qS33" + ".txt";
            sortingAlgorithmsint[1](intAlgorithm.tab3, size, filename);

        }

        for (int i = 0; i < 100; ++i) {
            intAlgorithm.initialize(Table<int>::generate66(size));


            filename = fs::current_path().string() + "\\Files\\int_" + to_string(size) + "k_" + "iS66" + ".txt";
            sortingAlgorithmsint[0](intAlgorithm.tab, size, filename);

            filename = fs::current_path().string() + "\\Files\\int_" + to_string(size) + "k_" + "iSB66" + ".txt";
            sortingAlgorithmsint[1](intAlgorithm.tab1, size, filename);

            filename = fs::current_path().string() + "\\Files\\int_" + to_string(size) + "k_" + "hS66" + ".txt";
            sortingAlgorithmsint[2](intAlgorithm.tab2, size, filename);

            filename = fs::current_path().string() + "\\Files\\int_" + to_string(size) + "k_" + "qS66" + ".txt";
            sortingAlgorithmsint[1](intAlgorithm.tab3, size, filename);

        }

        for (int i = 0; i < 100; ++i) {
            floatAlgorithm.initialize(Table<float>::generateSorted(size));


            filename = fs::current_path().string() + "\\Files\\float_" + to_string(size) + "k_" + "iSSorted" + ".txt";
            sortingAlgorithmsfloat[0](floatAlgorithm.tab, size, filename);

            filename = fs::current_path().string() + "\\Files\\float_" + to_string(size) + "k_" + "iSBSorted" + ".txt";
            sortingAlgorithmsfloat[1](floatAlgorithm.tab1, size, filename);

            filename = fs::current_path().string() + "\\Files\\float_" + to_string(size) + "k_" + "hSSorted" + ".txt";
            sortingAlgorithmsfloat[2](floatAlgorithm.tab2, size, filename);

            filename = fs::current_path().string() + "\\Files\\float_" + to_string(size) + "k_" + "qSSorted" + ".txt";
            sortingAlgorithmsfloat[1](floatAlgorithm.tab3, size, filename);

        }
        for (int i = 0; i < 100; ++i) {
            floatAlgorithm.initialize(Table<float>::generateReverse(size));


            filename = fs::current_path().string() + "\\Files\\float_" + to_string(size) + "k_" + "iSReverse" + ".txt";
            sortingAlgorithmsfloat[0](floatAlgorithm.tab, size, filename);

            filename = fs::current_path().string() + "\\Files\\float_" + to_string(size) + "k_" + "iSBReverse" + ".txt";
            sortingAlgorithmsfloat[1](floatAlgorithm.tab1, size, filename);

            filename = fs::current_path().string() + "\\Files\\float_" + to_string(size) + "k_" + "hSReverse" + ".txt";
            sortingAlgorithmsfloat[2](floatAlgorithm.tab2, size, filename);

            filename = fs::current_path().string() + "\\Files\\float_" + to_string(size) + "k_" + "qSReverse" + ".txt";
            sortingAlgorithmsfloat[1](floatAlgorithm.tab3, size, filename);

        }

        for (int i = 0; i < 100; ++i) {
            floatAlgorithm.initialize(Table<float>::generate33f(size));


            filename = fs::current_path().string() + "\\Files\\float_" + to_string(size) + "k_" + "iS33" + ".txt";
            sortingAlgorithmsfloat[0](floatAlgorithm.tab, size, filename);

            filename = fs::current_path().string() + "\\Files\\float_" + to_string(size) + "k_" + "iSB33" + ".txt";
            sortingAlgorithmsfloat[1](floatAlgorithm.tab1, size, filename);

            filename = fs::current_path().string() + "\\Files\\float_" + to_string(size) + "k_" + "hS33" + ".txt";
            sortingAlgorithmsfloat[2](floatAlgorithm.tab2, size, filename);

            filename = fs::current_path().string() + "\\Files\\float_" + to_string(size) + "k_" + "qS33" + ".txt";
            sortingAlgorithmsfloat[1](floatAlgorithm.tab3, size, filename);

        }

        for (int i = 0; i < 100; ++i) {
            floatAlgorithm.initialize(Table<float>::generate66f(size));


            filename = fs::current_path().string() + "\\Files\\float_" + to_string(size) + "k_" + "iS66" + ".txt";
            sortingAlgorithmsfloat[0](floatAlgorithm.tab, size, filename);

            filename = fs::current_path().string() + "\\Files\\float_" + to_string(size) + "k_" + "iSB66" + ".txt";
            sortingAlgorithmsfloat[1](floatAlgorithm.tab1, size, filename);

            filename = fs::current_path().string() + "\\Files\\float_" + to_string(size) + "k_" + "hS66" + ".txt";
            sortingAlgorithmsfloat[2](floatAlgorithm.tab2, size, filename);

            filename = fs::current_path().string() + "\\Files\\float_" + to_string(size) + "k_" + "qS66" + ".txt";
            sortingAlgorithmsfloat[1](floatAlgorithm.tab3, size, filename);

        }
    }
}
