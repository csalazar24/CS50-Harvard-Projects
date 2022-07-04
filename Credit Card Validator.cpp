#include <stdio.h>

using namespace std;

int get_num_size(long long credit_card_number)
{

    int count = 0;

    while (credit_card_number != 0)
    {

        credit_card_number = credit_card_number / 10;
        count++;
    }

    return count;

}

int helper_check_sum(long long credit_card_number)
{

    int sum = 0;
    int amount_digits = get_num_size(credit_card_number);
    int every_other = 0;

    for (int i = 0; i < amount_digits - 1; i++)
    {
        //Get last
        every_other = credit_card_number % 10;
        //Delete last number
        credit_card_number = credit_card_number / 10;
        //Delete last number
        credit_card_number = credit_card_number / 10;

        sum += every_other;
    }

    return sum;
}

int check_sum(long long credit_card_number)
{
    int every_other_second_to_last = 0;
    int result_of_mult = 0;
    int sum = 0;
    int amount_digits = get_num_size(credit_card_number);
    int check_double_digits = 0;
    int total = 0;
    int every_other = helper_check_sum(credit_card_number);

    for (int i = 0; i < amount_digits - 1; i++)
    {
        //Delete last number
        credit_card_number = credit_card_number / 10;

        //Get second to last
        every_other_second_to_last = credit_card_number % 10;

        //Delete another to get another second to last next iteration
        credit_card_number = credit_card_number / 10;

        //result of multiplying by 2
        result_of_mult = every_other_second_to_last * 2;

        check_double_digits = get_num_size(result_of_mult);

        if (check_double_digits > 1)
        {

            for (int j = 0; j < check_double_digits; j++)
            {
                long temp = result_of_mult % 10;
                sum += result_of_mult % 10;
                result_of_mult = result_of_mult / 10;
            }
        }
        else
        {
            //add them to sum
            sum += result_of_mult;
        }
    }

    total = sum + every_other;

    return total;

}

bool check_last(long long result)
{
    long temp = result % 10;

    return temp == 0 ? true : false;
}

int get_first_nums(long long credit_cardnumber, int how_many_digits)
{
    long amount_digits = get_num_size(credit_cardnumber);
    int first_num = 0;

    for (int i = amount_digits; i > how_many_digits; i--)
    {
        credit_cardnumber = credit_cardnumber / 10;
    }

    first_num = credit_cardnumber;

    return first_num;

}

int main(void)
{
    long long credit_cardnumber = 0;
    printf("Number: ");

    scanf_s("%lld", &credit_cardnumber);
    
    long long result = check_sum(credit_cardnumber);

    bool is_it_valid = check_last(result);
    int card_length = get_num_size(credit_cardnumber);
    int firsttwo = get_first_nums(credit_cardnumber, 2);
    int firstnum = get_first_nums(credit_cardnumber, 1);

    //Checks what kind of card it is
    if ((firsttwo == 34 || firsttwo == 37) && card_length == 15 && is_it_valid)
    {
        printf("AMEX\n");
    }
    else if ((firsttwo == 51 || firsttwo == 52 || firsttwo == 53 || firsttwo == 54 || firsttwo == 55) && card_length == 16
        && is_it_valid)
    {
        printf("MASTERCARD\n");
    }
    else if (firstnum == 4 && (card_length == 13 || card_length == 16) && is_it_valid)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}



