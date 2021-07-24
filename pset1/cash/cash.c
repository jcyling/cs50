#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Prompt change;
    float dollars;
    do
    {
        dollars = get_float("Change owed:");
    }
    while (dollars < 0);

    //Transform into cents
    int change = round(dollars * 100);

    //Find maximum number of coin
    int quarter = 0;
    int dime = 0;
    int nickel = 0;
    int penny = 0;

    //Divide by coins
    int r = change;
    while (r >= 25)
    {
        quarter = r / 25;
        r = r % 25;
    };

    while(r >= 10)
    {
        dime = r / 10;
        r = r % 10;
    }

    while(r >= 5)
    {
        nickel = r / 5;
        r = r % 5;
    }

    penny = r;

    int coins = penny + nickel + dime + quarter;

    //Print coins to user
    printf("%i\n", coins);


};