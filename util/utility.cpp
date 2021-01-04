#include <iostream>
#include <fstream>
#include <sstream>
#include <locale>
#include <vector>

using namespace std;

wstring cleanText(wstring text)
{
    wstring final_text = text;
    for(unsigned long i = 0; i < final_text.length(); ++i)
    {
        
        switch (final_text.at(i))
        {
        case L'\x104':    
        case L'\x105':
        case L'\x0e1':
            final_text.at(i) = 'a';
            break;
        case L'\x118':        
        case L'\x119':
            final_text.at(i) = 'e';
            break;
        case L'\x106':    
        case L'\x107':
            final_text.at(i) = 'c';
            break;
        case L'\x0d3':    
        case L'\x0f3':
            final_text.at(i) = 'o';
            break;
        case L'\x15a':    
        case L'\x15b':
            final_text.at(i) = 's';
            break;
        case L'\x17b':    
        case L'\x17c':
        case L'\x179':    
        case L'\x17a':
            final_text.at(i) = 'z';
            break;
        case L'\x141':    
        case L'\x142':
            final_text.at(i) = 'l';
            break;
        case L'\x143':    
        case L'\x144':
            final_text.at(i) = 'n';
            break;                                
        default:
            
            break;
        }

        if(!isalpha(final_text.at(i)))
        {
            final_text.at(i) = ' ';
        }
        if(isupper(final_text.at(i)))
        {
            final_text.at(i) += 32;
        }
        
    }

    return final_text;
} 

int main()
{
    setlocale( LC_ALL, "C.UTF-8" );
    wifstream file("pan-tadeusz.txt");
    wofstream out("out.txt");
    file.imbue(std::locale("C.UTF-8"));
    out.imbue(std::locale("C.UTF-8"));
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
    stream1 << file.rdbuf();

    while(stream1 >> word)
    {
        cleaned_word = cleanText(word) + L' ';
        stream2 << cleaned_word;
    }

    out << stream2.rdbuf();


    return 0;
}
