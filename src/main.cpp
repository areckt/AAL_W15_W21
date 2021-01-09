/*
 * Arkadiusz Dawid,     300199
 * Illia Yatskevich,    302211
 * Projekt AAL W15 W21 - Tablica mieszajaca
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <locale>
#include <algorithm>
#include "../include/generator.h"
#include "../include/benchmark.h"

using namespace std;

#define PRIME 7

unsigned long int hashFunction(wstring s);
void displayHelp();
void putIntoHashTable(vector<wstring> &hashTable, wstring s, int tableSize, unsigned long int k, unsigned int k1);
void printHashTable(vector<wstring> &hashTable);

int main(int argc, char *argv[]){

    string mode, inputFile, outputFile;
    int tableSize;

    if(argc == 2 || argc == 3 || argc == 5){
         mode = argv[1];
         if(mode[0] == 'h'){
             displayHelp();
             return 0;
         }

         tableSize = stoi(argv[2], nullptr, 10);
         if(argc == 5){
             inputFile = argv[3];
             outputFile = argv[4];
         }

         for(int i = 0; i < argc; ++i) {
             cout << "Argument " << i << "\t" << argv[i] << endl;
        }
     }
    else{
         cout << "Error: invalid number of parameters given\nIf you need help, try ./prog h" << endl;
         return -1;
    }

    vector<wstring> hashTable (tableSize);
    wstring s;
    unsigned long int k;
    unsigned int k1;


    /*
     * ##  MODE 1  ##
     */

    if(mode == "t1"){

        for(int i = 0; i < tableSize; ++i){
            cout << "Type in word: ";
            wcin >> s;

            if(s.at(0) == '0'){
                break;
            }

            putIntoHashTable(hashTable, s, tableSize, k, k1);
        }

        printHashTable(hashTable);
        return 0;

    }


    /*
     * ##  MODE 2  ##
     */

    if(mode == "t2"){
        wifstream file(inputFile);
        file.imbue(std::locale("C.UTF-8"));
        if(!file.good())
        {
            std::cout << "Cannot open file" << endl;
            return -1;
        }

        vector<wstring> text;
        wstring word;

        while(!file.eof())
        {
            file >> word;
            text.push_back(word);
        }

        vector<int> first_letter_dist = calcStartDist(text);
        vector<vector<int>> second_letter_dist = calcSecondDist(text);
        vector<int> wordLength = calcWordLengthDist(text);

        for(int i = 0; i < tableSize; i++){
            s = generateWord(first_letter_dist, second_letter_dist, wordLength);
            putIntoHashTable(hashTable, s, tableSize, k, k1);
        }

        printHashTable(hashTable);
        return 0;

    }


    return 0;
}

unsigned long int hashFunction(wstring s){  // calculates hash, returns k (before modulo TableSize)
    int g = 31;
    unsigned long int k = 0;
    for(char i : s){
        k = g * k + (int)i;
    }

    return k;
}

void displayHelp(){
    cout << "Available run modes:\n\n";

    cout << "1) ./prog t1 tableSize\n";
    cout << "It allows you to manually type in words for hashTable.\ntableSize should be a small integer.\n";
    cout << "You can type in '0' to stop. At the end, content of hashTable will be displayed\n\n";

    cout << "2) ./prog t2 tableSize in.txt out.txt\n";
    cout << "It will generate random words based on a text from in.txt and put them in hashTable.\n";
    cout << "The time measurement will be saved to out.txt.\n";
    cout << "tableSize should be an integer from the range 1 - 2147483647\n\n";

    cout << "3) ./prog h\n";
    cout << "Show this help message.\n";
}

void putIntoHashTable(vector<wstring> &hashTable, wstring s, int tableSize, unsigned long int k, unsigned int k1){
    k = hashFunction(s);
    k1 = (unsigned int)(k%tableSize);

    if(hashTable.at(k1).length() != 0){  // if collision occurs
        unsigned int k2 = PRIME - (k % PRIME);
        unsigned int new_k;
        for(int j = 1; true; j++){
            new_k = (k1 + j*k2) % tableSize;

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

void printHashTable(vector<wstring> &hashTable){

    cout << "\nINDEX\tCONTENT\n";
    int index = 0;
    for(const auto& i : hashTable){
        if(i.length() == 0) cout << index << "\t\t[-]" << endl;
        else wcout << index << "\t\t" << i << endl;
        ++index;
    }
}