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
#include <vector>
#include "../include/hash.h"

using namespace std;

#define PRIME 7

long int hashFunction(string s){        // oblicza hash, zwraca k (jeszcze przed modulo TableSize)
    int g = 31;
    long int k = 0;
    for(char i : s){
        k = g * k + (int)i;
    }

    return k;
}
string generate(void);                  // generuje losowe słowa, zwraca s
int insertToHashTable(string s, int k); // wstawia słowo s do tablicy na pozycji k



int main(int argc, char *argv[]){

    /*
     if(argc > 1){
        const int tableSize = stoi(argv[1], nullptr, 10);
        cout << "Table size:" << tableSize << endl;
    }
    */

    /*
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
    */
    int TableSize = 11;

    vector<string> hashTable (TableSize);
    string s;
    long int k;
    int k1;

    for(int i = 0; i < TableSize; i++){
        s = generate();
        k = hashFunction(s);
        k1 = (int)(k%TableSize);

        insertToHashTable(s, k1);
        if(hashTable.at(k).length() != 0){  // if collision occurs
            int k2 = PRIME - (k % PRIME);
            int new_k;
            for(int j = 1; ; j++){
                new_k = (k1 + j*k2) % TableSize;

                //check for collision
                if(hashTable.at(new_k).length() == 0){
                    insertToHashTable(s, new_k);
                    break;
                }
            }
        }
        else{   // if no collision occurs
            insertToHashTable(s, k1);
        }
    }

    for(const auto& i : hashTable){
        if(i.length() == 0) cout << "[-]" << endl;
    }

    return 0;
}



int insertToHashTable(string s, int k){
    ;
}