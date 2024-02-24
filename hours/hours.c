#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Números de Semenas fazendo CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Semana %i HW Horas: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Coloque T para o total de horas, A média de horas por semana: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f horas\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    float tot = 0;
    for (int c = 0; c < weeks; c++)
    {
        tot += hours[c];
    }

    if (output == 'T')
    {
        return tot;
    }

    if (output == 'A')
    {
        return tot/weeks;
    }
    return 0;
}