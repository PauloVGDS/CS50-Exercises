#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    string n = get_string("Número: ");
    int tot = 0;
    int sum = 0;
    int len = strlen(n);
    if (len % 2 == 1)
    {
        for (int c = len-1; c >= 0; c--)
    {
        int digit = n[c] - '0';

        if (c % 2 == 1)
        {

            digit *= 2;
            printf("\033[1;31m %i ",digit);
            if (digit < 9)
            {
                tot += digit;
            }
            else
            {
                tot += digit-9;
            }

        }
        else
        {
            printf("\033[1;34m %i ",digit);
            sum += digit;
        }

    }
    printf("%i %i",tot,sum);
    }
    else
    {
        for (int c = 0; c < len; c++)
    {
        int digit = n[c] - '0';

        if (c % 2 == 0)
        {
            digit *= 2;
            if (digit < 9)
            {
                tot += digit;
            }
            else
            {
                tot += digit-9;
            }
        }
        else
        {
            sum += digit;
        }
    }
    }
    if ((sum+tot) % 10 == 0)
    {
        if (len == 15 && (n[0] == '3' && (n[1] == '4' || n[1] == '7')))
        {
            printf("AMEX\n");
        }
        else if (len == 16 && (n[0] == '5' && (n[1] == '1' || n[1] == '2' || n[1] == '3' || n[1] == '4' || n[1] == '5')))
        {
            printf("MASTERCARD\n");
        }
        else if ((len == 13 || len == 16) && n[0] == '4')
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
        {
            printf("INVALID\n");
        }

}
