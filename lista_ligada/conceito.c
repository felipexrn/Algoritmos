#include <stdio.h>
#include <stdlib.h>

// declarações de estrutura de lista e nós
struct lista_ligada {
  int *inicio;
  int *fim;
  int tamanho;
};

struct no {
  int valor;
  struct no *prox;
  struct no *ante;
};

typedef struct lista_ligada* lista;
typedef struct no* no;

//implementações de funções
lista lista_criar() {
  lista l;
  l = (lista)malloc(sizeof(struct lista_ligada));
  l->inicio = 0;
  l->fim = 0;
  l-> tamanho = 0;
}

void lista_add(lista l, int valor) {
  no n;
  n = (no) malloc(sizeof(struct no));
  n->valor = valor;
  if(l->tamanho == 0) {
    n->prox = 0;
    n->ante = 0;
    l->inicio = n;
    l->fim = n;
    
  } else {
    n->prox = 0;
    n->ante = l->fim;
    l->fim = n;
  }
  l->tamanho++;
}

void lista_mostrar(lista l) {
  int i;
  for (i = 0; i < l->tamanho; i++) {
    
  }
}

// Função para testar lista ligada
int main() {
  lista l = lista_criar();
  lista_add(l, 15);
  lista_add(l, 15);
  
  return 0;
}