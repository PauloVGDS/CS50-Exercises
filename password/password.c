// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library


#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Coloque uma senha: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol!\n");
    }
}

// isdigit , islower, isupper, ispunct

bool valid(string password)
{
    int num = 0, lower = 0, upper = 0, punct = 0;
    int len = strlen(password);
    for (int cont = 0; cont < len; cont++)
    {
        if (isdigit(password[cont]))
        {
            num += 1;
        }
        else if (islower(password[cont]))
        {
            lower += 1;
        }
        else if (isupper(password[cont]))
        {
            upper += 1;
        }
        else
        {
            punct += 1;
        }
    }
    if (num > 0 && lower > 0 && upper > 0 && punct > 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}
