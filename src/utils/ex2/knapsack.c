#include "knapsack.h"

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
 * @brief  
 * @note   
 * @param  objects[]: 
 * @param  size: size of the array
 * @param  W: max weight
 * @retval None
 */
Object *knapsack(Object objects[], int size, int W){ 
    Object *result = malloc(100 * sizeof(Object));
    insertionsort(objects, size, DESCENDING);
    int current_weight = 0;
    for(int i =0; i < size; i++){
        if(current_weight + objects[i].weight < W){
            current_weight += objects[i].weight;
            result = &objects[i];
            result++;
        }
    }
    return result;
}