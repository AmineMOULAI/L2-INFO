#include <stdio.h>
#include <stdlib.h>


typedef enum
{
    pos,
    neg
}signe;

typedef struct 
{
    signe s;
    unsigned int k;
    short* n;
}nombre;

short min(a, b)
{
    if (a < b) return a;
    else return b;
}

nombre creer_nombre(unsigned int p)
{
    nombre nb;
    int nb_block = p / 16;
    nb.s = pos;
    nb.k = nb_block;
    nb.n = (short*)malloc(nb_block * sizeof(short));
    
    for(int i = 0; i < nb.k; i++)
      nb.n[i] = 0;
    
    return nb;
}

nombre addition(nombre a, nombre b, nombre res)
{
    short r = 0;
    if (a.s == b.s)
    {
        for (int i = 0; i < min(a.k, b.k); i++)
        {
            /* code */
        }
        
    }
    

}


int main()
{
    int p = 32;
    nombre nb;

    nb = creer_nombre(p);

    return 0;
}