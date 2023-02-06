#include <stdio.h>

void read_maze(int lin, int col, int maze[7][7]) {
  for (int l = 0; l < lin; l++) {
    for (int c = 0; c < col; c++) {
      int cell;
      scanf("%d", &cell);
      maze[c][l] = cell; 
    }
  }
}

void print_maze(int lin, int col, int maze[7][7]) {
  for (int l = 0; l < lin; l++) {
    for (int c = 0; c < col; c++) {
      int cell = maze[c][l];
      printf("%d ", cell);
    }
    printf("\n");
  }
}

int find_exit_way(int lin, int col, int maze[7][7]) {
  int ans = 0;
  if ()
  return ans;
}

int main() {
  int lin, col, maze[7][7];
  scanf("%d %d", &lin, &col);
  read_maze(lin, col, maze);
  //print_maze(lin, col, maze);
  int ans = find_exit_way(lin, col, maze);
  printf("%d\n", ans);
  return 0;
}