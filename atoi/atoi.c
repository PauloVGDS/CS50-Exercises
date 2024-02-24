#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);
int num = 0;
int main(void)
{
    string input = get_string("Enter a positive integer: ");

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    int len = strlen(input);
    int tint = 0;
    // Caso base
    if (len == 0)
    {
        return num;
    }
    // Caso recursivo
    for (int i = len - 1; i >= 0; i--)
    {
        tint = input[i] - '0';
        input[i] = '\0';
        convert(input);
        // parte executada na callstack
        num = num * 10 + tint;
        return num;
    }
    return num;
}