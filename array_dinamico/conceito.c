/* 
Este documento contém o conceito da array dinâmica 
Se possível desenhem o estão fazendo. facilita e muito o entendimento do conteúdo.
*/

#include <stdio.h> // biblioteca padrão de entrada e saída
#include <stdlib.h> // biblioteca de alocação e de liberação de memoria

// declaração de estruturas.

struct array { // declaração de estrutura para armazenamento de array 
  int capacity; // capacidade da array
  int used; // espaço usado na array
  int *data; // ponteiro para array
};

typedef struct array* list; // renomeação do tipo da estrutura da array como ponteiro para estrutura de array

// implementação de funções.

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
  l = (list) malloc(sizeof(struct array)); // alocação de memória para a estrutura da array
  l->used = 0; // espaço usado inicial
  l->capacity = 10; // capacidade inicial
  l->data = (int*) malloc(sizeof(int) * l->capacity); // alocação de memória para o array
  return l; // retorno da função com estrutura de array
}

// função para alocar memória para a array
void array_alocar(list l) {
  int i, *new_data; // ponteiro para um novo array
    l->capacity += 10; // capacidade aumentada em 10
    new_data = (int*) malloc(sizeof(int) * l->capacity); // alocação de memória para novo array
    for (i = 0; i < l->used; i++) { // copia do velho array para o novo array
      new_data[i] = l->data[i];
    }
    int *old_data = l->data; // ponteiro para o array antigo
    l->data = new_data; // re-alocação do ponteiro para o novo array
    free(old_data); // libera memória do antigo array
}


// função para adicionar elementos no final da array 
void array_add(list l, int value) { // parametros de l (array) e value (valor a ser inserido)
  if(l->capacity == l->used) { // quando a array está cheia
    array_alocar(l); // alocação de memória para a nova array
  }
  l->data[l->used++] = value;
}

// função para inserir elemento na array na posição index AINDA EM DESENVOLVIMENTO
void array_insert(list l, int index, int value) { 
  if (index <= l->used) { // se o index for menor igual que o tamanho da array
    if(l->capacity == l->used) { // quando a array está cheia
      array_alocar(l); // alocação de memória para a nova array
    }
    int ant, pro;
    ant = l->data[index];
    l->data[index] = value;
    pro = l->data[index+1];
    for (index; index < l->used; index++) {
      ant = l->data[index];
      l->data[index] = pro;
      pro = l->data[index+1];
    }
  }  
}

// aqui criamos a array e testamos as funções
// compile com o comando: gcc conceito.c -o conceito
// execute com o comando: ./conceito < entrada.txt
// o programa deve executar com sucesso caso o arquivo entrada.txt exista.
// se não existir, gere o arquivo de entrada com o programa gerador.c
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