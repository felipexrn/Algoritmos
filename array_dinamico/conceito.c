/* 
Este documento contém o conceito da array dinâmica 
Se possível desenhem o estão fazendo. facilita e muito o entendimento do conteúdo.
*/

#include <stdio.h> // biblioteca padrão de entrada e saída
#include <stdlib.h> // biblioteca padrão de liberação de memoria

// declaração de estruturas e declaração de funções. Este conteúdo deve ir para um arquivo.h 

struct array { // declaração de estrutura para armazenamento de array 
  int capacity; // capacidade da array
  int used; // espaço usado na array
  int *data; // ponteiro para array
};

typedef struct array* list; // renomeação do tipo da estrutura da array








// implementação de funções. Este conteúdo deve ir para um arquivo.c

// função para exibir array no console
void listar(list l) {
  for (int i = 0; i < l->used; i++) {
    printf("%d ", l->data[i]);
  }
  printf("\n");
}

// função para criar nova array
list array_criar() {
  list l;
  l = (list) malloc(sizeof(struct array));
  l->used = 0;
  l->capacity = 10;
  l->data = (int*) malloc(sizeof(int) * l->capacity);
  return l;
}

// função para adicionar elementos na array
void array_add(list l, int value) {
  if(l->capacity == l->used) {
    int i, *new_data;
    l->capacity += 10;
    new_data = (int*) malloc(sizeof(int) * l->capacity);
    for (i = 0; i < l->used; i++) {
      new_data[i] = l->data[i];
    }
    int *old_data = l->data;
    l->data = new_data;
    free(old_data); // libera memória da antiga array
  }
  
  l->data[l->used++] = value;
}









// aqui criamos a array e testamos as funções main.c
int main() {
  list l = array_criar(); // cria uma array dinâmica na memória
  
  int n, m;
  scanf("%d", &n); // lê quantidade de dados a serem inseridos na array
  for (int i = 0; i < n; i++) {
    scanf("%d", &m); // lê valor do console
    array_add(l, m); // adiciona valor lido do console na array
  }
  
  listar(l); // mostra a array no console
  printf("capacidade: %d usada: %d\n", l->capacity, l->used); // mostra capacidade e espaço usado da array
  free(l); // libera memória da array
    
  return 0;
}