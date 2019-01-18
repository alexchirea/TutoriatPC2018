#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elev
{
    char nume[30], prenume[30];
    int grupa;
    float medie;
    struct elev *next;
} elev;

void insert(elev **root, elev **end, char *n, char *p, int g, float m)
{
    elev *e = (elev*)malloc(sizeof(elev));
    strcpy(e->nume, n);
    strcpy(e->prenume, p);
    e->grupa = g;
    e->medie = m;
    e->next = NULL;
    if (*root == NULL)
    {
        *root = e;
        *end = e;
        return;
    }
    (*end)->next = e;
    *end = e;
    return;
}

void afisare(elev *root)
{
    elev *aux = root;
    while (aux != NULL)
    {
        printf("%s %s %d %.2f\n", aux->nume, aux->prenume, aux->grupa, aux->medie);
        aux = aux->next;
    }
    return;
}

void grupa(elev *root, int grupa)
{
    elev *aux = root;
    while (aux != NULL)
    {
        if (aux->grupa == grupa)
            printf("%s %s %d %.2f\n", aux->nume, aux->prenume, aux->grupa, aux->medie);
        aux = aux->next;
    }
    return;
}

void interschimba(elev *a, elev *b)
{
    elev aux;
    elev *aNext = a->next;
    elev *bNext = b->next;
    memcpy(&aux, a, sizeof(elev));
    memcpy(a, b, sizeof(elev));
    memcpy(b, &aux, sizeof(elev));
    a->next = aNext;
    b->next = bNext;
    return;
}

void sortare(elev *root)
{
    int o = 0;
    while (o == 0)
    {
        o = 1;
        elev *aux = root;
        while (aux != 0)
        {
            if (strcmp(aux->nume, aux->next->nume) > 0)
            {
                o = 0;
                interschimba(aux, aux->next);
            }
            else if (strcmp(aux->nume, aux->next->nume) == 0)
            {
                if (aux->medie < aux->next->medie)
                {
                    o = 0;
                    interschimba(aux, aux->next);
                }
            }
            
            if (aux->next->next == 0) break;
            aux = aux->next;
        }
    }
}

int main()
{
    elev *root, *end;
    root = end = 0;
    insert(&root, &end, "Popescu", "Andrei", 152, 9.35);
    insert(&root, &end, "Zidaru", "Ioana", 153, 7.55);
    insert(&root, &end, "Ionescu", "Ana", 153, 8.25);
    insert(&root, &end, "Popescu", "Maria", 152, 9.75);
    
    grupa(root, 152);
    printf("\n\n##Inainte de sortare \n");
    afisare(root);
    
    printf("\n\n##Dupa sortare \n");
    sortare(root);
    afisare(root);
    return 0;
}
