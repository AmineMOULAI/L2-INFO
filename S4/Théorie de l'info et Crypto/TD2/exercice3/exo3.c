#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "exo2.h"
#include "exo3.h"

int char_in_str(char str[], int n, char c)
{
    for (int i = 0; i < n; i++)
    {
        if (str[i] == c) return 1;
    }
    return 0;
}

void substitution_decipher(char* ciphertext, char* deciphertext, int n)
{
    char correspondance[2][n];
    memset(correspondance, 0, sizeof(correspondance));

    for (int j = 0; j < n; j++)
    {
        if (!char_in_str(correspondance[0], n, deciphertext[j]))
        {
            correspondance[0][j] = deciphertext[j];
            correspondance[1][j] = ciphertext[j];
        }
    }

    for (int j = 0; j < n; j++)
    {
        if (correspondance[0][j] != '\0') {
            printf("%c ", correspondance[0][j]);   
        }
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        if (correspondance[1][i] != '\0') {
                printf("%c ", correspondance[1][i]);
            }
    }
    printf("\n");
    
}

void vignere(char* ciphertext, char* deciphertext, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", abs(ciphertext[i] - deciphertext[i]));
    printf("\n");
}


int main()
{
    char ciphertext[] = "cetinsecteconstitueuneespeceendemiquecestadire";
    char decipher_text[] = "tywremhlkyfxemwrkohdeyhbgyfnvhgndctdvwhbky";
    //int* f = frequency_analysis(decipher_text, strlen(decipher_text));
    //display_frequency(f);
    //substitution_decipher(ciphertext, decipher_text, strlen(ciphertext));
    vignere(ciphertext, decipher_text, strlen(ciphertext));
    return 0;
}