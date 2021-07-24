#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user for height
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);


    //Print pyramid
    for (int j = 1; j <= n; j++)
    {
        //Print space
        for (int k = n; k > j; k--)
        {
            printf(" ");
        };

        //Print hash
        for (int i = 1; i <= j; i++)
        {
            printf("#");
        };
        printf("\n");
    }
}

