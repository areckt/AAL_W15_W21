/*
 * Arkadiusz Dawid,     300199
 * Illia Yatskevich,    302211
 * Projekt AAL W15 W21 - Tablica mieszajaca
 */

/*
 * UWAGI:
 * Bardzo ważne jest, by tableSize był liczbą pierwszą
 * PRIME musi być liczbą pierwszą, koniecznie mniejszą od tableSize
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../include/generator.h"

using namespace std;

#define PRIME 53

unsigned long int hashFunction(string s){        // calculates hash, returns k (before modulo TableSize)
    int g = 31;
    unsigned long int k = 0;
    for(char i : s){
        k = g * k + (int)i;
    }
    return k;
}

int main(int argc, char *argv[]){

    /*
     if(argc > 1){
        const int tableSize = stoi(argv[1], nullptr, 10);
        cout << "Table size:" << tableSize << endl;
    }
    */
    
    fstream file("../util/out.txt", ios::in);
    if(!file.good())
    {
        std::cout << "Cannot open file" << endl;
        return -1;
    }

    vector<string> text; 
    string word;

    while(!file.eof())
    {
        file >> word;
        text.push_back(word);
    }

    vector<int> first_letter_dist = calcStartDist(text);
    vector<vector<int>> second_letter_dist = calcSecondDist(text);
    vector<int> wordLength = calcWordLengthDist(text);

    unsigned int TableSize = 103;

    vector<string> hashTable (TableSize);
    string s;
    unsigned long int k;
    unsigned int k1;

    // main loop - inserting to the hashTable
    for(int i = 0; i < TableSize; i++){
        s = generateWord(first_letter_dist, second_letter_dist, wordLength);
        k = hashFunction(s);
        k1 = (int)(k % TableSize);

        if(hashTable.at(k1).length() != 0){  // if collision occurs
            //cout << "Collision at index " << k1 << "\twith word " << s << "\t- " << hashTable.at(k1) << " is already there" << endl;
            unsigned int k2 = PRIME - (k % PRIME);
            unsigned int new_k;
            for(int j = 1; true; j++){
                new_k = (k1 + j*k2) % TableSize;

                //check for collision
                if(hashTable.at(new_k).length() == 0){
                    hashTable.at(new_k) = s;
                    break;
                }
                //else cout << "Collision at index " << new_k << "\twith word " << s << "\t- " << hashTable.at(new_k) << " is already there" << endl;
            }
        }
        else{   // if no collision occurs
            hashTable.at(k1) = s;
        }
    }

    cout << endl;
    // print out content of hashTable
    for(const auto& i : hashTable){
        if(i.length() == 0) cout << "[-]" << endl;
        else cout << i << endl;
    }

    return 0;
}
