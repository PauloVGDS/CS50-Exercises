#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_sentences(string text);
int count_words(string text);

int main(void)
{
    string text = get_string("Text: ");

    int sentences = count_sentences(text);
    int letters = count_letters(text);
    int words = count_words(text);
    float L = ((float) letters/(float) words)*100;
    float S = ((float) sentences/(float) words)*100;
    float index = ((0.0588 * L) - (0.296 * S) - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 10)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n",round(index));
    }


}

int count_letters(string text)
{
    int letters = 0;
    for (int c = 0, len = strlen(text); c < len; c++)
    {
        if isalpha(text[c])
        {
            letters += 1;
        }
    }
    return letters;
}




int count_sentences(string text)
{
    int sentences = 0;
    for (int c = 0, len = strlen(text); c < len; c++)
    {
        if ((text[c] == '.' && text[c-1] != '.') || text[c] == '?' ||  text[c] == '!')
        {
            sentences += 1;
        }
    }
    return sentences;
}

int count_words(string text)
{
    int words = 1;
    for (int c = 0, len = strlen(text); c < len; c++)
    {
        if (isspace(text[c]) != 0)
        {
            words += 1;
        }
    }
    return words;
}