#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>


#define STR_SIZE 50
#define SIZE_ALPH  26
std::string FILE_PATH_IN = "D:\\C++Project\\Additional3\\text.txt";
std::string FILE_PATH_OUT = "output.txt";
std::string exceptions = " ,;\n'"".?!:(){}[]*&^%$#@-_=+\\|/0123456789";
std::string ALL_LITTERS_UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string ALL_LITTERS_LOWER = "abcdefghijklmnopqrstuvwxyz";
char maxLitters[4];
int N;

void outArray(std::string *myString);

void outArrayS(int *counter) {
    for (int i = 0; i < SIZE_ALPH; i++) {
        if (counter[i] != 0)
            std::cout << ALL_LITTERS_UPPER[i] << " - " << counter[i] << std::endl;
    }


}

void searchMax(int *counter) {
    int max = 0;
    int k = 0;
    for (int i = 0; i < SIZE_ALPH; i++) {
        if (counter[i] > max) {
            max = counter[i];
            k = i;
        }
    }
    maxLitters[0] = ALL_LITTERS_UPPER[k]; // максимиум
    for (int i = 1; i < 4; i++) {
            if (ALL_LITTERS_UPPER.find());
        }



}


int counts(std::string *s, std::string what, int j) {
    for (int i = 0; i < j; ++i) {
        if (s[i] == what)
            return false;
    }
    return true;
}


std::string remover(std::string str) {
    std::string ret = "";
    for (char i: str) {
        if (exceptions.find(i) == std::string::npos)
            ret += i;
    }
    return ret;
}


int main() {
    setlocale(0, "");
    std::ifstream file(FILE_PATH_IN);
    int counterString[STR_SIZE] = {0};
    std::string elements;

    //    while (!file.eof()) {
    while (getline(file, elements)) {
        for (int i = 0; i < ALL_LITTERS_UPPER.length(); i++) {
            counterString[i] += std::count(elements.begin(), elements.end(), ALL_LITTERS_UPPER[i]);
            counterString[i] += std::count(elements.begin(), elements.end(), ALL_LITTERS_LOWER[i]);
        }
        file.close();
        outArrayS(counterString);


    }


    //    delete[] elements;
    return 0;
}


void outArray(std::string *myString) {
    std::ofstream file(FILE_PATH_OUT, std::ios::out);
    for (int i = 0; i < N; i++) {
        if (!myString[i].empty()) {
            std::cout << myString[i] << " ";
            //            file << myString[i] << std::endl;
        }
    }
    std::cout << std::endl;

    file.close();
}