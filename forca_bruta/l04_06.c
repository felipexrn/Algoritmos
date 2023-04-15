#include <stdio.h>

struct cost {
  int way;
};

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

int best_way_from_A_to_B(int l, int c, int l_end, int c_end, int maze[7][7], int lin, int col, struct cost* way_cost) {
  int cell = maze[l][c];
  if (l == l_end && c == c_end ) {
    maze[l][c] = -3;
    printf("\n");
    print_maze(lin, col, maze);
    maze[l][c] = cell;
    way_cost->way += cell;
    return 1;
  }
  if (maze[l][c] < 0 || l == lin || c == col || l < 0 || c < 0) {
     return 0;
    }
  const int INF = 1001;
  int ans1 = INF, ans2 = 0; 
  maze[l][c] = -2;
  ans1 = best_way_from_A_to_B(l+1, c, l_end, c_end, maze, lin, col, way_cost);
  ans2 = best_way_from_A_to_B(l, c+1, l_end, c_end, maze, lin, col, way_cost);
  if(ans2 < ans1) ans1 = ans2;
  ans2 = best_way_from_A_to_B(l-1, c, l_end, c_end, maze, lin, col, way_cost);
  if(ans2 < ans1) ans1 = ans2;
  ans2 = best_way_from_A_to_B(l, c-1, l_end, c_end, maze, lin, col, way_cost);
  if(ans2 < ans1) ans1 = ans2;
  maze[l][c] = cell;
  way_cost->way += cell;
  return ans1;
}

int main() {
  int l_start, c_start, lin, col, l_end, c_end;
  struct cost* way_cost = malloc(sizeof(struct cost)); 
  way_cost->way = 0;
  scanf("%d %d", &lin, &col);
  scanf("%d %d", &l_start, &c_start);
  scanf("%d %d", &l_end, &c_end);
  int maze[lin][col];
  read_maze(lin, col, maze);
  //print_maze(lin, col, maze);
  int ans = best_way_from_A_to_B(l_start, c_start, l_end, c_end, maze, lin, col, way_cost);
  printf("\n%d\n", ans);
  printf("\n%d\n", way_cost->way);
  return 0;
}