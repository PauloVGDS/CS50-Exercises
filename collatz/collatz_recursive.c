#include <stdio.h>
#include <cs50.h>

int collatz(int n);

int main(void)
{
    int num = get_int("Número: ");
    collatz(num);
}

int collatz(int n)
{
    int count = 0;
    if (n == 1)
    {
        printf("%i\n",count);
        return count;
    }
    // Números pares
    else if ((n % 2) == 0)
    {
        count += 1;
        printf("%i\n",count);
        return 1 + collatz(n/2);
    }
   // Números Ímpares
    else
    {
        count += 1;
        printf("%i",count);
        return 1 + collatz(3*n + 1);
    }
    printf("%i\n",count);
}