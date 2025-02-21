#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_SIZE 256
#define N 30
#define C 10

void clear_screen() {
    printf("\033[H\033[J"); // Séquence ANSI pour effacer l'écran
}

//structures

typedef struct 
{
    int alive;
}cell;

typedef struct 
{
    int height, width;
    cell grid[MAX_SIZE][MAX_SIZE];
    int cellsAlive;
    
}grid;



// Fonctions

void initialize(int t[])
{
    for (int i = 0; i < N; i++)
        t[i] = -1;
}

void add(int* t[], int k)
{
    int i = 0;
    while (i < N && t[i] != -1)
        i++;
    
    if (i < N)
        t[i] = k;
}

int delete(int* t[])
{
    int p = t[0];
    for (int i = 0; i < N - 1; i++)
        t[i] = t[i + 1];
    
    t[N - 1] = -1;
    
    return p;
}

void first_config(int config[])
{

    printf("Entrer your config :\n");
    for (int i = 0; i < C; i++)
    {
        printf("Enter cell %d : ", i);
        scanf("%d", &config[i]);
    }
        
}
    
grid create_grid(int height, int width)
{
    grid g;
    g.height = height;
    g.width = width;
    g.cellsAlive = 0;


    for (int i = 0; i < g.height / 2; i++)
    {
        for (int j = 0; j < g.width; j++)
            g.grid[i][j].alive = 0;        
    }
    int c[20];
    first_config(c);
    //Place cells 
    
    for (int i = 0; i < C; i++)
    {
        int cell = c[i];
        int x = cell / N;
        int y = cell % N;

        if (x < g.height && y < g.width)
        {
            g.grid[x][y].alive = 1;
        }
        

    }
   
    return g;    
}

void display(grid* g)
{
    for (int i = 0; i < g->height + 2; i++)
        printf("#");
    printf("\n");
    for (int i = 0; i < g->height / 2; i++)
    {
        printf("#");
        for (int j = 0; j < g->width; j++)
        {
            if (g->grid[i][j].alive == 0) printf(" ");
            else printf("X");
        }
        printf("#");
        printf("\n");
    }
    for (int i = 0; i < g->height + 2; i++)
        printf("#");
}

int cellsAlive(grid* g, int x, int y)
{
    int alive = 0;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int nx = x + i;
            int ny = y + j;

            if (nx >= 0 && nx < g->height && ny >= 0 && ny < g->width && !(i == 0 && j == 0))
                if (g->grid[nx][ny].alive == 1)
                    alive++;   
        }   
    }

    return alive;
    
}

void evolution(grid* g)
{
    grid cg;

   for (int i = 0; i < g->height; i++)
   {
        for (int j = 0; j < g->width; j++)
        {
            if (g->grid[i][j].alive == 1)
            {
                if (cellsAlive(g, i, j) < 2 || cellsAlive(g, i, j) > 3)
                {
                    cg.grid[i][j].alive = 0;
                }else cg.grid[i][j].alive = g->grid[i][j].alive;
                
            }else
            {
                if (cellsAlive(g, i, j) == 3)
                {
                    cg.grid[i][j].alive = 1;
                }else cg.grid[i][j].alive = g->grid[i][j].alive;
                
            }  
        } 
   }
   for (int i = 0; i < g->height; i++)
   {
        for (int j = 0; j < g->width; j++)
        {
            g->grid[i][j] = cg.grid[i][j];
        }
        
   }
    
}

int end(grid* g)
{
    int end = 1;
    for (int i = 0; i < g->height; i++)
    {
        for (int j = 0; j < g->width; j++)
        {
            if (g->grid[i][j].alive == 1)
                end = 0;   
        }
    }

    return end;
    
}


int main()
{
    srand(time(NULL));

    grid g;

    g = create_grid(N, N);
    while (1)
    {
        clear_screen();
        display(&g);
        evolution(&g);
        printf("\n");
        usleep(150000);
               
    }
    
    

    return 0;
}