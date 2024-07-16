#undef TICTACTOEAI_H
#define TICTACTOEAI_H
#define NULL 0
typedef struct node{
   int score;
   int** matrix;
}node;

typedef struct tree{
   node* leafs;
}tree;

int** insert_x(int** matrix,int index);

int calculate_score(int** matrix);

/* 
 * first recieves a matrix then
 * return a matrix of 0,1,2
 * 0 represents emptry space
 * 1 represents O (O starts the game)
 * 2 represents X
 * if input is invalid the result will be NULL
 */
int** answer(int** plate);



