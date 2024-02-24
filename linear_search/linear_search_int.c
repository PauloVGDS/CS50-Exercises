#include <stdio.h>
#include <cs50.h>
#include <string.h>
int main(void)
{
    // Lista de números
    int lista[] = {10,20,30,40,50,60,70,80,90,100};
    // Número alvo
    int num = get_int("Número: ");
    // Iteração em cada elemento da lista
    for (int i = 0; i < 10; i++)
    {
        // Se o elemento corresponde ao alvo...
        if (lista[i] == num)
        {
            printf("Achei!\n");
            return 0;
        }
    }
    // Se não...
    printf("Não achei!\n");
    return 1;
}