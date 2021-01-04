/*
 * Arkadiusz Dawid,     300199
 * Illia Yatskevich,    302211
 * Projekt AAL W15 W21 - Tablica mieszajaca
 */

/*
 * UWAGI:
 * Słowo nie powinno byc dłuższe niż 13 znaków, trzeba to uwzględnić przy generowaniu losowych słów
 * Powód jest taki, że przy 14 znakach hash jest zbyt duży i "przekręca" się na ujemne wartości
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <locale>
#include <algorithm>
#include "../include/generator.h"

using namespace std;

#define PRIME 7

long int hashFunction(wstring s){        // calculates hash, returns k (before modulo TableSize)
    int g = 31;
    long int k = 0;
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
    
    setlocale( LC_ALL, "C.UTF-8" );
    wifstream file("pan-tadeusz.txt");
    file.imbue(std::locale("C.UTF-8"));
    if(!file.good())
    {
        std::cout << "Cannot open file" << endl;
        return -1;
    }
    
    vector<wstring> text;
    wstring word;
    wstring cleaned_word;
    wstringstream stream1;
    wstringstream stream2;
    wss << file.rdbuf();
    

    while(stream1 >> word)
    {
        cleaned_word = cleanText(word) + L' ';
        stream2 << cleaned_word;
    }

    while(stream2 >> word)
    {
        text.push_back(word);
    }

    vector<int> first_letter_dist = calcStartDist(text);
    vector<vector<int>> second_letter_dist = calcSecondDist(text);
    vector<int> wordLength = calcWordLengthDist(text);


    int TableSize = 11;

    vector<wstring> hashTable (TableSize);
    wstring s;
    long int k;
    int k1;

    /*
    // initialize vectors of probability for generator
    vector<float> startProbability (26, 0); // prob of first letter in word
    vector<vector<float>> nextProbability (26, vector<float>(27, 0));   // prob of letter after other letter
    */
    
    

    // main loop - inserting to the hashTable
    for(int i = 0; i < TableSize; i++){
        s = generateWord(first_letter_dist, second_letter_dist, wordLength);
        k = hashFunction(s);
        k1 = (int)(k%TableSize);

        if(hashTable.at(k1).length() != 0){  // if collision occurs
            int k2 = PRIME - (k % PRIME);
            int new_k;
            for(int j = 1; true; j++){
                new_k = (k1 + j*k2) % TableSize;

                //check for collision
                if(hashTable.at(new_k).length() == 0){
                    hashTable.at(new_k) = s;
                    break;
                }
            }
        }
        else{   // if no collision occurs
            hashTable.at(k1) = s;
        }
    }

    // print out content of hashTable
    for(const auto& i : hashTable){
        if(i.length() == 0) cout << "[-]" << endl;
        else wcout << i << endl;
    }

    return 0;
}
