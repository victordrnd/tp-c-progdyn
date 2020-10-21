#include "pgcd.h"

int min(int a, int b)
{
    return a < b ? a : b;
}

/**
 * @brief  
 * @note   
 * @param  size: 
 * @param  N: 
 * @retval 
 */
int **fillArray(int size, int N)
{
    int **matrice = (int **)calloc(size, sizeof(int *));
    for (int i = 0; i < size; i++)
        matrice[i] = (int *)calloc(size, sizeof(int));

    for (int i = 0; i < N; i++)
    {
        int l_index = rand() % (size - 1);
        int c_index = rand() % (size - 1);
        matrice[l_index][c_index] = 1;
    }
    return matrice;
}

void displayMatrice(int **matrice, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", matrice[i][j]);
            // if (matrice[i][j] == 0)
            //     printf("%c ", '+');
            // if (matrice[i][j] == 1)
            //     printf("%c ", '#');
        }
        printf("\n");
    }
}


void displayResultMatrice(int **matrice, int size, Coord c)
{    
    for(int i = (c.x - c.size) + 1; i < c.x +1; i++){
        for(int j = (c.y - c.size) + 1; j < c.y+1; j++){
            matrice[i][j] = 2;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrice[i][j] == 0)
                printf("%c ", ' ');
            if (matrice[i][j] == 1)
                printf("%c ", '*');
            if(matrice[i][j] == 2)
                printf("%c ", '#');
        }
        printf("\n");
    }
}


Coord findMax(int **matrice, int size)
{
    int max = 0;
    Coord coords;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrice[i][j] >= max)
            {
                max = matrice[i][j];
                coords.x = i;
                coords.y = j;
                coords.size = max/2;
            }
        }
    }
    return coords;
}

void pgcb(int **matrice, int size)
{
    int **S = (int **)calloc(size, sizeof(int *));
    for (int i = 0; i < size; i++)
        S[i] = (int *)calloc(size, sizeof(int));

    S[0] = matrice[0];
    for (int l = 1; l < size; l++)
    {
        S[l][0] = matrice[l][0];
    }

    for (int i = 1; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (matrice[i][j] == 0)
                S[i][j] = min(S[i][j - 1], min(S[i - 1][j], S[i - 1][j - 1])) + 2;
            else if (matrice[i][j] == 1)
                S[i][j] = 1;
        }
    }
    displayMatrice(S, size);
    printf("\n");
    Coord coord = findMax(S, size);
    displayResultMatrice(matrice, size, coord);
}
