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

int can_i_walk_from_A_to_B(int l, int c, int l_end, int c_end, int maze[7][7], int lin, int col) {
  if (l == l_end && c == c_end ) {
    maze[l][c] = 8;
    printf("\n");
    print_maze(lin, col, maze);
    maze[l][c] = 0;
    return 1;
  }
  if (maze[l][c] != 0 || l == lin || c == col || l < 0 || c < 0) return 0;
  int ans = 0; 
  maze[l][c] = 2;
  ans += can_i_walk_from_A_to_B(l+1, c, l_end, c_end, maze, lin, col);
  if(ans == 1) return 1;
  ans += can_i_walk_from_A_to_B(l, c+1, l_end, c_end, maze, lin, col);
  if(ans == 1) return 1;
  ans += can_i_walk_from_A_to_B(l-1, c, l_end, c_end, maze, lin, col);
  if(ans == 1) return 1;
  ans += can_i_walk_from_A_to_B(l, c-1, l_end, c_end, maze, lin, col);
  if(ans == 1) return 1;
  maze[l][c] = 0;
  return ans;
}

int main() {
  int l_start, c_start, lin, col, l_end, c_end;
  scanf("%d %d", &lin, &col);
  scanf("%d %d", &l_start, &c_start);
  scanf("%d %d", &l_end, &c_end);
  int maze[lin][col];
  read_maze(lin, col, maze);
  //print_maze(lin, col, maze);
  int ans = can_i_walk_from_A_to_B(l_start, c_start, l_end, c_end, maze, lin, col);
  printf("\n%d\n", ans);
  return 0;
}