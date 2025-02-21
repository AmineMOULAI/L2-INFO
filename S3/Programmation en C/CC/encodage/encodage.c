#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 64

void read(const char* filename)
{
    FILE* f = fopen(filename, "rb");

    if (f != NULL)
    {
        char msg[BLOCK_SIZE];
        size_t bytes_lus;

        while ((bytes_lus = (msg, 64 * sizeof(char), 1, f)) > 0)
        {
            for (int i = 0; i < bytes_lus; i++)
            {
                printf("%c", msg[i]);
            }
                                                                                                                                                               
        }
        fclose(f);
    }
    
    
}

void analyizeF(const char* t[64], int frequence[256])
{
   for (int i = 0; i < 64; i++)
        frequence[(unsigned char)t[i]]++;
}

void analyizeText(const char* filename, int fq[256])
{
    FILE* f = fopen(filename, "rb");

    if (f != NULL)
    {
        char msg[65];
        while (fread(msg, 64 * sizeof(char), 1, f) == 1)
        {
            analyizeF(msg, fq);
            printf("%s ", msg);                                                                                                                                                   
        }
        fclose(f);
    }
}

void findKey(const char*)
{

}

int main()
{

    read("exemple.bin");

    return 0;
}