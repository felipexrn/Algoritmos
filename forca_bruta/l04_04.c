#include <stdio.h>

void read_maze(int lin, int col, int maze[7][7]) {
  for (int l = 0; l < lin; l++) {
    for (int c = 0; c < col; c++) {
      int cell;
      scanf("%d", &cell);
      maze[l][c] = cell; 
    }
  }
}

void print_maze(int lin, int col, int maze[7][7]) {
  for (int l = 0; l < lin; l++) {
    for (int c = 0; c < col; c++) {
      int cell = maze[l][c];
      printf("%d ", cell);
    }
    printf("\n");
  }
}

int find_best_exit_way(int l, int c, int lin, int col, int maze[7][7]) {
  if (l == lin - 1 && c == col-1 ) {
    maze[l][c] = 8;
    printf("\n");
    print_maze(lin, col, maze);
    maze[l][c] = 0;
    return 1;
  }
  const int INF = (lin * col);
  if (maze[l][c] != 0 || l == lin || c == col || l < 0 || c < 0) return INF;
  int ans1 = INF, ans2 = 0; 
  maze[l][c] = 2;
  ans1 = find_best_exit_way(l+1, c, lin, col, maze);
  ans2 = find_best_exit_way(l, c+1, lin, col, maze);
  if (ans2 < ans1) ans1 = ans2;
    ans2 = find_best_exit_way(l-1, c, lin, col, maze);
  if (ans2 < ans1) ans1 = ans2;
    ans2 = find_best_exit_way(l, c-1, lin, col, maze);
  if (ans2 < ans1) ans1 = ans2;
  maze[l][c] = 0;
  return ans1 + 1;
}

int main() {
  int l = 0, c = 0, lin, col, maze[7][7];
  scanf("%d %d", &lin, &col);
  read_maze(lin, col, maze);
  //print_maze(lin, col, maze);
  int ans = find_best_exit_way(l, c, lin, col, maze);
  printf("\n%d\n", ans);
  return 0;
}