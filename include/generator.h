/*
 * Arkadiusz Dawid,     300199
 * Illia Yatskevich,    302211
 * Projekt AAL W15 W21 - Tablica mieszajaca
 */

#ifndef AAL_GENERATOR_H
#define AAL_GENERATOR_H

std::string generateWord(std::vector<float> startProbability, std::vector<std::vector<float>> nextProbability);
std::vector<float> calcStartProb(void);
std::vector<std::vector<float>> calcNextProb(void);

#endif //AAL_GENERATOR_H