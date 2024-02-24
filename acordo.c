#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Você concorda?");
    if (c == 's')
    {
        printf("Concordo\n");
    }
    else if (c == 'n')
    {
        printf("Não concordo\n");
    }

}