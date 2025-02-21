#include <stdio.h>

void
print(int tab[9][9])
{
  int i, j;
  for(i = 0; i < 9; i++) {
    for(j = 0; j < 9; j++) {
      printf("%d ", tab[i][j]);
      if(j == 2 || j == 5)
	printf("| ");
    }
    printf("\n");
    if(i == 2 || i == 5) {
      for(j = 0; j < 9; j++)
	printf("--");
      printf("----\n");
    }
  }
}

int
verifie_ligne(int tab[9][9], int l)
{
  int ok = 1, i = 1, j, nb_i;
  while(i <= 9 && ok == 1) {
    j = 0;
    nb_i = 0;
    while(j < 9)
      if(tab[l][j++] == i) nb_i ++;
    if(nb_i > 1)
      ok = 0;
    i++;
  }
  return ok;    
}

int
verifie_colonne(int tab[9][9], int c)
{
  int ok = 1, i = 1, j, nb_i;
  while(i <= 9 && ok == 1) {
    j = 0;
    nb_i = 0;
    while(j < 9)
      if(tab[j++][c] == i) nb_i ++;
    if(nb_i > 1)
      ok = 0;
    i++;
  }
  return ok;    
}

int
verifie_bloc(int tab[9][9], int l, int c)
{
  int ok = 1, i = 1, j, nb_i, x, y;
  while(i <= 9 && ok == 1) {
    j = 0;
    nb_i = 0;
    while(j < 9){
      x = 3 * c + j % 3;
      y = 3 * l + (j++) / 3;
      if(tab[y][x] == i) nb_i ++;
    }
    if(nb_i > 1)
      ok = 0;
    i++;
  }
  return ok;    
}

int
verifie_grille(int tab[9][9])
{
  int i, j, ok = 0;
  for(i = 0; i < 9; i++) {
    ok += verifie_ligne(tab, i);
    ok += verifie_colonne(tab, i);
    ok += verifie_bloc(tab, i / 3, i % 3);
  }
  return (ok == 27);
}

int
resolve_rec(int tab[9][9], int modifiable[9][9], int idx)
{
  // tab: grille a remplir
  // modifiable: indique si une position est modifiable, cad, 
  //             si elle appartient ou non a la grille initiale
  // idx: numero de la position a modifiee: 0 (0,0) ... 81= (9,9)
  int val = 0, ok = 0, ok_rec = 0; 
  if(idx < 81) {
    int x = idx / 9, y = idx % 9;
    if(modifiable[x][y] == 0)
      return resolve_rec(tab, modifiable, idx+1);
    else{
      // ...
      val = 1;
      do{
	tab[x][y] = val;
	ok = verifie_grille(tab);
	if(ok == 0)
	  val++;
	else{
	  ok_rec = resolve_rec(tab, modifiable, idx+1);
	  if(ok_rec == 0)
	    val++;
	}
      }while(val <= 9 && (ok == 0 || ok_rec == 0));
      if(val == 10){
	tab[x][y] = 0;
	return 0;
      }else
	return 1;
    }
  }
  return 1;
}

void
resolve(int tab[9][9])
{
  int i, j, tmp[9][9];
  for(i = 0; i < 9; i++)
    for(j = 0; j < 9; j++)
      tmp[i][j] = (tab[i][j] == 0);
  printf(" ... resolve grille= %d\n", resolve_rec(tab, tmp, 0));
}

int
main(void)
{
  int tab[9][9] = {{1,0,0,0,0,0,0,0,4},
		   {0,0,0,0,9,0,0,0,8},
		   {0,0,0,6,8,0,5,7,1},
		   {0,4,0,8,0,0,0,0,0},
		   {0,0,0,5,2,7,0,0,3},
		   {7,5,0,3,0,0,9,1,0},
		   {0,3,0,1,0,0,0,0,5},
		   {8,7,4,0,6,0,0,0,0},
		   {2,0,5,0,0,8,0,0,6}};
  
  print(tab);
  printf(" ... verifie grille= %d\n", verifie_grille(tab));
  resolve(tab);
  print(tab);
  return 0;
}
    
