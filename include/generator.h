/*
 * Arkadiusz Dawid,     300199
 * Illia Yatskevich,    302211
 * Projekt AAL W15 W21 - Tablica mieszajaca
 */

#ifndef AAL_GENERATOR_H
#define AAL_GENERATOR_H

std::string generateWord(std::vector<int> calcStartDist, std::vector<std::vector<int>> calcSecondDist, std::vector<int> calcWordLengthDist);
std::vector<int> calcStartDist(std::vector<string> text);
std::vector<std::vector<int>> calcSecondDist(std::vector<string> text);
std::vector<int> calcWordLengthDist(std::vector<string> text);

#endif //AAL_GENERATOR_H
