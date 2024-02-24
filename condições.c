#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");
    if (x < y)
    {
        printf("x é menor que y\n");
    }
    else if (y < x)
    {
        printf("x é maior que y\n");
    }
    else
    {
        printf("x é igual a y\n");
    }
}