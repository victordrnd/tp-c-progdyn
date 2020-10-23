/**
 * @file knapsack.c
 * @author Victor DURAND (contact@victordurand.fr)
 * @version 0.1
 * @date 2020-10-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */


#include "knapsack.h"

/**
 * @brief  Sort object
 * @note   
 * @param  tab[]: Array of object to sort
 * @param  size: size of the array
 * @param  ascending: 0 or 1 for descending, asceneding
 * @retval None
 */
void insertionsort(Object tab[], int size, int ascending)
{
   int j;
   for (int i = 1; i < size; i++)
   {
      Object temp = tab[i];
      j = i - 1;
      while ((temp.cost/temp.weight < tab[j].cost/tab[j].weight) ^ ascending && j >= 0)
      {
            tab[j + 1] = tab[j];
            j = j - 1;
      }
      tab[j + 1] = temp;
   }
}

/**
 * @brief  Return best way of filling the max weight
 * @note   
 * @param  objects[]: array of object
 * @param  size: size of the array
 * @param  W: max weight
 * @retval None
 */
Object *knapsack(Object objects[], int size, int W){ 
    Object *result = malloc(100 * sizeof(Object));
    Object *wp = result;
    insertionsort(objects, size, DESCENDING);
    int current_weight = 0;
    for(int i =0; i < size; i++){
        if(current_weight + objects[i].weight <= W){
            current_weight += objects[i].weight;
            *wp = objects[i];
            wp++;
        }
    }
    return result;
}