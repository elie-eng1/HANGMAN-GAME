
#include <iostream>
#include "../include/hangman.h"

using namespace std;

// Function to display the hangman drawing
void displayHangman(int wrongGuesses) {

    cout << "\n";

    cout << " +---+\n";

    if (wrongGuesses >= 1)
        cout << " |   |\n";
    else
        cout << " |\n";

    if (wrongGuesses >= 2)
        cout << " O   |\n";
    else
        cout << "     |\n";

    if (wrongGuesses == 3)
        cout << " |   |\n";
    else if (wrongGuesses == 4)
        cout << "/|   |\n";
    else if (wrongGuesses >= 5)
        cout << "/|\\  |\n";
    else
        cout << "     |\n";

    if (wrongGuesses >= 6)
        cout << "/ \\  |\n";
    else
        cout << "     |\n";

    cout << "     |\n";
    cout << "=========\n";
}

// Function to display the hidden word
void displayWord(
    const string& word,
    const set<char>& guessedLetters
) {

    cout << "\nWord: ";

    for (char letter : word) {

        if (guessedLetters.count(letter))
            cout << letter << " ";
        else
            cout << "_ ";
    }

    cout << "\n";
}

// Function to check whether the player has won
bool hasWon(
    const string& word,
    const set<char>& guessedLetters
) {

    for (char letter : word) {

        if (!guessedLetters.count(letter))
            return false;
    }

    return true;
}

