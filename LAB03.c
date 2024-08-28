#include <stdio.h>
#define LEN 10

typedef struct {
  int values[LEN];
  int n;
} Lista;

int is_full(Lista *lista){
  return lista -> n == LEN;
}

int is_empty(Lista *lista){
  return lista->n == 0;
}

int buscar(Lista *lista, int valor){
  int idx = 0;
  while(idx < lista -> n && lista -> values [idx] <= valor )
    idx++;
  return idx;
}

void mover(Lista *lista, int idx){
  for(int i = lista ->n; i > idx; i --)    
    lista -> values[i] = lista -> values[i - 1];
}

int inserir(Lista *lista, int valor){
  if(is_full(lista))
    return 0;
  int idx = 0;
  if(!is_empty(lista)){
    idx = buscar(lista, valor);
    mover(lista, idx);
    
    
  }
  lista -> values[idx] = valor;
  lista-> n ++;
  return 1;
}


  
}

int main(void) {
  
  return 0;
}
