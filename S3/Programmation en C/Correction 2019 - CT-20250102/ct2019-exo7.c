#include <stdio.h>
#include <math.h>

int
distance(float xA, float yA, float xB, float yB)
{
  float d = sqrtf((xB - xA)*(xB - xA) + (yB - yA)*(yB - yA));
  return d;
}

typedef struct point
{
  float x, y;
} point_t;

void
points_les_plus_proches(point_t *nuage, int n, int *pt1, int *pt2)
{
  flaot d, dmin;
  int i, j;
  
  if(n < 0) {
    *pt1 = -1;
    *pt2 = -1;
  }else{
    dmin = 0;
    *pt1 = 0;
    *pt2 = 0;
    for(i = 0; i <= n-2; i++) {
      for(j = i+1; j <= n-1; j++) {
	d = distance(nuage[i].x, nuage[i].y, nuage[j].x, nuage[j].y);
	if(d < dmin) {
	  dmin = d;
	  *pt1 = i;
	  *pt2 = j;
	}
      }
    }
  }
}
