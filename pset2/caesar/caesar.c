#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    // Check key input
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int j = 0; j < strlen(argv[1]); j++)
    {
        if (isdigit(argv[1][j]) == 1)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // Store int 'key' as string
    int key = atoi(&argv[1][0]);

    if (key < 1)
    {
        printf("Try again with a positive integer after execution.\n");
        return 1;
    }

    else
    {
        // Ask for code
        string input = get_string("plaintext:");

        printf("ciphertext: ");

        // Enciphering each letter
        for (int i = 0; i < strlen(input); i++)
        {

            // Alphabetical:
            if (isalpha(input[i]))
            {

                // Uppercase encipher:
                if (isupper(input[i]))
                {
                    int output = (input[i] + key - 'A') % 26;
                    printf("%c", output + 'A');
                }

                // Lowercase encipher:
                else if (islower(input[i]))
                {
                    int output = (input[i] + key - 'a') % 26;
                    printf("%c", output + 'a');
                }

            }

            // Non-alphabetical:
            else
            {
                printf("%c", input[i]);
            }

        }

        printf("\n");

    }
}
