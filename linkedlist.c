#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int num;
    struct node *next;
}
node;

// Função para liberar a memória alocada.
// Recebe um nó de parâmetro
int freelist(node *cursor)
{
    // O nó cursor é um ponteiro, logo armazena um endereço na memória
    // Enquanto o nó cursor não for NULO
    while (cursor != NULL)
    {
        // Criamos um nó temporário que é igual ao cursor;
        node *tmp = cursor;
        // O cursor recebe o endereço do próximo termo da lista
        cursor = cursor->next;
        // Tmp era um endereço que tinha o primeiro termo da
        // Liberamos o nó tmp porque o cursor já avançou para o próximo da lista
        free(tmp);
    }
    // Se tudo deu certo então retorna 0
    return 0;

}

int main(void)
{
    printf("Digite um número: ");
    int n;
    scanf("%i",&n);
    node *list = malloc(sizeof(node));
    if (list == NULL)
    {
        return 1;
    }
    list = NULL;
    while (n != 0)
    {
        node *temp = malloc(sizeof(node));
        if (temp == NULL)
        {
            free(list);
            return 2;
        }
        temp->num = n;
        temp->next = NULL;

        temp->next = list;
        list = temp;
        n--;
    }

    node *cursor = list;

    while (cursor != NULL)
    {
        printf("%i\n",cursor->num);
        cursor = cursor->next;
    }
    cursor = list;
    freelist(cursor);
    return 0;
}