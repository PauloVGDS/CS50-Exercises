#include <stdio.h>
#include <cs50.h>
// Protótipo
int get_negative_int(void);

int main(void)

{
    // Receber inteiro negativo de usuário
    int i = get_negative_int();
    printf("%i\n",i);
}

int get_negative_int(void)
{
    int n;
    do
    {
        n = get_int("Inteiro Negativo: ");
    }
    while (n < 0);
    return n;
}