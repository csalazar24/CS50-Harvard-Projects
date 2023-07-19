#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

/**
 * This function performs the necessary calculations required by the Luhn's algorithm
 * to validate the credit card number.
 * @param card_number The credit card number
 * @param card_digits_size The number of digits in the credit card number
 * @return The calculated result
 */
int do_the_math(long card_number, int card_digits_size)
{
    // It will hold the card number after removing the last digits
    long card_number_modified = card_number;

    // It will take a single digit from the card number
    int single_digit = 0;
    int result = 0;
    int temp = 0;

    for (int i = 0; i < card_digits_size; i++)
    {
        // Remove the last digit
        card_number_modified = card_number_modified / 10;

        // Get the last number
        single_digit = card_number_modified % 10;

        if (single_digit * 2 > 9)
        {
            temp = single_digit * 2 % 10;
            result += temp;
            single_digit = single_digit * 2 / 10;
            result += single_digit;
        }
        else
        {
            // Multiply by 2 and add the results
            result += single_digit * 2;
        }

        // Remove the last digit
        card_number_modified = card_number_modified / 10;
    }

    // Add the result to the sum of the digits that weren't multiplied by 2
    for (int i = 0; i < card_digits_size; i++)
    {
        // Get the last number
        single_digit = card_number % 10;

        // Add the results
        result += single_digit;

        // Remove the last digit twice
        card_number /= 10;
        card_number /= 10;
    }

    return result;
}

/**
 * This function calculates the number of digits in the given credit card number.
 * @param card_number The credit card number
 * @return The number of digits in the credit card number
 */
int get_card_digits_size(long card_number)
{
    int card_digits_size = 0;

    while (card_number != 0)
    {
        // Remove the last digit
        card_number = card_number / 10;
        card_digits_size++;
    }

    return card_digits_size;
}

/**
 * This function implements the Luhn's algorithm to validate the credit card number.
 * @param card_number The credit card number
 * @return True if the credit card number is potentially valid, false otherwise
 */
bool lunhs_algorithm(long card_number)
{
    // Get the number of digits of the card number
    int card_digits_size = 0;
    card_digits_size = get_card_digits_size(card_number);

    // This variable will be used to hold a single digit several times
    int single_digit = 0;
    int result = 0;

    result = do_the_math(card_number, card_digits_size);

    // Get the last number of the final result
    single_digit = result % 10;

    // Return true if the last digit is 0 and false otherwise
    return single_digit == 0 ? true : false;
}

/**
 * This function extracts the first two digits from the credit card number.
 * @param credit_cardnumber The credit card number
 * @param card_digits_size The number of digits in the credit card number
 * @return The first two digits of the credit card number
 */
int get_first_two(long credit_cardnumber, int card_digits_size)
{

    for (int i = card_digits_size; i > 2; i--)
    {
        // Remove the last digit
        credit_cardnumber = credit_cardnumber / 10;
    }

    return credit_cardnumber;
}

/**
 * This function determines the type of credit card based on the credit card number.
 * @param card_number The credit card number
 * @return The card type as a string ("AMEX", "MASTERCARD", "VISA", or "INVALID")
 */
string classify_card(long card_number)
{
    // Get the number of digits in the credit card number
    int card_digits_size = 0;
    card_digits_size = get_card_digits_size(card_number);

    // Extract the first two digits of the credit card number
    int first_two_numbers = 0;
    first_two_numbers = get_first_two(card_number, card_digits_size);

    // Extract the first digit from the first two numbers
    int first_number = 0;
    first_number = first_two_numbers / 10;

    if ((first_two_numbers == 34 || first_two_numbers == 37) && card_digits_size == 15)
    {
        return "AMEX\n"; // American Express card
    }
    else if ((first_two_numbers >= 51 && first_two_numbers <= 55) && card_digits_size == 16)
    {
        return "MASTERCARD\n"; // Mastercard
    }
    else if (first_number == 4 && (card_digits_size == 13 || card_digits_size == 16))
    {
        return "VISA\n"; // Visa card
    }
    else
    {
        return "INVALID\n"; // Invalid card
    }
}

int main(void)
{
    bool is_valid = false;

    // Prompt the user to enter the credit card number
    long card_number = get_long("Please Enter the Card Number: ");

    // Validate the credit card number using the Luhn's algorithm
    is_valid = lunhs_algorithm(card_number);

    string card_type = "";

    // Determine the type of credit card based on the number
    card_type = classify_card(card_number);

    // Print the result
    if (is_valid && strcmp(card_type, "INVALID") != 0)
    {
        printf("%s", card_type);
    }
    else
    {
        printf("INVALID\n");
    }
}
