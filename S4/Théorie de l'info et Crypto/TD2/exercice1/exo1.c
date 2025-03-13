#include <stdio.h>
#include <string.h>
#include "exo1.h"

void print(const char* text, int n)
{
    for (int i = 0; i < n; i++)
        printf("%2c ", text[i]);
    printf("\n");
}

void numerize(const char* text, int n, int alphabet[26])
{
    for (int i = 0; i < n; i++)
        printf("%2d ", alphabet[text[i] - 'a']);
    printf("\n");
}

void shift_cipher(const char* text, int n, int key, char* encrypted_text)
{
    for (int i = 0; i < n; i++)
    {
        encrypted_text[i] = ((text[i] - 'a' + key) % 26) + 'a'; 
        printf("%2c ", encrypted_text[i]);
    }
    printf("\n");   
}

void substitution_cipher(const char* text, int n, int* alphabet, char* encrypted_text)
{
    for (int i = 0; i < n; i++)
    {
        int digit = alphabet[text[i] - 'a'];
        if (digit == 7)
            encrypted_text[i] = 'a';
        else if(digit == 25)
            encrypted_text[i] = 'i';
        else
            encrypted_text[i] = ((text[i] - 'a' + 1) % 26) + 'a';
    }
}

void vigenere_cipher(const char* text, int n, int* keyVeg, int nKeyVeg, char* encrypted_text)
{
    int i = 0;
    while (i < n)
    {
        for (int j = i; j < i + nKeyVeg; j++)
        {
            encrypted_text[j] = ((text[j] - 'a' + keyVeg[j % nKeyVeg]) % 26) + 'a';
        }
        i += nKeyVeg;
    }
    
}

int main()
{
    const char* text = "deschercheurstentent";
    int alphabet[26];
    char encrypted_text[256];

    for (int i = 0; i < 26; i++)
        alphabet[i] = i;

    /*for (int i = 0; i < 26; i++)
        printf("%d ", alphabet[i]);
    printf("\n");
    */
    print(text, strlen(text));
    numerize(text, strlen(text), alphabet);

    int key = 7;
    shift_cipher(text, strlen(text), key, encrypted_text);
    numerize(encrypted_text, strlen(encrypted_text), alphabet);
    printf("\n");

    printf("--------------------+Substitution cipher+------------------\n");
    substitution_cipher(text, strlen(text), alphabet, encrypted_text);
    numerize(encrypted_text, strlen(encrypted_text), alphabet);
    print(encrypted_text, strlen(encrypted_text));
    printf("\n");
    printf("--------------------+Vigenere cipher+------------------\n");
    const char* keyV = "ct";
    int key_numrized[2] = {alphabet[keyV[0] - 'a'], alphabet[keyV[1] - 'a']};

    vigenere_cipher(text, strlen(text), key_numrized, 2, encrypted_text);
    print(encrypted_text, strlen(encrypted_text));

    return 0;
}