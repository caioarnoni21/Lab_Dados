#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
  int valor;
  struct Celula *proximo;
} Celula;

typedef struct{
  int qtde; 
  Celula *primeiro; 
} LDE;

LDE *cria_LDE(){
  LDE *lde = malloc(sizeof(LDE));
  lde -> primeiro = NULL;
  lde -> qtde = 0;
    return lde;
}

Celula *cria_Celula(int valor){
  Celula * celula = malloc(sizeof(Celula));
  celula -> proximo = NULL;
  celula -> valor = valor;
  return celula;
}

void inserir(LDE *lde, int valor){
  Celula * novo = cria_Celula(valor);
  if(lde -> qtde == 0){
    lde -> primeiro = novo;
    lde -> qtde ++;
  } else {
    Celula * atual = lde -> primeiro;
    Celula *anterior = NULL;
    while (atual != NULL && atual -> valor < valor){
      anterior = atual;
      atual = atual -> proximo;
    }
    if(anterior == NULL && atual != NULL){
      novo -> proximo = atual;
      lde -> primeiro;
      lde ->qtde++;
    }
    if(anterior != NULL && atual == NULL){
      anterior -> proximo = novo;
      lde ->qtde++;
    }
    if(anterior != NULL && atual != NULL){
      anterior -> proximo = novo;
      novo -> proximo = atual;
      lde ->qtde++;
    }
  }
}

void mostrar(LDE*lde){
  Celula *atual = lde -> primeiro;
  while(atual != NULL){
    printf("%d", atual-> valor);
    atual = atual -> proximo;
  }
  printf("\n");
}

int main(void){
  int valores[] = {0 , 9, 8, 7, 6, 5, 4, 3, 2, 1,};
  int tamanho = sizeof(valores) / sizeof(int);
  LDE *lde = cria_LDE();
  for(int i = 0; i < tamanho; i++){
    inserir(lde, valores[i]);
    mostrar(lde);
  }
  return 0;
}



