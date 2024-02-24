#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int n;
    int aux = 0;
    do
    {
        n = get_int("Altura: ");
    }
    while (n < 1 || n > 8);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf(".");
        }
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}





