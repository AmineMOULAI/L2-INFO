#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 256
#define N 42
#define TOTAL_MINES 15

//structures 
typedef enum
{
    NDNM = 4,
    NDMD = 5,
    D = 6,
    M = 7

}box_stat;

typedef struct 
{
    box_stat stat;
    int nb_adj_mines;
    int mine;
} box;

typedef struct 
{
    int width;
    int height;
    box grid[MAX_SIZE][MAX_SIZE];
    int totalMines;
    int minesDiscoverd;
}grid;





// Fonctions
void initialiser(int t[])
{
    for (int i = 0; i < N * N; i++)
        t[i] = -1;
}

void ajouter(int t[], int k)
{
    int i = 0;
    while ((i < N) && (t[i] != -1))
        i++;
    
    if (i < N)
    {
        t[i] = k;
    }
}

int retirer(int t[])
{
    int p = t[0];

    for (int i = 0; i < N - 1; i++)
    {
        t[i] = t[i + 1];
    }
    t[N - 1] = -1;

    return p; 
}

grid creer(int width, int height, int total_mines)
{
    grid g; // On crée la grille directement sans pointeur
    g.width = width;
    g.height = height;
    g.totalMines = total_mines;
    g.minesDiscoverd = 0;

    // Initialisation de la grille
    for (int i = 0; i < g.height; i++)
    {
        for (int j = 0; j < g.width; j++)
        {
            g.grid[i][j].stat = 6;
            g.grid[i][j].nb_adj_mines = 0;
            g.grid[i][j].mine = 0;
        }
    }  

    int minesPlaced = 0;
    // Placement des mines
    while (minesPlaced < g.totalMines)
    {
        int x = rand() % g.height;
        int y = rand() % g.width;

        if (g.grid[x][y].mine != 1)
        {
            g.grid[x][y].mine = 1;
            minesPlaced++;
            printf("Mine placée en (%d, %d)\n", x, y);  // Affichage de chaque placement de mine
        }
    }

    // Mise à jour des cases adjacentes
    for (int x = 0; x < g.height; x++)
    {
        for (int y = 0; y < g.width; y++)
        {
            if (g.grid[x][y].mine == 1)
            {
                for (int i = -1; i <= 1; i++)
                {
                    for (int j = -1; j <= 1; j++)
                    {
                        int nx = x + i;
                        int ny = y + j;
                        if (nx >= 0 && nx < g.height && ny >= 0 && ny < g.width && !(i == 0 && j == 0))
                        {
                            g.grid[nx][ny].nb_adj_mines++;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < g.height; i++)
    {
        for (int j = 0; j < g.width; j++)
        {
            if(g.grid[i][j].nb_adj_mines != 0)
                g.grid[i][j].stat = g.grid[i][j].nb_adj_mines;
            
            if (g.grid[i][j].mine == 1)
                g.grid[i][j].stat = M;
        }
        
    }

    // ajouter un drapeau 
    for (int i = 0; i < 2; i++)
    {
        int dx = rand() % g.height;
        int dy = rand() % g.width;

        if (g.grid[dx][dy].nb_adj_mines != 0)
            g.grid[dx][dy].stat = NDMD;
    }
    
    return g; // On retourne directement la grille
}


void afficher(grid* g)
{
    for (int i = 0; i < g->width + 2; i++)
        printf("#");
    printf("\n");

    for (int i = 0; i < g->height; i++)
    {
        printf("#");
        for (int j = 0; j < g->width; j++)
        {
            if (g->grid[i][j].stat == D)
            {
                printf(" ");
            }else if (g->grid[i][j].stat == NDNM || g->grid[i][j].stat == M)
            {
                printf("X");
            }else if (g->grid[i][j].stat == NDMD)
            {
                printf("F");
            }else
            {
                printf("%d", g->grid[i][j].stat);
            }
        }
        printf("#");
        printf("\n");
    }
    for (int i = 0; i < g->width + 2; i++)
        printf("#");
    printf("\n");
    
}

void devoiler_case_vide(grid g, int x, int y)
{
    int t[N*N];
    initialiser(t);

    if (g.grid[x][y].stat != D)
    {
        int p = x * g.width + y;
        ajouter(t, p);
        
        while (t[0] != -1)
        {
            p = retirer(t);
            x = p / g.width;
            y = p % g.width;
            if (g.grid[x][y].stat != D)
                g.grid[x][y].stat = D;
            
            if (g.grid[x][y].nb_adj_mines > 0) continue;
            
            for (int i = -1; i < 1; i++)
            {
                for (int j = -1; j < 1; i++)
                {
                    int nx = x + i;
                    int ny = y + j;
                    if (nx >= 0 && nx < g.height && ny >= 0 && ny < g.width && !(i == 0 && j == 0) && g.grid[nx][ny].mine != 1)
                        p = nx * g.width + ny;
                        ajouter(t, p);
                    
                }
                
            }
            

        }
        
    }
    
    

}


int main()
{
    srand(time(NULL));

    int t[N] = {1, 3, 0, 2, 5, 7, 8, -1, -1, -1};
    int p;

    for (int i = 0; i < N; i++)
    {
        printf("%d ", t[i]);
    }

    printf("\n");
    p = retirer(t);
    printf("p = %d retire !", p);

    printf("\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", t[i]);
    }
    printf("\n");
    
    printf("Création de la grille...\n");
    grid g = creer(N, N / 2, TOTAL_MINES);

    for (int i = 0; i < g.height; i++)
    {
        for (int j = 0; j < g.width; j++)
        {
            printf("%d ", g.grid[i][j].stat);
        }
        printf("\n");
    }
    printf("\n");
    afficher(&g);



    return 0;
}