#include <stdio.h>
#include "utils/ex1/dichotomy.h"
#include <assert.h>
#include "utils/ex2/knapsack.h"
#include "utils/ex2/pgcd.h"

int main()
{
	int tab[10] = {3,7,8,8,10,12,34,40,55,99};
	assert(find_by_dichotomy_recursive(tab, 55, 0, 9) == 8);
	assert(find_by_dichotomy(tab,10, 7) == 1);


	Object o1, o2, o3;
	o1.weight = 6;o1.cost = 7;
	o2.weight = 5;o2.cost = 5;
	o3.weight = 5;o3.cost = 5;
	Object objects[3] = {o1, o2,o3};
	Object *backpack;
	backpack = knapsack(objects, 3, 10);
	Object *endPtr = backpack + sizeof(backpack)/sizeof(backpack[0]);
	while(backpack < endPtr){
		printf("L'object w : %d, c: %d\n", backpack->weight,backpack->cost);
		assert(backpack->weight == 6);
		assert(backpack->cost == 7);
		backpack++;
	}


	const int MATRICE_SIZE = 12;
	const int NB_BLACK_POINTS = 20;
	int **matrice = initMatrix(MATRICE_SIZE, NB_BLACK_POINTS);
	printf("\n");
	displayMatrix(matrice, MATRICE_SIZE);

	printf("\n\n");
	Coord coords = pgcb(matrice, MATRICE_SIZE);

	displayResultMatrice(matrice, MATRICE_SIZE, coords);
	return (0);
}