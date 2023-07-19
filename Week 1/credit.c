#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int do_the_math(long card_number, int card_digits_size)
{
    //It will hold the card number after removing the last digits
    long card_number_modified = card_number;

    //It will take a single digit from the card number
    int single_digit = 0;
    int result = 0;
    int temp = 0;

    for(int i = 0; i < card_digits_size; i++)
    {
        //Remove the last digit
        card_number_modified = card_number_modified / 10;

        //Get the last number
        single_digit =  card_number_modified % 10;

        if(single_digit * 2 > 9)
        {
            temp = single_digit * 2 % 10;
            result +=  temp;
            single_digit = single_digit * 2 / 10;
            result += single_digit;
        }
        else
        {
            // multiply by 2 and add the results
            result += single_digit * 2;
        }

        //Remove the last digit
        card_number_modified = card_number_modified / 10;

    }

    //Add the result to the sum of the digits that werent multiplied by 2
    for(int i = 0; i < card_digits_size; i++)
    {
        //Get the last number
        single_digit =  card_number % 10;

        //add the results
        result += single_digit;

        //Remove the last digit twice
        card_number /= 10;
        card_number /= 10;
    }

    return result;
}

int get_card_digits_size(long card_number)
{
    int card_digits_size = 0;

    while(card_number != 0)
    {
        card_number = card_number / 10;
        card_digits_size++;
    }

    return card_digits_size;
}

bool lunhs_algorithm(long card_number)
{

    //Get the number of digits of the card number
    int card_digits_size = 0;
    card_digits_size = get_card_digits_size(card_number);

    //This variable will be used to hold a single digit several times
    int single_digit = 0;
    int result = 0;

    result = do_the_math(card_number, card_digits_size);

    //Get the last number of the final result
    single_digit = result % 10;

    //Return true if the last digit is 0 and false otherwise
    return single_digit == 0 ? true : false;

}

int get_first_two(long credit_cardnumber, int card_digits_size)
{
    int first_two = 0;

    for (int i = card_digits_size; i > 2; i--)
    {
        credit_cardnumber = credit_cardnumber / 10;
    }

    first_two = credit_cardnumber;

    return first_two;

}

string classify_card(long card_number)
{
    int card_digits_size = 0;
    card_digits_size = get_card_digits_size(card_number);

    int first_two_numbers = 0;
    first_two_numbers = get_first_two(card_number, card_digits_size);

    int first_number = 0;
    first_number = first_two_numbers / 10;

    if ((first_two_numbers == 34 || first_two_numbers == 37) && card_digits_size == 15)
    {
        return "AMEX\n";
    }
    else if ((first_two_numbers == 51 || first_two_numbers == 52 || first_two_numbers == 53 || first_two_numbers == 54 || first_two_numbers == 55) && card_digits_size == 16)
    {
        return "MASTERCARD\n";
    }
    else if (first_number == 4 && ( card_digits_size == 13 ||  card_digits_size == 16))
    {
        return "VISA\n";
    }
    else
    {
        return "INVALID\n";
    }
}


int main(void){

    bool is_valid = false;

    long card_number = get_long("Please Enter the Card Number: ");

    is_valid = lunhs_algorithm(card_number);

    string card_type = "";

    card_type = classify_card(card_number);

    if(is_valid && strcmp(card_type, "INVALID") != 0)
    {
        printf("%s", card_type);
    }
    else
    {
        printf("INVALID\n");
    }

}