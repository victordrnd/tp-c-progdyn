#include <stdio.h>
#include "utils/ex1/dichotomy.h"
#include <assert.h>
#include "utils/ex2/knapsack.h"
#include "utils/ex2/pgcd.h"

int main()
{
	int tab[10] = {3,7,8,8,10,12,34,40,55, 99};
	assert(find_by_dichotomy(tab,10, 55) == 8);
	assert(find_by_dichotomy(tab,10, 7) == 1);


	Object o1, o2, o3;
	o1.weight = 6;o1.cost = 7;
	o2.weight = 5;o2.cost = 5;
	o3.weight = 5;o3.cost = 5;
	Object objects[3] = {o1, o2,o3};
	Object *backpack = malloc(30 * sizeof(Object));
	backpack = knapsack(objects, 3, 10);
	struct MyData* endPtr = backpack + sizeof(backpack)/sizeof(backpack[0]);
	while(backpack <= endPtr){
		printf("L'object w : %d, c: %d\n", backpack->weight,backpack->cost);
		backpack++;
	}

	int **matrice = fillArray(10, 21);
	printf("\n");
	displayMatrice(matrice, 10);

	printf("\n\n");
	pgcb(matrice, 10);

	return (0);
}