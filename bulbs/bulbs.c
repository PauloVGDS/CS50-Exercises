#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    const int BITS = 7;
    string lista[3];
    string word = get_string("Message: ");
    for (int c = 0, len = strlen(word); c < len; c++)
    {
        int bit = word[c];
        for (int i = BITS; i >= 0; i--)
        {
            if (bit >= pow(2,i))
            {

                bit -= pow(2,i);
                print_bulb(1);
            }
            else
            {
                print_bulb(0);
            }
        }
        bit = 0;
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
