#ifndef EXO1
#define EXO1

void numerize(const char* text, int n, int alphabet[26]);
void shift_cipher(const char* text, int n, int key, char* encrypted_text);
void substitution_cipher(const char* text, int n, int* alphabet, char* encrypted_text);
void vigenere_cipher(const char* text, int n, int* keyVeg, int nKeyVeg, char* encrypted_text);

#endif // 
