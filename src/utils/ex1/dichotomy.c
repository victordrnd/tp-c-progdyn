/**
 * @file dychotomy.c
 * @author Victor DURAND (contact@victordurand.fr)
 * @version 0.1
 * @date 2020-10-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */


#include "dichotomy.h"



/**
 * @brief  search index of value in array using dichotomie
 * @note   
 * @param  array[]: Array to search in
 * @param  size_t: size of the 
 * @param  value: 
 * @retval 
 */
int find_by_dichotomy(int array[], int size_t, int value)
{
    int middle = (size_t) >> 1;
    int low = 0;
    int high = size_t - 1;
    while (low <= high){
        int middle = (low + high) / 2;
        if(value > array[middle])
            low = middle +1;
        else if (value < array[middle])
            high = middle -1;
        else
            return middle;
    }
    return -1;
}



int find_by_dichotomy_recursive(int array[], int value, int low, int high){
    int middle = (low+high) >> 1;

    if(value == array[middle])
        return middle;

    if(value > array[middle]){
        return find_by_dichotomy_recursive(array, value, middle+1, high);
    }
    else{
        return find_by_dichotomy_recursive(array, value, low, middle-1);
    }
}