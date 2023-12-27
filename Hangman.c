#include <stdio.h>
#include<conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 6
#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

char* words[MAX_WORDS] = {
    "computer",
    "programming",
    "hangman",
    "language",
    "keyboard",
    "developer",
    "challenge",
    "victory",
    "algorithm",
    "function"
};

int main() {
    srand(time(0));
    char word[MAX_WORD_LENGTH];
    char guessed[MAX_WORD_LENGTH];
    int tries = 0;
    int wordLength;
    int i;

    strcpy(word, words[rand() % MAX_WORDS]);
    wordLength = strlen(word);

    for (i = 0; i < wordLength; i++) {
        guessed[i] = '_';
    }
    guessed[wordLength] = '\0';

    printf("Welcome to Hangman!\n");

    while (tries < MAX_TRIES) {
        printf("\nCurrent word: %s\n", guessed);
        printf("Tries left: %d\n", MAX_TRIES - tries);
        printf("Enter a letter: ");

        char guess;
        scanf(" %c", &guess);

        int correctGuess = 0;

        for (i = 0; i < wordLength; i++) {
            if (word[i] == guess && guessed[i] != guess) {
                guessed[i] = guess;
                correctGuess = 1;
            }
        }

        if (!correctGuess) {
            tries++;
            printf("Incorrect guess!\n");
        }

        int wordGuessed = 1;

        for (i = 0; i < wordLength; i++) {
            if (guessed[i] == '_') {
                wordGuessed = 0;
                break;
            }
        }

        if (wordGuessed) {
            printf("\nCongratulations! You guessed the word: %s\n", word);
            break;
        }
    }

    if (tries == MAX_TRIES) {
        printf("\nYou're out of tries! The word was: %s\n", word);
    }

    printf("Thanks for playing Hangman!\n",getch());
    
    return 0;
}
