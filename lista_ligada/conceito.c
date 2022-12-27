#include <stdio.h>
#include <stdlib.h>

// declarações de estrutura de lista e nós
struct no {
  int valor;
  struct no *prox;
  struct no *ante;
};

struct lista_ligada {
  struct no *inicio;
  struct no *fim;
  int tamanho;
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
  return l;
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
    l->fim->prox = n;
    n->prox = 0;
    n->ante = l->fim;
    l->fim = n;
  }
  l->tamanho++;
}

void lista_mostrar(lista l) {
  no atual = l->inicio;
  for (int i = 0; i < l->tamanho; i++) {
    printf("%d ", atual->valor);
    if (atual->prox != 0) {
      atual = atual->prox;
    }
  }
  printf("\n");
}

// Função para testar lista ligada
int main() {
  lista l = lista_criar();
  
  lista_add(l, 15);
  lista_add(l, 89);
  lista_add(l, -9);
  lista_add(l, 0);
  lista_add(l, 1101001);
  lista_mostrar(l);

  printf("tamanho: %d\n", l->tamanho);
  return 0;
}