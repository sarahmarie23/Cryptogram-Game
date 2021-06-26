#include <iostream>
#include <string>
#include <ctime>
#include <map>
using namespace std;

int main() {
   
    string sample = "THIS IS THE SAMPLE SENTENCE";
    string decoded{""};
    const int ALPHABET_SIZE{26};
    char letters[ALPHABET_SIZE] = {};
    char scrambled[ALPHABET_SIZE] = {};
    srand(static_cast<unsigned int>(time(0)));
    map <char, char> alphaMap;

    void shuffle(char scramble[], int length);
    bool checkIfEqual(char letters[], char scrambled[], int length);
    string encryptSentence(string sentence, map<char, char>alphaMap);

    //start with an array of the letters
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        char current = 'A';
        letters[i] = (current + i);
    }

    //copy the array
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        scrambled[i] = letters[i];
    }

    //then shuffle them
    //index can't equal i; check and redo shuffle if needed
    do {
        (shuffle(scrambled, ALPHABET_SIZE));
    } while (checkIfEqual(letters, scrambled, ALPHABET_SIZE) == true);

    //build the map with the 2 arrays 
    for (int index = 0; index < ALPHABET_SIZE; index++) {

        alphaMap.insert(pair<char, char>(letters[index], scrambled[index]));
    }
    //encrypt the sentence
    decoded = encryptSentence(sample, alphaMap);

    //final result
    std::cout << "Original sentence: " << sample << endl;
    std::cout << "Decoded sentence: " << decoded << endl;
   
    return 0;
}

void shuffle(char scramble[], int length) {

    for (int i = 0; i < length; i++) {
        int index = rand() % length;
        
        while (index == i) { //if you get the same index, keep trying until you get a new one
            index = rand() % length;
        }

        char temp = scramble[i];
        scramble[i] = scramble[index];
        scramble[index] = temp;
    }
}

bool checkIfEqual(char letters[], char scrambled[], int length) {
    for (int i = 0; i < length; i++) {
        if (letters[i] == scrambled[i]) {
            return true;
        }
    }
    return false;
}

string encryptSentence(string sentence, map<char, char>alphaMap) {
    string decoded{ "" };
    for (int index = 0; index < sentence.length(); index++) {
        char current = sentence.at(index);
        char add;
        
        if (isalpha(current)) {
            add = alphaMap.at(current);
        }
        else {
            add = current;
        }
        decoded.push_back(add);
    }
    return decoded;
}
