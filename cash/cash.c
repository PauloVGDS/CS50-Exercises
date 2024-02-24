#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // Pergunta quanto troco ainda é devido
    int moeda = 0;
    do
    {
        moeda = get_int("Troco devido: ");
    }
    while (moeda < 0);
    return moeda;
}

int calculate_quarters(int cents)
{
    // Calcula a quantidade de moedas de 25 centavos (quarters)
    int quarts = 0;
    int centavos = cents;

    if (centavos > 0)
    {
        for (int c = 1; centavos > 24; c++)
    {
        centavos -= 25;
        quarts = c;
    }
    }
    return quarts;
}

int calculate_dimes(int cents)
{
    // Calcula a quantidade de moedas de 10 centavos (dimes)
    int dimes = 0;
    int centavos = cents;

    if (centavos > 0)
    {
        for (int c = 1; centavos > 9; c++)
    {
        centavos -= 10;
        dimes = c;
    }
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    // Calcula a quantidade de moedas de 5 centavos (nickels)
    int nickels = 0;
    int centavos = cents;

    if (centavos > 0)
    {
        for (int c = 1; centavos > 4; c++)
    {
        centavos -= 5;
        nickels = c;
    }
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    // Calcula a quantidade de moedas de 1 centavo (pennies)
    int pennies = 0;
    int centavos = cents;

    if (centavos > 0)
    {
        for (int c = 1; centavos > 0; c++)
    {
        centavos -= 1;
        pennies = c;
    }
    }
    return pennies;
}
