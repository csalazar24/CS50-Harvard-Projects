//Written by Christopher Salazar 
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Function to compute the score for a given word
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: "); // Prompting Player 1 for a word
    string word2 = get_string("Player 2: "); // Prompting Player 2 for a word

    // Score both words
    int score1 = compute_score(word1); // Calculate the score for Player 1's word
    int score2 = compute_score(word2); // Calculate the score for Player 2's word

    // Determine the winner based on the scores
    if (score1 > score2)
    {
        printf("Player 1 wins!\n"); // Player 1 has a higher score
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n"); // Player 2 has a higher score
    }
    else
    {
        printf("Tie!\n"); // Both players have the same score
    }
}

// Function to compute the score for a given word
int compute_score(string word)
{
    int word_size = strlen(word); // Get the length of the word
    int score = 0;

    for (int i = 0; i < word_size; i++)
    {
        if (word[i] >= 'A' && word[i] <= 'z')
        {
            if (islower(word[i]))
            {
                word[i] = toupper(word[i]); // Convert lowercase letters to uppercase
            }

            score = score + POINTS[word[i] - 65]; // Calculate the score for the letter
        }
    }

    return score; // Return the total score for the word
}
