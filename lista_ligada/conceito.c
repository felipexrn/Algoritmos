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
  return l; // retorno da função com a lista criada
}

void lista_add(lista l, int valor) { // função para acionar elementos na lista
  no n; // ponteiro para nó da lista
  n = (no) malloc(sizeof(struct no)); // alocação de memória para nó da lista
  n->valor = valor; // atribuição do valor a ser armazendado
  if(l->tamanho == 0) { // caso a lista estiver vazia
    n->prox = 0; // não há próximo nó (este é o único)
    n->ante = 0; // não há nó anterior (este é o primeiro)
    l->inicio = n; // início da lista é o próprio nó
    l->fim = n; // fim da lista é o próprio nó
  } else { // caso a lista não estiver vazia 
    l->fim->prox = n; // o próximo do anterior é o novo nó
    n->prox = 0; // o próximo do dó atual é zero (ele é o último da lista)
    n->ante = l->fim; // o anterior recebe o antifo fim da lista
    l->fim = n; // o fim da lista é o novo nó
  }
  l->tamanho++; // acrescenta o tamanho da lista em 1
}

void lista_mostrar(lista l) { // função para mostrar lista
  no atual = l->inicio; // ponteiro auxiliar do tipo nó 
  for (int i = 0; i < l->tamanho; i++) { // percorre a lista pelo tamanho
    printf("%d ", atual->valor); // exibe valor do nó atual
    if (atual->prox != 0) { // se o próximo nó existe
      atual = atual->prox; // aponta para o próximo nó
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