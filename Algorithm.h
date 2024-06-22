#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>
#include <iostream>

using namespace std;

template<class T>
class Algorithm {
public:
    T* tab;
    T* tab1;
    T* tab2;
    T* tab3;
    int size;

    // Konstruktor domyślny
    Algorithm();

    // Metoda do inicjalizacji
    void initialize(const vector<T>& vector);

    //Dekonstruktor
    ~Algorithm();

    // Metoda do wyświetlania tablicy
    void displayArray(T*& tab);

    // Metoda zapisująca tablice do pliku
    void saveToFile(const string& filename);

    // Metoda sprawdzająca czy tablica jest posortowana
    bool isTableSorted(T*& tab);

    // Metoda do zapisu wyniku w pliku
    void saveResult(double result, const string& filename);

    // Metoda sortująca algorytmem przez wstawianie
    void insertionSort(T*& tab, const string& filename);

    // Metoda sortująca algorytmem przez wstawianie binarnie
    void insertionSortBin(T*& tab, const string& filename);

    //Metoda służąca do przywracania funkcji kopca
    void heapify(T *&tab, int n, int i);

    //Metoda sortująca algorytmem przez kopcowanie
    void heapSort(T*& tab, const string& filename);

    // Metoda sortująca algorytmem szybkim
    void quickSort(T*& tab, int left, int right, const string& filename);


};
#endif // ALGORITHM_H
