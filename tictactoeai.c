#include "tictactoeai.h"
#include <stdio.h>
#include <stdlib.h>

int **insert_x(int **matrix, int index) {
  int **m = malloc(sizeof(int *) * 3);
  for (int i = 0; i < 3; ++i) {
    m[i] = malloc(sizeof(int) * 3);
    for (int j = 0; j < 3; ++j) {
      m[i][j] = matrix[i][j];
    }
  }
  if (index < 3) {
    m[0][index] = 2;
  }
  if (index < 6) {
    int i = index - 3;
    m[1][i] = 2;
  }
  if (index < 9) {
    int i = index - 6;
    matrix[2][i] = 2;
  }
  return m;
}

int calculate_score(int **matrix) {
  int score = 0;
  // calculate score for each row
  if (matrix[0][0] == 1 || matrix[0][1] == 1 || matrix[0][2] == 1) {
    if (matrix[0][0] != 2 && matrix[0][1] != 2 && matrix[0][2] != 2) {
      score++;
    }
  }
  if (matrix[1][0] == 1 || matrix[1][1] == 1 || matrix[1][2] == 1) {
    if (matrix[1][0] != 2 && matrix[1][1] != 2 && matrix[1][2] != 2) {
      score++;
    }
  }
  if (matrix[2][0] == 1 || matrix[2][1] == 1 || matrix[2][2] == 1) {
    if (matrix[2][0] != 2 && matrix[2][1] != 2 && matrix[2][2] != 2) {
      score++;
    }
  }
  // calculate score for each column
  if (matrix[0][0] == 1 || matrix[1][0] == 1 || matrix[2][0] == 1) {
    if (matrix[0][0] != 2 && matrix[1][0] != 2 && matrix[2][0] != 2) {
      score++;
    }
  }
  if (matrix[0][1] == 1 || matrix[1][1] == 1 || matrix[2][1] == 1) {
    if (matrix[0][1] != 2 && matrix[1][1] != 2 && matrix[2][1] != 2) {
      score++;
    }
  }
  if (matrix[0][2] == 1 || matrix[1][2] == 1 || matrix[2][2] == 1) {
    if (matrix[0][2] != 2 && matrix[1][2] != 2 && matrix[2][2] != 2) {
      score++;
    }
  }
  // calculate score for each diameter
  if (matrix[0][0] == 1 || matrix[1][1] == 1 || matrix[2][2] == 1) {
    if (matrix[0][0] != 2 && matrix[1][1] != 2 && matrix[2][2] != 2) {
      score++;
    }
  }
  if (matrix[0][2] == 1 || matrix[1][1] == 1 || matrix[2][0] == 1) {
    if (matrix[0][2] != 2 && matrix[1][1] != 2 && matrix[2][0] != 2) {
      score++;
    }
  }
  return score;
}

int **answer(int **matrix) {
  // validate input state
  int ones = 0;
  int twos = 0;
  int *empty_houses = (int *)malloc(sizeof(int) * 9);
  int empty_counter = 0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (matrix[i][j] == 1) {
        ones++;
      }
      if (matrix[i][j] == 2) {
        twos++;
      }
      if (matrix[i][j] == 0) {
        if (i == 0) {
          empty_houses[empty_counter++] = j;
        }
        if (i == 1) {
          empty_houses[empty_counter++] = 3 + j;
        }
        if (i == 2) {
          empty_houses[empty_counter++] = 6 + j;
        }
      }
    }
  }
  // input state is invalid
  if (ones != twos + 1) {
    printf("%s\n", "Invalid input");
    return NULL;
  }
  tree *t = (tree *)malloc(sizeof(tree));
  t->leafs = (node *)malloc(sizeof(node) * empty_counter);
  for (int i = 0; i < empty_counter; ++i) {
    t->leafs[i].matrix = insert_x(matrix, empty_houses[i]);
    t->leafs[i].score = calculate_score(t->leafs[i].matrix);
  }
  node current = t->leafs[0];
  int **ans = t->leafs[0].matrix;
  for (int i = 0; i < empty_counter; ++i) {
    if (current.score > t->leafs[i].score) {
      current = t->leafs[i];
      ans = current.matrix;
    }
  }
  return ans;
}
