#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char *a = get_string("a: ");
    char *b = get_string("b: ");
    if (*a == *b)
    {
        printf("Iguais.\n");
    }
    else
    {
        printf("Diferentes.\n");
    }
}