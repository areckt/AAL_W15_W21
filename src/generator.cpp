/*
 * Arkadiusz Dawid,     300199
 * Illia Yatskevich,    302211
 * Projekt AAL W15 W21 - Tablica mieszajaca
 */

#include <iostream>
#include <random>
#include <map>
#include <string>
#include <vector>
#include "../include/generator.h"

using namespace std;


string generateWord(vector<int> first_letter_dist, vector<vector<int>> second_letter_dist, vector<int> wordLength)
{
    char alfabet[] = "abcdefghijklmnopqrstuvwxyz";
    int word_length[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

    random_device device;
    mt19937 engine(device()); // Seed the random number engine
    discrete_distribution<> first_dist(first_letter_dist.begin(), first_letter_dist.end()); // Create the distribution
    discrete_distribution<> length_dist(wordLength.begin(), wordLength.end());

    string final_word;
    int random_letter_pos = first_dist(engine);
    int random_length = word_length[length_dist(engine)];
    char random_letter = alfabet[random_letter_pos];
    final_word.push_back(random_letter);
    for(int i = 1; i < random_length; ++i)
    {
        discrete_distribution<> second_dist(second_letter_dist.at(random_letter_pos).begin(), second_letter_dist.at(random_letter_pos).end());
        random_letter_pos = second_dist(engine);   
        random_letter = alfabet[random_letter_pos];
        final_word.push_back(random_letter);
        
    }
    //cout << "Generated: " << final_word << endl;
    return final_word;
    
}



// Poniżej są funkcje, które mają wyliczyć tablice prawdopodobieństw wystąpienia danych liter
// Zakładamy, że powinny to zrobić tylko raz na początku działania programu

vector<int> calcStartDist(vector<string> text)
{
    vector<int> first_letter_dist(26, 0);
    map<char, int> first_letter_map;
    for(unsigned int i = 0; i < text.size(); i++)
    {
        ++first_letter_map[text[i].at(0)];
    }
    for(auto p : first_letter_map) {
      
        for(int i = 97; i <= 122; ++i)
        {
            if(p.first == i)
            {
                first_letter_dist[i-97] = p.second;
            }
        }
    }
    cout << "[INFO] Calculated first_letter_dist" << endl;
    return first_letter_dist;
}


vector<vector<int>> calcSecondDist(vector<string> text)
{
    vector<vector<int>> second_letter_dist(26, vector<int>(26, 0));
    vector<string> second_letters;
    string next_letter;
    for(unsigned int i = 0; i < text.size(); ++i)
    {
        if(text.at(i).length() > 1)
        {
            for(unsigned int j = 0; j < (text.at(i).length() - 1); ++j)
            {
                next_letter.push_back(text.at(i).at(j));
                next_letter.push_back(text.at(i).at(j+1));
                second_letters.push_back(next_letter);
                next_letter.clear();
            }
        }

    }

    map<string, int> second_letter_map;
    
    for(unsigned int i = 0; i < second_letters.size(); ++i)
    {
        ++second_letter_map[second_letters.at(i)];
    }

    for(auto p : second_letter_map) {

        for(int i = 97; i <= 122; ++i)
        {
            for(int j = 97; j <= 122; ++j)
            {
                if(p.first.at(0) == i)
                {
                    if(p.first.at(1) == j)
                        second_letter_dist[i-97][j-97] = p.second;

                }

            }
        }
    }
    cout << "[INFO] Calculated second_letter_dist" << endl;
    return second_letter_dist;
}

vector<int> calcWordLengthDist(vector<string> text)
{
    vector<int> word_length_dist;
    map<int, int> length_map;

    for(unsigned int i = 0; i < text.size(); i++)
    {
        ++length_map[text[i].length()];
    }

    for(auto p : length_map) {
        word_length_dist.push_back(p.second);
    }
    cout << "[INFO] Calculated word_length_dist" << endl;
    return word_length_dist;
}

