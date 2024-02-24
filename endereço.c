#include <stdio.h>

int main(void)
{
    char *s = "OI!";
    printf("%c\n",*s);
    printf("%c\n",*(s+1));
    printf("%c\n",*(s+2));
    // Valores elevados podem levar a 'Segmentation fault'
    printf("%c\n",*(s+10000));
}