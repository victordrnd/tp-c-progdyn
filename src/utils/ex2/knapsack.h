#define DESCENDING 0

typedef struct {
    int cost;
    int weight;
} Object;


Object *knapsack(Object objects[], int size, int W);