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

int find_exit_ways(int l, int c, int lin, int col, int maze[7][7]) {
  if (l == lin - 1 && c == col-1 ) {
    //printf("\n");
    //print_maze(lin, col, maze);
    return 1;
  }
  if (maze[l][c] != 0 || l == lin || c == col || l < 0 || c < 0) return 0;
  int ans = 0; 
  maze[l][c] = 2;
  ans += find_exit_ways(l+1, c, lin, col, maze);
  ans += find_exit_ways(l, c+1, lin, col, maze);
  ans += find_exit_ways(l-1, c, lin, col, maze);
  ans += find_exit_ways(l, c-1, lin, col, maze);
  maze[l][c] = 0;
  return ans;
}

int main() {
  int l = 0, c = 0, lin, col, maze[7][7];
  scanf("%d %d", &lin, &col);
  read_maze(lin, col, maze);
  //print_maze(lin, col, maze);
  int ans = find_exit_ways(l, c, lin, col, maze);
  printf("%d\n", ans);
  return 0;
}