
typedef struct{
    int x;
    int y;
    int size;
} Coord;

int max(int a,int b);

int **initMatrix(int size,int N);

void displayMatrix(int **matrice,int size);

void displayResultMatrice(int **matrice, int size, Coord c);

Coord pgcb(int **matrice,int size);