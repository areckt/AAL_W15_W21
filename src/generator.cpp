/*
 * Arkadiusz Dawid,     300199
 * Illia Yatskevich,    302211
 * Projekt AAL W15 W21 - Tablica mieszajaca
 */

#include <iostream>
#include <string>
#include <vector>
#include "../include/generator.h"

using namespace std;


string generateWord(vector<float> startProbability, vector<vector<float>> nextProbability){

    string word = "";
    char letter;
    int wordLength = 0;

    // na podstawie startProbability wylosuj pierwszą literę słowa
    word += letter;

    while(letter != ',' || wordLength<13){
        // na podstawie nextProbability losuj kolejne litery dopóki:
            // nie wylosujesz przecinka ','
            // ALBO
            // słowo osiągnie długość 13 liter

        word += letter;
        wordLength++;
    }
    return word;
}


// Poniżej są funkcje, które mają wyliczyć tablice prawdopodobieństw wystąpienia danych liter
// Zakładamy, że powinny to zrobić tylko raz na początku działania programu

vector<float> calcStartProb(){
    // np. wczytaj tekst z pliku i zliczaj wystąpienia konkretnych liter jako pierwszych
    // potem podziel przez liczbę wszystkich słów w pliku
    // *przy założeniu, że teskt w pliku składa się tylko z małych liter i przecinków (żadnych spacji, kresek, itp.)
}


vector<vector<float>> calcNextProb(){
    // np. wczytaj tekst z pliku i przechodząc litera po literze zliczaj wystąpienia danej litery po innej
    // potem podziel przez liczbę wystąpień wszystkich liter po danej literze
    // *przy założeniu, że teskt w pliku składa się tylko z małych liter i przecinków (żadnych spacji, kresek, itp.)
}

