#include <stdio.h>

struct caminho{
  int tamanho;
  int l[110],c[110];
};

void print_caminho(struct caminho *cam) {
  printf("Caminho encontrado: ");
  for (int i=0 ; i<cam->tamanho ; ++i)
    printf("(%d,%d) ",cam->l[i],cam->c[i]);
  printf("\n");
}

int find_lab_bt(int lab[10][10], int lin, int col, int l, int c, struct caminho *cam){
  if (l==lin-1 && c==col-1) {
    print_caminho(cam);
  return 1;
  }
  
  if (lab[l][c]!=0 || l<0 || c<0 || l==lin || c==col){
    return 1000000;
  }
  
  int ans = 1000000;
  lab[l][c]=2;
  cam->l[cam->tamanho] = l;
  cam->c[cam->tamanho] = c;
  cam->tamanho++;
  ans = find_lab_bt(lab,lin,col,l+1,c, cam);
  int ans_alt = find_lab_bt(lab,lin,col,l,c+1,cam);
  if (ans_alt < ans) ans = ans_alt;
    ans_alt = find_lab_bt(lab,lin,col,l-1,c,cam);
  if (ans_alt < ans) ans = ans_alt;
    ans_alt = find_lab_bt(lab,lin,col,l,c-1,cam);
  if (ans_alt < ans) ans = ans_alt;
    lab[l][c]=0;
  cam->tamanho--;
  return ans+1;
}

int find_lab(int lab[10][10], int lin, int col, struct caminho *cam){
  return find_lab_bt(lab,lin,col,0,0, cam);
}

void read_lab(int lab[10][10], int lin, int col){
  int i,j;
  for (i=0 ; i<lin ; ++i)
  for (j=0 ; j<col ; ++j)
  scanf("%d",&lab[i][j]);
}

void print_maze(int lin, int col, int lab[10][10]) {
  for (int l = 0; l < lin; l++) {
    for (int c = 0; c < col; c++) {
      int cell = lab[c][l];
      printf("%d ", cell);
    }
    printf("\n");
  }
}

int main() {
  int lab[10][10],lin,col;
  struct caminho cam;
  cam.tamanho=0;
  scanf("%d %d",&lin,&col);
  read_lab(lab,lin,col);
  int sol = find_lab(lab,lin,col,&cam);
  printf("%d\n",sol);
  return 0;
}