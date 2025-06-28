#include <iostream>
#include <string>
using namespace std;

void hangmanGame() {
    
    string secretWord = "COMPUTER";
    string guessedWord = "________"; //8 underscores for 8 letters
    int wrongGuesses = 0;
    int maxWrong = 6;
    char guess = 'a';
    bool gameWon = false;
    

    //!gameWon is just a way of making the boolean value true to initiate the loop
    while (wrongGuesses < maxWrong && !gameWon) { 
        cout << "Word: " << guessedWord << endl;
        cout << "Wrong Guesses: " << wrongGuesses << "/" << maxWrong << endl;

        cout << "Enter a letter: ";
        cin >> guess;

        bool foundLetter = false;
        for (int i = 0; i < secretWord.length(); i++) {
            if (secretWord[i] == guess) {
                guessedWord[i] = guess;
                foundLetter = true;
            }
        }

        if (!foundLetter) {
            wrongGuesses++;
            cout << "Wrong! That letter is not in the word." << endl;
        } else {
            cout << "Good guess!" << endl;
        }

        if (guessedWord == secretWord) {
            gameWon = true;
        }
    
    }

    if (gameWon) {
            cout << "You won! The word was: " << secretWord << endl;
        } else {
            cout << "You lost! The word was: " << secretWord << endl;
        }
}

int main() {
    
    hangmanGame();
    
    return 0;
}