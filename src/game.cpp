#include "../include/hangman.h"
#include <cctype>
#include <iostream>
#include <set>
#include <string>

void playGame() {
    constexpr int kMaxWrongGuesses = 6;

    const std::string secretWord = selectRandomWord();
    std::set<char> guessedLetters;
    int wrongGuesses = 0;

    std::cout << "=== Welcome to Hangman ===\n";

    while (wrongGuesses < kMaxWrongGuesses && !hasWon(secretWord, guessedLetters)) {
        displayHangman(wrongGuesses);
        displayWord(secretWord, guessedLetters);
        std::cout << "Wrong guesses: " << wrongGuesses << " / " << kMaxWrongGuesses << "\n";
        std::cout << "Enter a letter: ";

        std::string input;
        if (!(std::cin >> input)) {
            std::cin.clear();
            std::cout << "Invalid input. Please try again.\n";
            continue;
        }

        if (input.size() != 1) {
            std::cout << "Please enter a single character.\n";
            continue;
        }

        const unsigned char rawChar = static_cast<unsigned char>(input[0]);
        if (!std::isalpha(rawChar)) {
            std::cout << "Please enter a letter (A-Z).\n";
            continue;
        }

        const char guess = static_cast<char>(std::tolower(rawChar));
        if (guessedLetters.count(guess)) {
            std::cout << "You already guessed '" << guess << "'. Try another letter.\n";
            continue;
        }

        guessedLetters.insert(guess);

        if (secretWord.find(guess) != std::string::npos) {
            std::cout << "Good guess! '" << guess << "' is in the word.\n";
        } else {
            ++wrongGuesses;
            std::cout << "Sorry, '" << guess << "' is not in the word.\n";
        }
    }

    displayHangman(wrongGuesses);
    displayWord(secretWord, guessedLetters);

    if (hasWon(secretWord, guessedLetters)) {
        std::cout << "Congratulations! You guessed the word: " << secretWord << "\n";
    } else {
        std::cout << "Game over! The word was: " << secretWord << "\n";
    }
}
