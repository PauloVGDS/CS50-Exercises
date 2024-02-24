#include <stdio.h>
#include <cs50.h>
#include <string.h>
int main(void)
{

    string lista[] = {"battleship","boot","cannon","iron","thimble","top hat"};

    string str = get_string("String: ");

    for (int i = 0; i < 6; i++)
    {

        if (strcmp(lista[i], str) == 0)
        {
            printf("Achei!\n");
            return 0;
        }
    }

    printf("Não achei!\n");
    return 1;
}