#include "Test.h"
#include <iostream>
#include "Algorithm.h"
#include "Table.h"
#include <filesystem>
#include <chrono>
#include <cstdlib>
#include <functional>

using namespace std;
namespace fs = filesystem;

void Test::test() {
    int choice;
    int type;
    int n;
    string filename;
    while(true){
        cout << "Wybierz typ zmiennej: (1)-int, (2)-float, (3)-char" << endl;
        cin >> type;
        if(type == 1 || type == 2 || type ==3){
            break;
        }
    }
    Algorithm<int> intAlgorithm;
    Algorithm<float> floatAlgorithm;
    Algorithm<char> charAlgorithm;

    while (true){

        cout << "Wybierz co chcesz zrobic: (1)Utworz tablice na podstwie pliku, (2)Wyswietl tablice, (3)Wygeneruj tablice, \n (4)Zapisz tablice do pliku, (5)Posortuj tablice, (6)Zmien typ zmiennej, (-1)Zakoncz program" << endl;
        cin >> choice;
        switch(choice){
            case 1:
                cout <<"Podaj nazwe pliku:"<<endl;
                cin>>filename;
                filename = fs::current_path().string() + "\\Files" + "\\" + filename;
                if (type == 1) {
                    intAlgorithm.initialize(Table<int>::loadTable(filename));
                } else if (type == 2) {
                    floatAlgorithm.initialize(Table<float>::loadTable(filename));
                } else if (type == 3) {
                    charAlgorithm.initialize(Table<char>::loadTable(filename));
                } else{
                    cout << "Blad"<< endl;
                }
                break;
            case 2:
                if (type == 1) {
                    if(intAlgorithm.size<=30)
                        intAlgorithm.displayArray(intAlgorithm.tab);
                    else
                    if(intAlgorithm.isTableSorted(intAlgorithm.tab))
                        cout << "Tablica ma ponad 30 elementow, jest posortowana: " << "true" << endl;
                    else
                        cout << "Tablica ma ponad 30 elementow, jest posortowana: " << "false" << endl;
                } else if (type == 2) {
                    if(floatAlgorithm.size<=30)
                        floatAlgorithm.displayArray(floatAlgorithm.tab);
                    else
                    if(floatAlgorithm.isTableSorted(floatAlgorithm.tab))
                        cout << "Tablica ma ponad 30 elementow, jest posortowana: " << "true" << endl;
                    else
                        cout << "Tablica ma ponad 30 elementow, jest posortowana: " << "false" << endl;
                } else if (type == 3) {
                    if(charAlgorithm.size<=30)
                        charAlgorithm.displayArray(charAlgorithm.tab);
                    else
                    if(charAlgorithm.isTableSorted(charAlgorithm.tab))
                        cout << "Tablica ma ponad 30 elementow, jest posortowana: " << "true" << endl;
                    else
                        cout << "Tablica ma ponad 30 elementow, jest posortowana: " << "false" << endl;
                } else{
                    cout << "Blad"<< endl;
                }
                break;
            case 3:
                cout << "Podaj rozmiar tablicy:";
                cin >> n;
                if (type == 1) {
                    intAlgorithm.initialize(Table<int>::generateIntArray(n));
                } else if (type == 2) {
                    floatAlgorithm.initialize(Table<float>::generateFloatArray(n));
                } else if (type == 3) {
                    charAlgorithm.initialize(Table<char>::generateCharArray(n));
                } else{
                    cout << "Blad"<< endl;
                }
                break;
            case 4:
                cout <<"Podaj nazwe pliku do jakiego chcesz zapisac"<<endl;
                cin>>filename;
                filename = fs::current_path().string() + "\\Files" + "\\" + filename;
                if (type == 1) {
                    intAlgorithm.saveToFile(filename);
                } else if (type == 2) {
                    floatAlgorithm.saveToFile(filename);
                } else if (type == 3) {
                    charAlgorithm.saveToFile(filename);
                } else{
                    cout << "Blad"<< endl;
                }
                break;
            case 5:
            {
                //Sortowanie InsertionSort
                filename = fs::current_path().string() + "\\Files\\iS.txt";
                if (type == 1) {
                    intAlgorithm.insertionSort(intAlgorithm.tab, filename);
                } else if (type == 2) {
                    floatAlgorithm.insertionSort(floatAlgorithm.tab, filename);
                } else if (type == 3) {
                    charAlgorithm.insertionSort(charAlgorithm.tab, filename);
                } else{
                    cout << "Blad"<< endl;
                }

                //Sortowanie InsertionSortBin
                filename = fs::current_path().string() + "\\Files\\iSB.txt";
                if (type == 1) {
                    intAlgorithm.insertionSortBin(intAlgorithm.tab1, filename);
                } else if (type == 2) {
                    floatAlgorithm.insertionSortBin(floatAlgorithm.tab1, filename);
                } else if (type == 3) {
                    charAlgorithm.insertionSortBin(charAlgorithm.tab1, filename);
                } else{
                    cout << "Blad"<< endl;
                }

                //Sortowanie HeapSort
                filename = fs::current_path().string() + "\\Files\\hS.txt";
                if (type == 1) {
                    intAlgorithm.heapSort(intAlgorithm.tab2, filename);
                } else if (type == 2) {
                    floatAlgorithm.heapSort(floatAlgorithm.tab2, filename);
                } else if (type == 3) {
                    charAlgorithm.heapSort(charAlgorithm.tab2, filename);
                } else{
                    cout << "Blad"<< endl;
                }


                auto start = chrono::high_resolution_clock::now();

                //Sortowanie quickSort
                filename = fs::current_path().string() + "\\Files\\qS.txt";
                if (type == 1) {
                    intAlgorithm.quickSort(intAlgorithm.tab3, 0, intAlgorithm.size - 1, filename);
                } else if (type == 2) {
                    floatAlgorithm.quickSort(floatAlgorithm.tab3, 0, floatAlgorithm.size - 1, filename);
                } else if (type == 3) {
                    charAlgorithm.quickSort(charAlgorithm.tab3, 0, charAlgorithm.size - 1, filename);
                } else{
                    cout << "Blad"<< endl;
                }

                auto end = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed = end - start;
                cout << "QuickSort ";
                intAlgorithm.saveResult(elapsed.count(), filename);

                if (type == 1) {
                    if(intAlgorithm.size<=30){
                        cout << "Tablica posortowana iS:";
                        intAlgorithm.displayArray(intAlgorithm.tab);
                        cout << "Tablica posortowana iSB:";
                        intAlgorithm.displayArray(intAlgorithm.tab1);
                        cout << "Tablica posortowana hS:";
                        intAlgorithm.displayArray(intAlgorithm.tab2);
                        cout << "Tablica posortowana qS:";
                        intAlgorithm.displayArray(intAlgorithm.tab3);
                    }
                    else{
                        if(intAlgorithm.isTableSorted(intAlgorithm.tab))
                            cout << "Tablica ma ponad 30 elementow, jest posortowana iS: " << "true" << endl;
                        else
                            cout << "Tablica ma ponad 30 elementow, jest posortowana iS: " << "false" << endl;
                        if(intAlgorithm.isTableSorted(intAlgorithm.tab1))
                            cout << "Tablica ma ponad 30 elementow, jest posortowana iSB: " << "true" << endl;
                        else
                            cout << "Tablica ma ponad 30 elementow, jest posortowana iSB: " << "false" << endl;
                        if(intAlgorithm.isTableSorted(intAlgorithm.tab2))
                            cout << "Tablica ma ponad 30 elementow, jest posortowana hS: " << "true" << endl;
                        else
                            cout << "Tablica ma ponad 30 elementow, jest posortowana hS: " << "false" << endl;
                        if(intAlgorithm.isTableSorted(intAlgorithm.tab3))
                            cout << "Tablica ma ponad 30 elementow, jest posortowana qS: " << "true" << endl;
                        else
                            cout << "Tablica ma ponad 30 elementow, jest posortowana qS: " << "false" << endl;
                    }

                } else if (type == 2) {
                    if(floatAlgorithm.size<=30){
                        cout << "Tablica posortowana iS:";
                        floatAlgorithm.displayArray(floatAlgorithm.tab);
                        cout << "Tablica posortowana iSB:";
                        floatAlgorithm.displayArray(floatAlgorithm.tab1);
                        cout << "Tablica posortowana hS:";
                        floatAlgorithm.displayArray(floatAlgorithm.tab2);
                        cout << "Tablica posortowana qS:";
                        floatAlgorithm.displayArray(floatAlgorithm.tab3);
                    }
                    else{
                        if(floatAlgorithm.isTableSorted(floatAlgorithm.tab))
                            cout << "Tablica ma ponad 30 elementow, jest posortowana iS: " << "true" << endl;
                        else
                            cout << "Tablica ma ponad 30 elementow, jest posortowana iS: " << "false" << endl;
                        if(floatAlgorithm.isTableSorted(floatAlgorithm.tab1))
                            cout << "Tablica ma ponad 30 elementow, jest posortowana iSB: " << "true" << endl;
                        else
                            cout << "Tablica ma ponad 30 elementow, jest posortowana iSB: " << "false" << endl;
                        if(floatAlgorithm.isTableSorted(floatAlgorithm.tab2))
                            cout << "Tablica ma ponad 30 elementow, jest posortowana hS: " << "true" << endl;
                        else
                            cout << "Tablica ma ponad 30 elementow, jest posortowana hS: " << "false" << endl;
                        if(floatAlgorithm.isTableSorted(floatAlgorithm.tab3))
                            cout << "Tablica ma ponad 30 elementow, jest posortowana qS: " << "true" << endl;
                        else
                            cout << "Tablica ma ponad 30 elementow, jest posortowana qS: " << "false" << endl;
                    }
                } else if (type == 3) {
                    if(charAlgorithm.size<=30){
                        cout << "Tablica posortowana iS:";
                        charAlgorithm.displayArray(charAlgorithm.tab);
                        cout << "Tablica posortowana iSB:";
                        charAlgorithm.displayArray(charAlgorithm.tab1);
                        cout << "Tablica posortowana hS:";
                        charAlgorithm.displayArray(charAlgorithm.tab2);
                        cout << "Tablica posortowana qS:";
                        charAlgorithm.displayArray(charAlgorithm.tab3);
                    }
                    else{
                        if(charAlgorithm.isTableSorted(charAlgorithm.tab))
                            cout << "Tablica ma ponad 30 elementow, jest posortowana iS: " << "true" << endl;
                        else
                            cout << "Tablica ma ponad 30 elementow, jest posortowana iS: " << "false" << endl;
                        if(charAlgorithm.isTableSorted(charAlgorithm.tab1))
                            cout << "Tablica ma ponad 30 elementow, jest posortowana iSB: " << "true" << endl;
                        else
                            cout << "Tablica ma ponad 30 elementow, jest posortowana iSB: " << "false" << endl;
                        if(charAlgorithm.isTableSorted(charAlgorithm.tab2))
                            cout << "Tablica ma ponad 30 elementow, jest posortowana hS: " << "true" << endl;
                        else
                            cout << "Tablica ma ponad 30 elementow, jest posortowana hS: " << "false" << endl;
                        if(charAlgorithm.isTableSorted(charAlgorithm.tab3))
                            cout << "Tablica ma ponad 30 elementow, jest posortowana qS: " << "true" << endl;
                        else
                            cout << "Tablica ma ponad 30 elementow, jest posortowana qS: " << "false" << endl;
                    }
                }
                break;
            }
            case 6:
                while(true){
                    cout << "Wybierz typ zmiennej: (1)-int, (2)-float, (3)-char" << endl;
                    cin >> type;
                    if(type == 1 || type == 2 || type == 3){
                        break;
                    }
                }

                break;
            case -1:
                exit(0);
            default:
                cout << "Podales zly numer: \n";
                break;
        }
    }
}
