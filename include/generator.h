/*
 * Arkadiusz Dawid,     300199
 * Illia Yatskevich,    302211
 * Projekt AAL W15 W21 - Tablica mieszajaca
 */

#ifndef AAL_GENERATOR_H
#define AAL_GENERATOR_H

std::wstring generateWord(std::vector<int> calcStartDist, std::vector<std::vector<int>> calcSecondDist, std::vector<int> calcWordLengthDist);
std::vector<int> calcStartDist(std::vector<std::wstring> text);
std::vector<std::vector<int>> calcSecondDist(std::vector<std::wstring> text);
std::vector<int> calcWordLengthDist(std::vector<std::wstring> text);
std::wstring cleanText(std::wstring text);

#endif //AAL_GENERATOR_H
