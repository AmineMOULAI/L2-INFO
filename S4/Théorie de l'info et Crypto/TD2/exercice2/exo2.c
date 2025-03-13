#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "exo2.h"

#define M 26

void print(const char* text, int n)
{
    for (int i = 0; i < n; i++)
        printf("%2c ", text[i]);
    printf("\n");
}

void affine_cipher(const char* text, int n, int* key, char* encrypted_text)
{
    for (int i = 0; i < n; i++)
        encrypted_text[i] = ((((text[i] - 'a') * key[0]) + key[1]) % M) + 'a';
}

int normalisation(int a)
{
    return (a + M*M) % M;
}

int reverse(int a)
{
    for (int i = 1; i < M; i++)
    {
        if ((a * i) % M == 1)
            return i;
    }
    return -1;
    
    
}
void affine_decipher(const char* encrypted_text, int n, int* key, char* text)
{
    int r = reverse(key[0]);
    for (int i = 0; i < n; i++)
    {
        int tmp = (r * ((encrypted_text[i] - 'a') - key[1]));
        tmp = normalisation(tmp);
        text[i] = (tmp % M) + 'a';
    }
}

int* frequency_analysis(const char* text, int n)
{
    int* frequency = (int*)malloc(26 * sizeof(int));

    for (int i = 0; i < n; i++)
        frequency[text[i] - 'a']++;
    
    return frequency;
    
}

void display_frequency(int* frequency)
{
    for (int i = 0; i < 26; i++)
        printf("%2c ", 'a' + i);
    printf("\n");
    for (int i = 0; i < 26; i++)
        printf("%2d ", frequency[i]);
    printf("\n");
}

/*int main()
{
    const char* text = "chiffrementaffine";
    char encrypted_text[50];

    print(text, strlen(text));

    int key[2] = {5, 8};
    printf("--------------------+Affine cipher+------------------\n");
    affine_cipher(text, strlen(text), key, encrypted_text);
    print(encrypted_text, strlen(encrypted_text));
    printf("\n");

    const char* ciphertext = "dcamojcibwvhs";
    char deciphertext[50];

    
    printf("--------------------+Affine decipher+------------------\n");
    int key1[2] = {3, 2};
    print(ciphertext, strlen(ciphertext));
    affine_decipher(ciphertext, strlen(ciphertext), key1, deciphertext);
    print(deciphertext, strlen(deciphertext));
    printf("\n");
    printf("--------------------+Frequency analysis+------------------\n");
    const char* ciphertext1 = "ntjmpumgxpqtstgqpgtxpnchumtputgfsftgthnngxnchumwxootrtumhpyctgktjqtjchfooxujqhgztumxpotjxotfoqtohrxumhzutwftgtopfmntjmpuatmfmshodpfrxpjjtqtghbxuj";
    frequency_analysis(ciphertext1, strlen(ciphertext1));
    
    return 0;
}*/