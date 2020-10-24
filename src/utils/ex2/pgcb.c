/**
 * @file pgcb.c
 * @author Victor DURAND (contact@victordurand.fr)
 * @version 0.1
 * @date 2020-10-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdlib.h>

#include "pgcd.h"
/**
 * @brief  Return min of two value
 * @note   
 * @param  a: value to compare 
 * @param  b: value to compare
 * @retval 
 */
int min(int a, int b)
{
    return a < b ? a : b;
}

/**
 * @brief  Fill the array
 * @note   
 * @param  size : Size of the array to fill  
 * @param  N : Number of obstacle in the matrix 
 * @retval 
 */
int **initMatrix(int size, int N)
{
    int **matrice = (int **)calloc(size, sizeof(int *));
    for (int i = 0; i < size; i++)
        matrice[i] = (int *)calloc(size, sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        int l_index = rand() % size;
        int c_index = rand() % size;
        matrice[l_index][c_index] = 1;
    }
    return matrice;
}

/**
 * @brief Display the array   
 * @param  matrice : Array to display 
 * @param  size : size of the array to display 
 * @retval None
 */
void displayMatrix(int **matrice, int size)
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


/**
 * @brief  Display the result array
 * @param  matrice: Array to display
 * @param  size : size of the array 
 * @param  c : Coord of the max square 
 * @retval None
 */
void displayResultMatrice(int **matrice, int size, Coord c){    
    for(int i = (c.x - c.size) + 1; i <= c.x; i++){
        for(int j = (c.y - c.size) + 1; j <= c.y; j++){
            matrice[i][j] = 2;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrice[i][j] == 0){
                printf("%c ", ' ');
                continue;
            }
            if (matrice[i][j] == 1){
                printf("%c ", '*');
                continue;
            }
            if(matrice[i][j] == 2)
                printf("%c ", '#');
        }
        printf("\n");
    }
}

/**
 * @brief  Find the max square in the matrix 
 * @param  matrice : Array to explore 
 * @param  size : Size of the array 
 * @retval 
 */
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


/**
 * @brief   Explore array to find biggest sqare
 * @param  matrice: array to explore and find biggest square 
 * @param  size: size of the array
 * @retval None
 */
Coord pgcb(int **matrice, int size)
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
    Coord coords = findMax(S, size);
    return coords;
    
}
