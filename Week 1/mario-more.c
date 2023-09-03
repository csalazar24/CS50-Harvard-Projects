//Written by Christopher Salazar 
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt the user to enter a number between 1 and 8
    int height = 0;
    do
    {
        height = get_int("Please enter a number between 1 and 8: ");
    }
    while (height > 8 || height <= 0);

    int temp = height - 2;

    // Build the pyramid
    for (int i = 0; i < height; i++)
    {
        // Print the spaces before the left pyramid
        for (int s = 0; s <= temp; s++)
        {
            printf(" ");
        }

        // Print the left pyramid
        for (int x = 0; x <= i; x++)
        {
            printf("#");
        }

        printf("  "); // Print the gap between the two pyramids

        // Print the right pyramid
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
        --temp;
    }
}
