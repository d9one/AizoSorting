#include <random>
#include <fstream>
#include <chrono>
#include "Algorithm.h"

template<class T>
Algorithm<T>::Algorithm() : tab(nullptr), size(0) {}

template<class T>
void Algorithm<T>::initialize(const vector<T>& vector) {
    size = static_cast<int>(vector.size());
    tab = new T[size];
    tab1 = new T[size];
    tab2 = new T[size];
    tab3 = new T[size];
    for (int i = 0; i < size; ++i) {
        tab[i] = vector[i];
        tab1[i] = vector[i];
        tab2[i] = vector[i];
        tab3[i] = vector[i];
    }
}

template<class T>
Algorithm<T>::~Algorithm() {
    delete[] tab;
    tab = nullptr;
    delete[] tab1;
    tab1 = nullptr;
    delete[] tab2;
    tab2 = nullptr;
    delete[] tab3;
    tab3 = nullptr;
}

template<class T>
void Algorithm<T>::displayArray(T*& tab) {
    for (int i = 0; i < size; ++i) {
        cout << tab[i] << " ";
    }
    cout << endl;
}

template<class T>
void Algorithm<T>::saveToFile(const string& filename) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        outputFile << size << "\n";
        for (int i = 0; i < size; ++i) {
            outputFile << tab[i] << "\n";
        }
        outputFile.close();
        cout << "Tablica zostala zapisana do pliku"<< endl;
    } else {
        cerr << "Nie udało sie zapisac do pliku" << endl;
    }
}

template<class T>
bool Algorithm<T>::isTableSorted(T*& tab) {
    bool x = true;
    for(int i=0; i<size-1; i++){
        if(tab[i]>tab[i+1]){
            x = false;
        }
    }
    return x;
}

template<class T>
void Algorithm<T>::saveResult(double result, const string& filename){
    ofstream outputFile(filename, ios::app);
    if (outputFile.is_open()) {
        outputFile << result << "\n";
        outputFile.close();
        cout << "Zapisano: " << result << " s" << endl;
    } else {
        cerr << "Nie udało sie zapisac do pliku" << endl;
    }
}

template<class T>
void Algorithm<T>::insertionSort(T*& tab, const string& filename) {
    int i;
    T t;
    auto start = chrono::high_resolution_clock::now();
    // Pętla główna przechodzi przez elementy tablicy, zaczynając od przedostatniego
    for(int j = size-2; j>=0; j--){
        t = tab[j];
        i = j + 1;
        // Pętla while przechodzi przez elementy tablicy od i do końca, szukając miejsca dla t
        while(i<size && t>tab[i]){
            tab[i-1] = tab[i];
            i++;
        }
        // Wstawianie klucza na odpowiednią pozycję
        tab[i-1] = t;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "InsertionSort ";
    saveResult(elapsed.count(), filename);

}

template<class T>
void Algorithm<T>::insertionSortBin(T*& tab, const string& filename) {
    T t;
    auto start = chrono::high_resolution_clock::now();
    for (int j = 1; j < size; j++) {
        T key = tab[j];
        int left = 0;
        int right = j;

        // Wyszukiwanie binarne odpowiedniej pozycji dla klucza
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (tab[mid] <= key) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        // Przesuwanie elementów w prawo
        for (int k = j; k > left; k--) {
            tab[k] = tab[k - 1];
        }

        // Wstawianie klucza na odpowiednią pozycję
        tab[left] = key;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "InsertionSortBin ";
    saveResult(elapsed.count(), filename);
}
template<class T>
void Algorithm<T>::quickSort(T *&tab, int left, int right, const std::string &filename) {
    if (left >= right) return; // Warunek stopu rekurencji

    int i = left, j = right;
    T pivot = tab[(left + right) / 2]; // Wybór pivota

    // Podział tablicy na dwie części: mniejsze i większe od pivota
    while (i <= j) {
        while (tab[i] < pivot) i++;
        while (tab[j] > pivot) j--;
        if (i <= j) {
            swap(tab[i], tab[j]);
            i++;
            j--;
        }
    }

    // Rekurencyjne sortowanie dwóch części tablicy
    quickSort(tab, left, j, filename);
    quickSort(tab, i, right, filename);

}

template<class T>
void Algorithm<T>::heapify(T *&tab, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && tab[left] > tab[largest]) {
        largest = left;
    }

    if (right < n && tab[right] > tab[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(tab[i], tab[largest]);
        heapify(tab, n, largest);
    }
}

template<class T>
void Algorithm<T>::heapSort(T *&tab, const std::string &filename) {

    auto start = chrono::high_resolution_clock::now();
    // Budowanie kopca
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(tab, size, i);
    }

    // Rozbieranie kopca
    for (int i = size - 1; i >= 0; i--) {
        swap(tab[0], tab[i]);
        heapify(tab, i, 0);
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "HeapSort ";
    saveResult(elapsed.count(), filename);
}




// Explicit instantiation dla typu int
template class Algorithm<int>;

// Explicit instantiation dla typu float
template class Algorithm<float>;

// Explicit instantiation dla typu char
template class Algorithm<char>;
