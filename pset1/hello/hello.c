#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get name
    string name = get_string("What is your name?\n");

    //Print name
    printf("hello, %s\n", name);
}