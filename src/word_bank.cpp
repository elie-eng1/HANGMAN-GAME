
#include <vector>
#include <string>
#include <random>

#include "../include/hangman.h"

using namespace std;

// Function to select a random word
string selectRandomWord() {

    vector<string> words = {

        "teacher",
        "computer",
        "network",
        "programming",
        "university",
        "student",
        "database",
        "software",
        "keyboard",
        "internet"

    };

    random_device rd;
    mt19937 generator(rd());

    uniform_int_distribution<int> distribution(
        0,
        static_cast<int>(words.size()) - 1
    );

    return words[distribution(generator)];
}

