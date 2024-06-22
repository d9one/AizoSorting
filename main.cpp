#include <iostream>
#include "Simulation.h"
#include "Test.h"

using namespace std;

int main() {
    int mode;
    while(true){
        cout << "Wybierz (1) dla trybu testu, (2) dla trybu symulacji, (-1)Zakoncz dzialanie porgramu: "<< endl;
        cin >> mode;
        switch(mode){
            case 1:
                Test::test();
                break;
            case 2:
                Simulation::simulation();
                break;
            case -1:
                exit(0);
            default:
                break;
        }
    }
}