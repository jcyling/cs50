#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    //Get text from user
    string text = get_string("Text: ");

    //Calculate grade using formula

    //Find letters and sentences
    int L = 0;
    int S = 0;
    int W = 1;


    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            L++;
        }
        else if (isspace(text[i]))
        {
            W++;
        }
        else if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            S++;
        }
    }


    //Resolve grade
    float averageLets = 100.00 * L / W;
    float averageStns = 100.00 * S / W;
    float index = 0.0588 * averageLets - 0.296 * averageStns - 15.8;

    int grade = round(index);

    //Print grade level
    if (grade < 1)
    {
        printf("Before Grade 1\n");

    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");

    }
    else
    {
        printf("Grade %i\n", grade);
    }
}