/*
 * Arkadiusz Dawid,     300199
 * Illia Yatskevich,    302211
 * Projekt AAL W15 W21 - Tablica mieszajaca
 */

/*
    KOMPILACJA:     g++ utility.cpp -o prog -licuuc -licuio -licui18n
    URUCHOMIENIE:   ./prog < in.txt > out.txt
*/

#include <iostream>
#include <string>
#include <vector>
#include <unicode/utypes.h>
#include <unicode/unistr.h>
#include <unicode/translit.h>

using namespace std;

string desaxUTF8(const string& str) {
    // UTF-8 string -> UTF-16 UnicodeString
    UnicodeString source = UnicodeString::fromUTF8(StringPiece(str));

    // Transliterate UTF-16 UnicodeString
    UErrorCode status = U_ZERO_ERROR;
    Transliterator *accentsConverter = Transliterator::createInstance(
            "NFD; [:M:] Remove; NFC", UTRANS_FORWARD, status);
    accentsConverter->transliterate(source);

    // UTF-16 UnicodeString -> UTF-8 std::string
    std::string result;
    source.toUTF8String(result);

    return result;
}

string toLowerCase(string s)
{
    string result = s;
    for (int i = 0; i < result.size(); i++)
        if (result[i] >= 'A' && result[i] <= 'Z')
            result[i] = tolower(result[i]);
    return result;
}

string removePunctuation(string s){
    string result = "";
    for(int i = 0; i < s.length(); ++i){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            result += s[i];
        }
    }
    return result;
}

string transformLwithStroke(string temp){
    string word = "";
    for(int i = 0; i < temp.length(); ++i){
        if( (((int)temp.at(i) == -59) && ((int)temp.at(i+1) == -126)) ||
            (((int)temp.at(i) == -59) && ((int)temp.at(i+1) == -127))){
            word += 'l';
            i++;
        }
        else{
            word += temp.at(i);
        }
    }
    return word;
}

int main(){

    vector<string> text;
    vector<string>::iterator iter;
    string word;

    while(cin >> word){

        word = transformLwithStroke(word);  //transforms 'ł' and 'Ł' to 'l'
        word = desaxUTF8(word);             //transforms other diacritics
        word = removePunctuation(word);     //removes non-letters
        word = toLowerCase(word);           //changes every letter to lower case

        if(word.length() > 1)
            text.push_back(word);

    }


    for(int i = 0; i < text.size(); ++i){
        cout << text.at(i) << "\n";
    }

    return 0;
}