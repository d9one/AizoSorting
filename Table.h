#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <iostream>
#include <fstream>
#include <random>
#include <limits>

using namespace std;

template<typename T>
class Table {
public:
    // Metoda ładująca dane z pliku do obiektu Algorithm
    static vector<T> loadTable(const string& fileName);

    //Metoda generująca tablice o rozmiarze n z danymi typu int
    static vector<int> generateIntArray(int size);

    //Metoda generująca tablice o rozmiarze n z danymi typu float
    static vector<float> generateFloatArray(int size);

    //Metoda generująca tablice o rozmiarze n z danymi typu char
    static vector<char> generateCharArray(int size);

    //Metoda generujaca tablic o rozmairze n z danymi typu T posortowana
    static vector<T> generateSorted(int size);

    //Metoda generujaca tablic o rozmairze n z danymi typu T odwróconą
    static vector<T> generateReverse(int size);

    //Metoda generujaca tablic o rozmairze n z danymi typu int  w 33% posortowaną
    static vector<int> generate33(int size);

    //Metoda generujaca tablic o rozmairze n z danymi typu float  w 33% posortowaną
    static vector<float> generate33f(int size);

    //Metoda generujaca tablic o rozmairze n z danymi typu int  w 66% posortowaną
    static vector<int> generate66(int size);

    //Metoda generujaca tablic o rozmairze n z danymi typu float  w 66% posortowaną
    static vector<float> generate66f(int size);
};



#endif // TABLE_H