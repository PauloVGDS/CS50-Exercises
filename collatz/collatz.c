#include <stdio.h>
#include <cs50.h>

void collatz(int n);

int main(void)
{
    int num = get_int("Número: ");
    collatz(num);
}

void collatz(int n)
{
    int count = 0;
    int num = n;
    if (num != 1)
    {
        while (num != 1)
        {
            if (num % 2 == 0)
            {
                num = num / 2;
                count += 1;
            }
            if (num % 2 != 0 && num != 1)
            {
                num = 3*num + 1;
                count += 1;
            }
        }

    }
    printf("%i\n",count);
}
