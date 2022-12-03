#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstring>


#define STR_SIZE 50
#define SIZE_ALPH 26
std::string FILE_PATH_IN = "D:\\C++Project\\Additional3\\text.txt";
std::string FILE_PATH_OUT = "D:\\C++Project\\Additional3\\output.txt";
std::string exceptions = " ,;\n'"".?!:(){}[]*&^%$#@-_=+\\|/0123456789";
std::string ALL_LITTERS_UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string ALL_LITTERS_LOWER = "abcdefghijklmnopqrstuvwxyz";
std::string upLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string downLetters = "abcdefghijklmnopqrstuvwxyz";
std::string word;




void searchMax(int *counter);

std::string remover(std::string str);


void outArrayS(int *counter) {
    for (int i = 0; i < SIZE_ALPH; i++) {
        if (counter[i] != 0)

            std::cout << upLetters[i] << " - " << counter[i] << std::endl;
    }


}

void changeWord(int index, std::string info){
    word[index] = (char) toupper(word[index] );
    word[index + 1] = (char) toupper(word[index+ 1]);
    word += "(";
    word.push_back(info[0]);
    word += ",";
    word.push_back(info[1]);
    word += ")";
}

bool checkForLetters(std::string &wordF) {
    bool flag = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::string strUp;
            strUp.push_back(upLetters[j]);
            strUp.push_back(upLetters[i]);
            std::transform(wordF.begin(), wordF.end(), wordF.begin(),
                           toupper);
            if ((wordF.find(strUp) != std::string::npos) and (upLetters[j] != upLetters[i])) {
                std::cout << strUp << std::endl;
                flag = true;
                int index = wordF.find(strUp);
                changeWord(index, strUp);

            }

        }

    }

    return flag;
}


void writeNewText() {
    std::ifstream file(FILE_PATH_IN);
    std::string  upperWord;
    while (!file.eof()) {
        file >> word;
        upperWord = word;

        checkForLetters(upperWord);
        std::cout << word << std::endl;


    }


}

int counts(std::string *s, std::string what, int j) {
    for (int i = 0; i < j; ++i) {
        if (s[i] == what)
            return false;
    }
    return true;
}




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
    //std::cout << upLetters << std::endl;
    //outArrayS(counterString);
    writeNewText();


    return 0;
}

void searchMax(int *counter) {
    for (int i = 0; i < SIZE_ALPH; i++) {
        for (int j = i; j < SIZE_ALPH; j++) {
            if (counter[i] < counter[j]) {
                std::swap(counter[i], counter[j]);
                std::swap(upLetters[i], upLetters[j]);
                std::swap(downLetters[i], downLetters[j]);
            }
        }

    }
    upLetters.resize(4);


}

std::string remover(std::string str) {
    std::string ret = "";
    for (char i: str) {
        if (exceptions.find(i) == std::string::npos)
            ret += i;
    }
    return ret;
}


