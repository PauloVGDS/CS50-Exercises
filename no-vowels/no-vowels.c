// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int replace(string word[]);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        replace(&argv[1]);
        return 0;
    }
    else
    {
        printf("Mínimo de uma palavra!\n");
        return 1;
    }
}

int replace(string word[])
{
    int len = strlen(word[0]);
    for (int c = 0; c < len; c++)
    {
        switch (word[0][c])
        {
            case 'a':
                printf("6");
                break;

            case 'e':
                printf("3");
                break;
            case 'i':
                printf("1");
                break;
            case 'o':
                printf("0");
                break;
            default:
                printf("%c",word[0][c]);
                break;
        }
    }
        printf("\n");
        return 0;
}
