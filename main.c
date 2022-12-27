#include <stdio.h>
#include <stdlib.h>

// arquivo.h
struct array {
  int capacity;
  int used;
  int *data;
};

typedef struct array* list;

// arquivo.c
void listar(list l) {
  for (int i = 0; i < l->used; i++) {
    printf("%d ", l->data[i]);
  }
  printf("\n");
}

list lista_criar() {
  list l;
  l = (list) malloc(sizeof(struct array));
  l->used = 0;
  l->capacity = 10;
  l->data = (int*) malloc(sizeof(int) * l->capacity);
  return l;
}

void add(list l, int value) {
  if(l->capacity == l->used) {
    int i, *new_data;
    l->capacity += 10;
    new_data = (int*) malloc(sizeof(int) * l->capacity);
    for (i = 0; i < l->used; i++) {
      new_data[i] = l->data[i];
    }
    int *old_data = l->data;
    l->data = new_data;
    free(old_data);
  }
  
  l->data[l->used++] = value;
}

//main.c
int main() {
  list l = lista_criar();
  
  add(l, 1);
  add(l, 2);
  add(l, 3335);
  add(l, 4);
  add(l, 9);
  add(l, 10);
  add(l, -1);
  add(l, 150);
  add(l, 14);
  add(l, 15);
  add(l, 777);
  add(l, 158);
  
  listar(l);
  free(l);
    
  return 0;
}