#include "Table.h"

using namespace std;
template<typename T>
vector<T> Table<T>::loadTable(const string& fileName) {
    ifstream file(fileName);

    if (!file.is_open()) {
        cerr << "Nie udalo sie otworzyc pliku: " << fileName << endl;
        perror("Blad");

        return {};
    }

    int size;
    file >> size;

    vector<T> tab;
    tab.reserve(size);

    T element;
    while (file >> element) {
        tab.push_back(element);
    }

    file.close();

    return tab;
}

template<typename T>
vector<int> Table<T>::generateIntArray(int size) {
    vector<int> tab;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(numeric_limits<int>::min(), numeric_limits<int>::max());

    for (int i = 0; i < size; ++i) {
        int random_num = dis(gen);
        tab.push_back(random_num);
    }

    return tab;
}

template<typename T>
vector<float> Table<T>::generateFloatArray(int size) {
    float min_val = -100000.0f;
    float max_val = 100000.0f;

    vector<float> tab;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(min_val, max_val);

    for (int i = 0; i < size; ++i) {
        float random_num = dis(gen);
        tab.push_back(random_num);
    }

    return tab;
}

template<typename T>
vector<char> Table<T>::generateCharArray(int size) {
    char min_val = CHAR_MIN;
    char max_val = CHAR_MAX;

    vector<char> tab;
    srand(time(nullptr));

    for (int i = 0; i < size; ++i) {
        char random_num = rand() % (max_val - min_val + 1) + min_val;
        tab.push_back(random_num);
    }

    return tab;
}

template<typename T>
vector<T>Table<T>::generateSorted(int size) {
    vector<T> tab;
    for(int i=0; i<size; i++){
        tab.push_back(i);
    }
    return tab;
}

template<typename T>
vector<T>Table<T>::generateReverse(int size) {
    vector<T> tab;
    for(int i=size; i>0; i--){
        tab.push_back(i);
    }
    return tab;
}

template<typename T>
vector<int>Table<T>::generate33(int size){
    vector<int> tab;
    int n = size/3;
    int x = numeric_limits<int>::min();

    while(n>0){
        tab.push_back(x);
        x++;
        n--;
    }

    int min_range = x+1;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(min_range, numeric_limits<int>::max());

    for(int i=(size/3)+1; i<size; i++){
        int random_num = dis(gen);
        tab.push_back(random_num);
    }
    return tab;
}

template<typename T>
vector<int>Table<T>::generate66(int size){
    vector<int> tab;
    int n = (2*size)/3;
    int x = numeric_limits<int>::min();

    while(n>0){
        tab.push_back(x);
        x++;
        n--;
    }

    int min_range = x+1;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(min_range, numeric_limits<int>::max());

    for(int i=((2*size)/3)+1; i<size; i++){
        int random_num = dis(gen);
        tab.push_back(random_num);
    }
    return tab;
}

template<typename T>
vector<float>Table<T>::generate33f(int size){
    vector<float> tab;
    int n = size/3;
    float min_val = -100000.0f;
    float max_val = 100000.0f;

    while(n>0){
        tab.push_back(min_val);
        min_val++;
        n--;
    }

    float min_range = min_val+1;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(min_range, max_val);

    for(int i=(size/3)+1; i<size; i++){
        float random_num = dis(gen);
        tab.push_back(random_num);
    }
    return tab;
}

template<typename T>
vector<float>Table<T>::generate66f(int size){
    vector<float> tab;
    int n = (2*size)/3;
    float min_val = -100000.0f;
    float max_val = 100000.0f;

    while(n>0){
        tab.push_back(min_val);
        min_val++;
        n--;
    }

    float min_range = min_val+1;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(min_range, max_val);

    for(int i=((2*size)/3)+1; i<size; i++){
        float random_num = dis(gen);
        tab.push_back(random_num);
    }
    return tab;
}
// Explicit instantiation dla typu int
template class Table<int>;

// Explicit instantiation dla typu float
template class Table<float>;

// Explicit instantiation dla typu char
template class Table<char>;
