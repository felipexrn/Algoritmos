/* 
Este documento contém o conceito da lista duplamente ligada 
Se possível desenhem o estão fazendo. facilita e muito o entendimento do conteúdo.
*/

#include <stdio.h> // biblioteca padrão de entrada e saída
#include <stdlib.h> // biblioteca padrão de liberação de memoria

// declarações de estrutura de lista e nós
struct no { // estrutura para nós da lista duplamente ligada
  int valor; // armazena valor do nó
  struct no *prox; // armazena ponteiro para próximo nó
  struct no *ante; // armazena ponteiro para nó anterior
};

struct lista_ligada { // estrutura da lista
  struct no *inicio; // armazena nó do início da lista
  struct no *fim; // armazena nó do fim da lista
  int tamanho; // armazena tamanho da lista
};

typedef struct lista_ligada* lista; // re-declaração de tipo da lista
typedef struct no* no; // re-declaração de tipo do nó

//implementações de funções
lista lista_criar() { // função para criar lista duplamente ligada
  lista l; // ponteiro do tipo lista
  l = (lista)malloc(sizeof(struct lista_ligada)); // alocação de memória da lista duplamente ligada
  l->inicio = 0; // valor inicial do ponteiro para o inicio da lista
  l->fim = 0; // valor inicial do ponteiro para o fim da lista 
  l-> tamanho = 0; // valor inicial do tamamanho da lista
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