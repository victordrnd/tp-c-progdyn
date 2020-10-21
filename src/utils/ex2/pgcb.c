/**
 * @brief  
 * @note   
 * @param  size: 
 * @param  N: 
 * @retval 
 */
int **fillArray(int size,int N){
    int **matrice = calloc(size * sizeof(int*));
    // int matrice[size][size];
    // for(int l = 0; l < size; l++){
    //     for(int c = 0; c < size; c++){
    //         matrice[l][c] = 0;
    //     }
    // }
    for(int i = 0; i < N; i++){
        int l_index = rand() % size;
        int c_index = rand() % size;
        matrice[l_index][c_index] = 1;
    }
    return matrice;
}