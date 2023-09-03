//Written by Christopher Salazar 
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Function prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Get input text from the user
    string input = get_string("Text: ");

    // Count the number of letters, words, and sentences in the input text
    int letter_count = count_letters(input);
    int word_count = count_words(input);
    int sentence_count = count_sentences(input);

    // Calculate the average number of letters and sentences per 100 words
    float L = (letter_count * 100.0) / word_count;
    float S = (sentence_count * 100.0) / word_count;

    // Calculate the Coleman-Liau index
    float result = 0.0588 * L - 0.296 * S - 15.8;

    // Determine the reading grade level and print the result
    if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (result >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(result));
    }
}

// Function to count the number of letters in a string
int count_letters(string text)
{
    int count = 0;
    int string_length = strlen(text);

    for (int i = 0; i < string_length; i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        {
            count++;
        }
    }

    return count;
}

// Function to count the number of words in a string
int count_words(string text)
{
    int count = 1; // Start with 1 because the first word is already counted
    int string_length = strlen(text);

    for (int i = 0; i < string_length; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }

    return count;
}

// Function to count the number of sentences in a string
int count_sentences(string text)
{
    int count = 0;
    int string_length = strlen(text);

    for (int i = 0; i < string_length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }

    return count;
}
