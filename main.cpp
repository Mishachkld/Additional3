#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>


#define STR_SIZE 40
#define SIZE_ALPH 33 // 26 размер алфавита
std::string FILE_PATH_IN = "input.txt";
std::string FILE_PATH_OUT = "output.txt";
std::string ALL_LITTERS_UPPER = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
std::string ALL_LITTERS_LOWER = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
std::string upLetters = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";  // строчка для сортировки букв по частоте использования в тексте
//std::string ALL_LITTERS_UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//std::string ALL_LITTERS_LOWER = "abcdefghijklmnopqrstuvwxyz";
//std::string upLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string word;


void searchMax(int *counter);

void changeWord(int index, std::string info);

void checkForLetters(std::string &wordF);

void writeNewText();

int main() {
    setlocale(0, "");
    std::ifstream file(FILE_PATH_IN);
    int counterString[STR_SIZE] = {0};
    std::string elements;
    while (getline(file, elements)) {
        for (int i = 0; i < ALL_LITTERS_UPPER.length(); i++) {
            counterString[i] += std::count(elements.begin(), elements.end(), ALL_LITTERS_UPPER[i]);
            counterString[i] += std::count(elements.begin(), elements.end(), ALL_LITTERS_LOWER[i]);
        }
    }
    file.close();
    searchMax(counterString);
    writeNewText();
    return 0;
}

void searchMax(int *counter) {
    for (int i = 0; i < SIZE_ALPH; i++) {
        for (int j = i; j < SIZE_ALPH; j++) {
            if (counter[i] < counter[j]) {
                std::swap(counter[i], counter[j]);
                std::swap(upLetters[i], upLetters[j]);
            }
        }

    }
    upLetters.resize(4);

}

void writeNewText() {
    std::ifstream fileIn(FILE_PATH_IN);
    std::ofstream fileOut(FILE_PATH_OUT);
    fileOut  << "В тексте чаще всего встречались эти буквы:" << " " << upLetters <<std::endl;
    std::string upperWord;
    while (!fileIn.eof()) {
        fileIn >> word;
        upperWord = word;
        checkForLetters(upperWord);
        fileOut << word << " ";
    }
    fileIn.close();
    fileOut.close();
}

void checkForLetters(std::string &wordF) {   // смотрим есть ли нужные нам комбинации
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::string strUp;
            strUp.push_back(upLetters[j]);
            strUp.push_back(upLetters[i]);
            std::transform(wordF.begin(), wordF.end(), wordF.begin(),
                           toupper);
            if ((wordF.find(strUp) != std::string::npos) and (upLetters[j] != upLetters[i])) {
                int index = wordF.find(strUp);
                changeWord(index, strUp);
            }
        }
    }
}

void changeWord(int index, std::string info) { // показываем, какие буквы встречаются и меняем слово
    word[index] = (char) toupper(word[index]);
    word[index + 1] = (char) toupper(word[index + 1]);
    word += "(";
    word.push_back(info[0]);
    word += ",";
    word.push_back(info[1]);
    word += ")";
}