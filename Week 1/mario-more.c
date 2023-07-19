#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    do
    {

        height = get_int("Please enter a number between 1 and 8: ");

    }
    while (height > 8 || height <= 0);


    int temp = height - 2;

    for (int i = 0; i < height; i++)
    {
        for (int s = 0; s <= temp; s++)
        {
            printf(" ");

        }
        for (int x = 0; x <= i; x++)
        {
            printf("#");
        }

        printf("  ");
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
        --temp;
    }
}