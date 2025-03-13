#ifndef EXO2
#define EXO2

void print(const char* text, int n);
void affine_cipher(const char* text, int n, int* key, char* encrypted_text);
void affine_decipher(const char* encrypted_text, int n, int* key, char* text);
int normalisation(int a);
int reverse(int a);
int* frequency_analysis(const char* text, int n);
void display_frequency(int* frequency);

#endif