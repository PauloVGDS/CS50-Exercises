#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string names[] = {"Bill","Charlie","Fred","George","Ginny","Percy","Ron"};

    for (int i = 0; i < 7; i++)
    {
        if (strcmp(names[i], "Ron") == 0)
        {
            printf("Achei\n");
            return 0;
        }
    }
    printf("Não achei\n");
    return 1;
}