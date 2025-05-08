from random import randint

'''
    * Tri par insertion
        * Principe : On place chaque élément du tableau à la bonne place parmi les autres éléments déjà triés 
        * Input : 
            - t : list[int] -> tableau à trier 
            - n : int -> la taille du tableau à trier
        * Output :
            - Le tableau 't' trié
    ** Notons que le traitement est effectué sur le même tableau sans créer une copie

'''

'''def tri_insertion(t : list[int], n : int) -> list[int]:

    for i in range(n):
        v = t[i]
        j = i
        while j > 0 and v < t[j - 1]:
            t[j] = t[j - 1]
            j -= 1
        t[j] = v
    return t

n = 10
t1 = [randint(0, 10) for i in range(n)]
print(t1)
t1.sort()

assert tri_insertion(t1, n) == t1
print(t1)
print(tri_insertion(t1, n))'''

'''n = 10
best = [i for i in range(n)]
worst = [i for i in reversed(range(n))]

def tri_insertion_analysis(t : list[int], n : int) -> list[int]:
    nb = 0
    for i in range(1, n):
        v = t[i]
        j = i
        nb += 1
        while j > 0 and v < t[j - 1]:
            t[j] = t[j - 1]
            j -= 1
            nb += 1
        t[j] = v
        if j == 0:
            nb -= 1
    return t, nb

print(f"Meilleur cas : {best} -> {tri_insertion_analysis(best, n)}")
print(f"Pire cas : {worst} -> {tri_insertion_analysis(worst, n)}")

'''
'''
def tri_insertion_rec(t : list[int], n : int) -> int:
    '''Version récursive'''
    if n < 2:
        return t
    else:
        tri_insertion_rec(t, n - 1)
        i = n - 1
        v = t[i]
        j = i
        while j > 0 and v < t[j - 1]:
            t[j] = t[j - 1 ]
            j -= 1
        t[j] = v

n = 10
t1 = [randint(0, 10) for i in range(n)]
print(t1)
t1.sort()

assert tri_insertion_rec(t1, n) == t1
'''

# Tri rapide (Quicksort)

'''
    * Tri rapide (Quicksort)
        * Principe : Placer l'élèment d'un tableau (pivot) à sa place définitive de telle sort que les elts du gauche < pivot et ceux du droite > pivot
        * Input : 
            - t : list[int] -> tableau à trier  
            - n : la taille du tableau 
            ** On a deux fonctions pour arriver à cette fonction 
                * tri_rapide0 : 
                    * Input :
                        - t : list[int] -> tableau à trier
                        - g : int -> L'indice de début 
                        - d : int -> L'indice de dernier

                ** Le traitement s'effectue directement sur le tableau concerné
                
                * partitiion :
                    * input :
                        - t : list[int] -> tableau à trier
                        - g : int -> L'indice de début 
                        - d : int -> L'indice de dernier 
                    * Output : 
                        - m : int -> la valeur qui partitionne le tableau en 2 parties (gauche inf / droite sup)          


def partition(t : list[int], g : int, d : int) -> int:

    assert g < d - 1

    pivot = t[d - 1]
    m = g

    for i in range(g, d - 1):
        if t[i] <= pivot:
            tmp = t[i]
            t[i] = t[m]
            t[m] = tmp
            m += 1
    t[d - 1] = t[m]
    t[m] = pivot

    return m

def tri_rapide0(t : list[int], g : int, d : int) -> None:

    if d - g > 1:
        m = partition(t, g, d)
        tri_rapide0(t, g, m - 1)
        tri_rapid0(t, m + 1, d)

def tri_rapide(t : list[int], n : int) -> None:
    tri_rapide0(t, 0, len(t))

'''

'''
    * Tri par Fusion (Merge sort)
        * Principe : Diviser le tableau en des sous-tableaux et trier les sous-tablaeux puis les fusionner à chaque fois  
        * Input :
            - a : list[int] -> Tableau à trier
            - dim : int -> la taille du tableau a
        
        ** On fait appel à 2 fonctions, une locale et une autre définie en dehors de la fonction principale
            * fusionRec():
                * Input : 
                    - g, d : int -> les indices du tableau a[g, d]
                * Output :
                    - None -> Rien (le traitement se fait sur le tableau)
                
                * fusion():
                    * Input :
                        - a, b : list[int] -> les sous-tableaux qu'on va fusionner
                        - g, d, m : int -> les indices du tableau t[g, d] et m l'indice de séparation
                    * Output : 
                        - None -> Rien (le traitement se fait sur les tableaux)
    
'''

def fusion(a : list[int], b : list[int], g : int, m : int, d : int) -> None:

    assert len(a) == len(b)

    i, j = g, m

    for k in range(g, d):
        if i < m and (j == d or a[i] < a[j]):
            b[k] = a[i]
            i += 1
        else:
            b[k] = a[j]
            j += 1
    return None

def tri_fusion(a : list[int], dim : int) -> int:

    b = a[:]

    def fusionRec(g : int, d : int):
        if g >= d - 1:
            return 
        m = (g + d) // 2
        fusionRec(g, m)
        fusionRec(m, d)
        b[g:d] = a[g:d]
        fusion(a, b, g, m, d)

    fusionRec(a, len(a))

    return None

