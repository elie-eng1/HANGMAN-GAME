#ifndef HANGMAN_H
#define HANGMAN_H

#include <set>
#include <string>

void displayHangman(int wrongGuesses);
void displayWord(const std::string& word, const std::set<char>& guessedLetters);
bool hasWon(const std::string& word, const std::set<char>& guessedLetters);
std::string selectRandomWord();
void playGame();

#endif
