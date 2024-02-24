#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declaração de Variáveis
    int ano = 0;
    int populacao_por_ano;
    // Declara a variável 'populacao_inicial' e recebe o valor do usuário
    int populacao_inicial = get_int("População: ");
    // Loop para caso a população inicial seja menor que 9
    while (populacao_inicial < 9)
    {
        populacao_inicial = get_int("População Inicial: ");
    }
    // Declara a variável 'populacao_final' e recebe o valor do usuário
    int populacao_final = get_int("População Final: ");
    // Loop para caso a população final seja menor que a população inicial
    while (populacao_final < populacao_inicial)
    {
        populacao_final = get_int("População Final: ");
    }
    // Loop para fazer o calculo dos anos
    while (populacao_inicial < populacao_final)
    {
        // Cálculo
        int nascimentos = populacao_inicial / 3;
        int mortes = populacao_inicial / 4;
        populacao_inicial = populacao_inicial + nascimentos - mortes;
        // Contador
        ano++;
        // Resetando as variáveis do calculo
        nascimentos = mortes = 0;


    }
    // Exibindo os anos
    printf("Years: %i", ano);
    
}
