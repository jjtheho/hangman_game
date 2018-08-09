// ** Note that this program cannot function without the modules and libraries provided by the University of Waterloo.
// In the beginning the player is prompt to provide a number between 1 and 200 (There are 200 hangman words).
// Once a valid number has been inputted, the player is prompt to guess the letters of the word through user input.
// The player will win if he/she guess the word correctly.
// If the player guess a letter not in the word six times, he/she will lose.
// Regardless of whether the player wins or loses the game,
// they will be prompted on whether they want to play the game again.
// The player can then input "y" to play again or "n" to end the game

#include <string.h>
#include "hangman-io.h"
#include "words.h"
#include "cs136.h"


int main(void) {
    while (1) {
        printf(enter_game_number, max_words);
        int n = 0;
        while (scanf("%d", &n) == 1) {
            if (n >= 1 && n <= max_words) {
                break;
            } else {
                printf(invalid_game_number, 0);
                printf(enter_game_number, max_words);
            }
        }
        const char *c = get_word(n);
        char update[50] = {};
        for (int j = 0; c[j] != '\0'; ++j) {
            if (c[j] == 32) {
                update[j] = c[j];
            } else {
                update[j] = '*';
            }
        }
        char guessed[26] = {};
        for (int i = 0; i <= max_strikes;) {
            print_hangman(i);
            printf(letter_prompt, 0);
            printf("%s\n", update);
            char choice = 0;
            while (scanf(" %c", &choice) == 1) {
                if ((choice < 'A' || choice > 'Z') &&
                    (choice < 'a' || choice > 'z')) {
                    printf(not_a_letter, choice);
                    print_hangman(i);
                    printf(letter_prompt, 0);
                } else if (choice >= 'a' && choice <= 'z') {
                    choice = choice - 'a' + 'A';
                    break;
                } else {
                    break;
                }
            }
            if (choice == guessed[choice - 'A']) {
                printf(already_guessed_letter, choice);
            } else {
                int count = 0;
                for (int k = 0; c[k] != '\0'; ++k) {
                    if (c[k] == choice) {
                        update[k] = choice;
                        ++count;
                    }
                }
                guessed[choice - 'A'] = choice;
                if (count <= 0) {
                    ++i;
                    if (i >= max_strikes) {
                        printf("%s\n", update);
                        printf(not_in_word, choice);
                        print_hangman(i);
                        printf(game_over, c);
                        break;
                    } else {
                        printf(not_in_word, choice);
                        printf(not_last_guess, max_strikes - i);
                    }
                }
                if (strcmp(c, update) == 0) {
                    printf(congratulations, c);
                    break;
                }
            }
        }
        printf(play_again, 0);
        char ans = 0;
        while (scanf(" %c", &ans) == 1) { // whitespace warning
            if (ans == 'Y' || ans == 'y') {
                break;
            } else if (ans == 'N' || ans == 'n') {
                return 0;
            } else {
                printf(invalid_play_again_response, 0);
                printf(play_again, 0);
            }
        }
    }
}
      
 