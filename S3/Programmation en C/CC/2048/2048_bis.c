#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define N 4


typedef enum
{
    U = 8,
    D = 2,
    L = 4,
    R = 6

}dir;

typedef struct 
{
    int** g;
    int score;
}game;

game* create_grid(int n)
{
    //alocate game
    game* grid = (game*)malloc(sizeof(game));

    grid->g = (int**)malloc(n * sizeof(int*));
    if (grid->g == NULL)
    {
        printf("Allocation field !");
        return NULL;
    }

    // allocate grid
    int i = 0;
    do
    {
        grid->g[i] = (int*)malloc(n * sizeof(int));
        i++;
    } while (i < n && grid->g[i - 1] != NULL);

    // initialize grid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            grid->g[i][j] = 0;
    }
    int min = 2, max = 6;

    int t = min + rand() % (max - min + 1);

    for (int i = 0; i < t; i++)
    {   
        int x = rand() % 4;
        int y = rand() % 4;
        int c = rand() % 2; 
        grid->g[x][y] = (c == 0) ? 2 : 4;
    }
    

    grid->score = 0;

    return grid;
}

void destroy_game(game* grid, int n)
{
    for (int i = 0; i < n; i++)
        free(grid->g[i]);
    free(grid->g);

    free(grid);
    
}

void print_grid(game* grid, int n)
{

    printf("+--------- score = %d ----------+\n\n", grid->score);

    for (int i = 0; i < n; i++)
        printf("+-----");   
    printf("+\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid->g[i][j] != 0) printf("|%4d ", grid->g[i][j]);
            else printf("|     ");
        }
        printf("|\n");

        for (int i = 0; i < n; i++)
            printf("+-----");   
        printf("+\n");
        
    }
}

void move_left(int* row, int n, int* score)
{
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (row[i] != 0)
            row[j++] = row[i];
    }

    while (j < n)
        row[j++] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (row[i] == row[i + 1] && row[i] != 0)
        {
            row[i] *= 2;
            *score += row[i];
            row[i + 1] = 0;
        } 
    }

    j = 0;

    for (int i = 0; i < n; i++)
    {
        if (row[i] != 0)
            row[j++] = row[i];
    }

    while (j < n)
        row[j++] = 0;
}

void move_right(int* row, int n, int* score)
{
    int j = n - 1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (row[i] != 0)
            row[j--] = row[i];
    }

    while (j >= 0)
        row[j--] = 0;

    for (int i = n - 1; i > 0; i--)
    {
        if (row[i] == row[i - 1] && row[i] != 0)
        {
            row[i] *= 2;
            *score += row[i];
            row[i - 1] = 0;
        } 
    }

    j = n - 1;

    for (int i = n - 1; i > 0 ; i--)
    {
        if (row[i] != 0)
            row[j--] = row[i];
    }

    while (j >= 0)
        row[j--] = 0;
}

void move_up(game* t, int col, int n)
{
    int* c = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        c[i] = t->g[i][col];

    move_left(c, n, &t->score);

    for (int i = 0; i < n; i++)
        t->g[i][col] = c[i];
    
    free(c);
}

void move_down(game* t, int col, int n)
{
    int* c = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        c[i] = t->g[i][col];

    move_right(c, n, &t->score);

    for (int i = 0; i < n; i++)
        t->g[i][col] = c[i];

    free(c);
}

void move_grid(game* t, int n, dir d)
{
    if (d == U)
    {
        for (int j = 0; j < n; j++)
            move_up(t, j, n);
        
    }else if (d == D)
    {
        for (int j = 0; j < n; j++)
            move_down(t, j, n);
    }else if (d == L)
    {
        for (int i = 0; i < n; i++)
            move_left(t->g[i], n, &t->score);
    }else if (d == R)
    {
        for (int i = 0; i < n; i++)
            move_right(t->g[i], n, &t->score);
    }else
    {
        printf("Erreur !");
    }  
}

void new_case(int** g, int n)
{
    int cn_i[n * n];
    int cn_j[n * n];
    int cn = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == 0)
            {
                cn_i[cn] = i;
                cn_j[cn] = j;
                cn++;
            }
        }
    }

    // calculate %
    if (cn > 0)
    {
        int valide = 0;
        while (!valide)
        {
            float p = (cn * 100) / (n * n);

            // insert number 
            int x = cn_i[rand() % cn];
            int y = cn_j[rand() % cn];
            if (g[x][y] == 0)
            {
                g[x][y] = (p < 40) ? 4 : 2;
                valide = 1;  
            }
            
        }
    }
    
    
    
}

int is_game_over(int** g, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == 0)
                return 0;

            if (i + 1 < n && g[i][j] == g[i + 1][j])
                return 0; 

            if (j + 1 < n && g[i][j] == g[i][j + 1])
                return 0;  
        }
    }
    return 1;  
}

int check_vectory(int** g, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == 2048)
                return 1;
        }
        
    }
    return 0;
    
}

void play_turn(game* t, int n)
{
    int d;

    scanf("%d", &d);

    
    if (d == U) move_grid(t, n, U);
    else if (d == D) move_grid(t, n, D);
    else if (d == L) move_grid(t, n, L);
    else if(d == R) move_grid(t, n, R);
    
    new_case(t->g, n);   
}
    


void run_game(game* t, int n)
{
    do
    {
        system("cls");
        print_grid(t, n);
        play_turn(t, n);
        if (check_vectory(t->g, n))
        {
            printf("WON !");
            break;
        }
        Sleep(150);
        
    } while (!is_game_over(t->g, n));
    
    printf("Game Over !");
    
}

int main()
{
    srand(time(NULL));

    game* t = NULL;

    t = create_grid(N);
    run_game(t, N);
    destroy_game(t, N);

    return 0;
}