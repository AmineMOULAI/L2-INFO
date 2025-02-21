#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 256
#define N 10
#define TOTAL_MINES 5

//structures 
typedef enum
{
    NDNM,
    NDMD,
    D

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
    grid g;
    g.width = width;
    g.height = height;
    g.totalMines = total_mines;
    g.minesDiscoverd = 0;

    for (int i = 0; i < g.height; i++)
    {
        for (int j = 0; j < g.width; j++)
        {
            g.grid[i][j].stat = NDNM;
            g.grid[i][j].mine = 0;
            g.grid[i][j].nb_adj_mines = 0;
        }
    }

    int minesPlaced = 0;

    while (minesPlaced < g.totalMines)
    {
        int x = rand() % g.height;
        int y = rand() % g.width;

        if (g.grid[x][y].mine != 1)
        {  
            g.grid[x][y].mine = 1;
            minesPlaced++;
        

            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    if (x + i >= 0 && x + i < g.height && y + j >= 0 && y + j < g.width)
                    {
                        if (i != 0 || j != 0)
                        {
                            if (g.grid[x + i][y + j].mine != 1)
                                g.grid[x + i][y + j].nb_adj_mines++;
                        }
                    }   
                }  
            }
        } 
        for (int i = 0; i < g.height; i++)
        {
            for (int j = 0; j < g.width; j++)
            {
                if (g.grid[i][j].mine != 1 && g.grid[i][j].nb_adj_mines != 0)
                    g.grid[i][j].stat = g.grid[i][j].nb_adj_mines;
                
            }
            
        }
        
    }

    return g;
}

void afficher(grid g)
{
    for (int i = 0; i < g.height; i++)
    {
        for (int j = 0; j < g.width; j++)
        {
            switch (g.grid[i][j].stat)
            {
            case NDNM:
                printf("X");
                break;
            case NDMD:
                printf("F");
                break;
            case D:
                printf(" ");
                break;
            
            default:
                printf("%d", g.grid[i][j].stat);
            }
        }
        printf("\n");
        
    }
    
}

void tester_grille(grid g) {
    int mine_count = 0;
    bool dimensions_ok = (g.width > 0 && g.width <= MAX_SIZE) && (g.height > 0 && g.height <= MAX_SIZE);

    // Vérifier les dimensions
    if (dimensions_ok) {
        printf("Dimensions de la grille : OK\n");
    } else {
        printf("Dimensions de la grille : ERREUR\n");
    }

    // Vérifier le nombre de mines
    for (int i = 0; i < g.height; i++) {
        for (int j = 0; j < g.width; j++) {
            if (g.grid[i][j].mine == 1) {
                mine_count++;
            }
        }
    }
    
    if (mine_count == g.totalMines) {
        printf("Nombre de mines : OK\n");
    } else {
        printf("Nombre de mines : ERREUR\n");
    }

    // Vérifier la cohérence des valeurs de nb_adj_mines
    bool adj_mines_ok = true;
    for (int x = 0; x < g.height; x++) {
        for (int y = 0; y < g.width; y++) {
            if (g.grid[x][y].mine == 0) {
                int adjacent_mines = 0;
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        int nx = x + i;
                        int ny = y + j;
                        if ((i != 0 || j != 0) && nx >= 0 && nx < g.height && ny >= 0 && ny < g.width) {
                            if (g.grid[nx][ny].mine == 1) {
                                adjacent_mines++;
                            }
                        }
                    }
                }
                if (g.grid[x][y].nb_adj_mines != adjacent_mines) {
                    adj_mines_ok = false;
                    printf("Erreur au niveau de la case (%d, %d): attendu %d, trouvé %d\n", x, y, adjacent_mines, g.grid[x][y].nb_adj_mines);
                }
            }
        }
    }
    if (adj_mines_ok) {
        printf("Valeurs de nb_adj_mines : OK\n");
    } else {
        printf("Valeurs de nb_adj_mines : ERREUR\n");
    }
}


int main()
{
    srand(time(NULL));

    //int t[N] = {1, 3, 0, 2, 5, 7, 8, -1, -1, -1};
    //int p;

    /*for (int i = 0; i < N; i++)
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
    }*/
    
    printf("Création de la grille...\n");
    grid c = creer(N, N, TOTAL_MINES);

    printf("Affichage de la grille :\n");
    afficher(c);

    printf("\n");
    for (int i = 0; i < c.height; i++)
    {
        for (int j = 0; j < c.width; j++)
        {
            printf("%d ", c.grid[i][j].mine);
        }
        printf("\n");
        
    }
    
    printf("Création de la grille...\n");
    grid g = creer(N, N, TOTAL_MINES);

    printf("Affichage de la grille :\n");
    afficher(g);


    return 0;
}