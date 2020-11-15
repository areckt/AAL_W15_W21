/*
 * Arkadiusz Dawid,     300199
 * Illia Yatskevich,    302211
 * Projekt AAL W15 W21 - Tablica mieszajaca
 */

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){

    if(argc > 1){
        int tableSize = stoi(argv[1], nullptr, 10);
        cout << "Rozmiar tablicy to:" << tableSize << endl;
    }
    cout << "Hello World" << endl;


    return 0;
}