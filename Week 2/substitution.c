//Written by Christopher Salazar 
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function prototype for the encipher function
string encipher(string plain_text, string key);

int main(int argc, string argv[])
{
    // Check for the correct number of command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    int key_length = strlen(key);
    string plain_text = "";
    int plain_text_length = 0;
    string cipher_text = "";

    // Check if the key contains exactly 26 characters
    if (key_length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Check if the key contains only alphabetic characters and no repeated characters
    for (int i = 0; i < key_length; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain letters.\n");
            return 1;
        }

        for (int j = i + 1; j < key_length; j++)
        {
            if (key[i] == key[j])
            {
                printf("Key cannot contain repeated characters.\n");
                return 1;
            }
        }
    }

    // Get the plaintext input from the user
    plain_text = get_string("plaintext: ");
    plain_text_length = strlen(plain_text);

    // Encrypt the plaintext using the provided key
    cipher_text = encipher(plain_text, key);

    // Print the ciphertext
    printf("ciphertext: %s\n", cipher_text);
}

// Function to encipher the plaintext using the given key
string encipher(string plain_text, string key)
{
    string cipher_text = plain_text;

    for (int i = 0; i < strlen(plain_text); i++)
    {
        if (isupper(plain_text[i]))
        {
            if (isupper(key[plain_text[i] - 65]))
            {
                cipher_text[i] = key[plain_text[i] - 65];
            }
            else
            {
                cipher_text[i] = toupper(key[plain_text[i] - 65]);
            }
        }
        else if (islower(plain_text[i]))
        {
            if (islower(key[plain_text[i] - 97]))
            {
                cipher_text[i] = key[plain_text[i] - 97];
            }
            else
            {
                cipher_text[i] = tolower(key[plain_text[i] - 97]);
            }
        }
    }

    return cipher_text;
}
