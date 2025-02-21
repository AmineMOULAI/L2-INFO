#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 4



// struct

typedef struct 
{
    int grid[DIM][DIM];
    int score;
}grid;

typedef enum
{
    U = 8,
    D = 2,
    L = 4,
    R = 6
}dir;



// functions 
void merge_left(int t[])
{
   int i, j = 0;

    // Shift to the left
   for (i = 0; i < DIM; i++)
   {
        if (t[i]!= 0)
            t[j++] = t[i];
   }

    // add zeros
   while (j < DIM)
        t[j++] = 0;

   // merge
   for (i = 0; i < DIM - 1; i++)
   {
        if (t[i] == t[i + 1] && t[i] != 0)
        {
            t[i] *= 2;
            t[i + 1] = 0;
        }
   }

    // shift again to the left
   j = 0;
   for (i = 0; i < DIM; i++)
   {
        if (t[i] != 0)
            t[j++] = t[i];
   }

    // add zeros
   while (j < DIM)
        t[j++]= 0;
    
}

void merge_right(int t[])
{
   int i, j = DIM - 1;

    // Shift to the right
   for (i = DIM - 1; i >= 0; i--)
   {
        if (t[i]!= 0)
            t[j--] = t[i];
   }

    // add zeros
   while (j >= 0)
        t[j--] = 0;

   // merge
   for (i = DIM - 1; i > 0; i--)
   {
        if (t[i - 1] == t[i] && t[i] != 0)
        {
            t[i] *= 2;
            t[i - 1] = 0;
        }
   }

    // shift again to the right
   j = DIM - 1;
   for (i = DIM - 1; i > 0; i--)
   {
        if (t[i] != 0)
            t[j--] = t[i];
   }

    // add zeros
   while (j >= 0)
        t[j--]= 0; 
}

void merge_up(int g[DIM][DIM], int c, int col[DIM])
{
    for (int i = 0; i < DIM; i++)
        col[i] = g[i][c];
    
    merge_left(col);

    for (int i = 0; i < DIM; i++)
    {
        g[i][c] = col[i];
    }
}

void merge_down(int g[DIM][DIM], int c, int col[DIM])
{
    for (int i = 0; i < DIM; i++)
        col[i] = g[i][c];
    
    merge_right(col);

    for (int i = 0; i < DIM; i++)
    {
        g[i][c] = col[i];
    }
}

void new_case(grid* g)
{
    int c;
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            /* code */
        }
        
    }
    

}


void add_number(int t[])
{
    int caseNull[DIM];
    int indx = 0;

    // find the zeros
    for (int i = 0; i < DIM; i++)
    {
        if (t[i] == 0)
            caseNull[indx++] = i;
    }

    // insert 2 || 4
    if (indx > 0)
    {
        int p = caseNull[rand() % indx];
        int c = rand() % 2;
        if (c == 0)
            t[p] = 2;
        else
            t[p] = 4;    
    }
}

void initialize(grid* g)
{
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
            g->grid[i][j] = 0;
    }

    for (int i = 0; i < 2; i++)
    {
        int c = rand() % 4;
        add_number(g->grid[c]);
    }
    
}

void print_row()
{
    printf("+");
    for (int i = 1; i < DIM * DIM - 3; i++)
    {
        printf("-");
        if (i % 3 == 0)
        printf("+");
        }
        printf("\n");
    }
void display(grid g)
{
    
    print_row();
   for (int i = 0; i < DIM; i++)
    {
        printf("|");
        for (int j = 0; j < DIM; j++)
        {
            if (g.grid[i][j] != 0)
                printf(" %d |", g.grid[i][j]);
            else
                printf("   |");
            
            
            
        }
        printf("\n");
        print_row();
    }
}

int main()
{
    srand(time(NULL));

    int row[4] = {2, 2, 4, 4};
    int grille[DIM][DIM] = {
        {2, 2, 2, 4},
        {2, 0, 0, 0},
        {0, 2, 0, 4},
        {4, 0, 2, 0}
    };

    grid g;

    for (int i = 0; i < DIM; i++)
        printf("%d ", row[i]);
    printf("\n");

    merge_left(row);
    add_number(row);

    for (int i = 0; i < DIM; i++)
        printf("%d ", row[i]);
    printf("\n");
    printf("\n");

    initialize(&g);

    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
            printf("%d ", g.grid[i][j]);
        printf("\n");   
    }
    printf("\n");

    display(g);

    printf("\n");
    printf("\n");
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
            printf("%d ", grille[i][j]);
        printf("\n");
        
    }

    printf("\n");
    printf("\n");

    int col[DIM];

    merge_up(grille, 0, col);
    merge_down(grille, 3, col);

    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
            printf("%d ", grille[i][j]);
        printf("\n");
        
    }
    
    
    return 0;
}