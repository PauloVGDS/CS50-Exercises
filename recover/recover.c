#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        printf("Usage: ./recover <image_name>\n");
        return 1;
    }

    FILE *arquivo = fopen(argv[1],"r");
    uint8_t buffer[512];
    FILE *img = NULL;
    int read_count = -1;
    char *nome_arquivo = malloc(8 * sizeof(char));
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }


    while (fread(buffer, 512, 1, arquivo))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0))
        {
            if (read_count >= 0)
            {
                fclose(img);
            }
            read_count++;
            sprintf(nome_arquivo, "%03i.jpg",read_count);
            img = fopen(nome_arquivo,"w");
        }
        if (read_count >= 0)
        {
            fwrite(buffer, 512, 1, img);
        }
    }
    free(nome_arquivo);
    fclose(arquivo);
    return 0;
}


