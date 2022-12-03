#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>


#define STR_SIZE 50
#define SIZE_ALPH  26
std::string FILE_PATH_IN = "Text.txt";
std::string FILE_PATH_OUT = "output.txt";
std::string exceptions = " ,;\n'"".?!:(){}[]*&^%$#@-_=+\\|/0123456789";
std::string ALL_LITTERS_UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string changed_litters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string ALL_LITTERS_LOWER = "abcdefghijklmnopqrstuvwxyz";
char maxLitters[4];
int N;

void outArray(std::string *myString);

void outArrayS(int *counter) {
	for (int i = 0; i < SIZE_ALPH; i++) {
		if (counter[i] != 0)

			std::cout << changed_litters[i] << " - " << counter[i] << std::endl;
	}


}

void searchMax(int *counter) {
	for (int i = 0; i < SIZE_ALPH; i++) {
		for (int j = i; j < SIZE_ALPH; j++) {
			if (counter[i] < counter[j]) {
				std::swap(counter[i], counter[j]);
				std::swap(changed_litters[i], changed_litters[j]);
			}
		}

	}
	changed_litters.resize(4);


}

void chekForLetters(std::string &word) {
	for (int i = 0; i < 4; i++) {
		for (int j = i+1; j < 3; j++) {
			char str = changed_litters[i] + changed_litters[j];
			if (word.find(str) != std::string::npos) {
				word[word.find(str)] = toupper(word[word.find(str)]);
				word[word.find(str) + 1] = toupper(word[word.find(str)+1]);
				std::cout << word << std::endl;
				std::cout << word.find(str);

			}
				
		}

	}


}


void writeNewText() {
	std::ifstream file(FILE_PATH_IN);
	std::string word;
	while (!file.eof()) {
		file >> word;
		chekForLetters(word);
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


std::string remover(std::string str) {
	std::string ret = "";
	for (char i : str) {
		if (exceptions.find(i) == std::string::npos)
			ret += i;
	}
	return ret;
}


int main() {
	setlocale(0, "");
	std::ifstream file(FILE_PATH_IN);
	int counterString[STR_SIZE] = { 0 };
	std::string elements;

	while (getline(file, elements)) {
		for (int i = 0; i < ALL_LITTERS_UPPER.length(); i++) {
			counterString[i] += std::count(elements.begin(), elements.end(), ALL_LITTERS_UPPER[i]);
			counterString[i] += std::count(elements.begin(), elements.end(), ALL_LITTERS_LOWER[i]);
		}
	}

	file.close();
	searchMax(counterString);
	//std::cout << changed_litters << std::endl;
	//outArrayS(counterString);
	writeNewText();



	system("pause");
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
