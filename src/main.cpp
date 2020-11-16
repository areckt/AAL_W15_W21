/*
 * Arkadiusz Dawid,     300199
 * Illia Yatskevich,    302211
 * Projekt AAL W15 W21 - Tablica mieszajaca
 */

/*
 * UWAGI:
 * Slowo nie powinno byc dluzsze niz 13 znakow, trzeba to uwzglednic przy generowaniu losowych slow
 */

#include <iostream>
#include <string>

using namespace std;

const int TableSize = 10;
int hashFunction(string s);

int main(int argc, char *argv[]){

    /*
     if(argc > 1){
        const int tableSize = stoi(argv[1], nullptr, 10);
        cout << "Table size:" << tableSize << endl;
    }
    */

    string HashTable[TableSize];
    string sTemp;
    int index;

    for(int i = 0; i < TableSize; i++){
        cout << "Type in word " << i+1 << endl;
        cin >> sTemp;
        index = hashFunction(sTemp);
        cout << "Index in table: " << index << endl;
        HashTable[index] = sTemp;
    }

    cout << "Zawartosc tabeli: " << endl;
    for(int i = 0; i < TableSize; i++){
        cout << "Na pozycji " << i << ": " << HashTable[i] << endl;
    }

    return 0;
}

int hashFunction(string s){
    int g = 31;
    long int k = 0;
    for(char i : s){
        k = g * k + (int)i;
    }
    k %= TableSize;
    return (int)k;
}