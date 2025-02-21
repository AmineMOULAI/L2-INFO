#include <stdio.h>
#include <string.h>

void numerize(const char* text, int n, int alphabet[26])
{
    for (int i = 0; i < n; i++)
        printf("%2c ", text[i]);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%2d ", alphabet[text[i] - 'a']);
}
void shift_cipher(const char* text, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", (text[i] + key) % 26);
    }
    
}
int main()
{
    const char* text = "deschercheurstentent";
    int alphabet[26];

    for (int i = 0; i < 26; i++)
        alphabet[i] = i;

    /*for (int i = 0; i < 26; i++)
        printf("%d ", alphabet[i]);
    printf("\n");
    */
    numerize(text, strlen(text), alphabet);
    printf("\n");
    
    return 0;
}