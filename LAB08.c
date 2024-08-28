#include <stdio.h>
#include <stdlib.h>

#define tam_hash 11

typedef struct Celula {
    int valor;
    struct Celula* prox;
} Celula;

typedef struct {
    Celula* inicio;
} Lista;

typedef struct {
    Lista tabela[tam_hash];
} Hash;

int funcao_hash(int valor) {
    return valor % tam_hash;
}

Hash* start_hash() {
    Hash* hash = (Hash*)malloc(sizeof(Hash));
    if (hash == NULL) {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < tam_hash; i++) {
        hash->tabela[i].inicio = NULL;
    }
    return hash;
}

void inserir_hash(Hash* hash, int valor) {
    int posicao = funcao_hash(valor);
    Celula* nova_celula = (Celula*)malloc(sizeof(Celula));
    if (nova_celula == NULL) {
        printf("Erro ao alocar memória para a nova célula.\n");
        exit(EXIT_FAILURE);
    }
    nova_celula->valor = valor;
    nova_celula->prox = hash->tabela[posicao].inicio;
    hash->tabela[posicao].inicio = nova_celula;
}

void remover_hash(Hash* hash, int valor) {
    int posicao = funcao_hash(valor);
    Celula* atual = hash->tabela[posicao].inicio;
    Celula* anterior = NULL;
    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) {
        return;
    }
    if (anterior == NULL) {
        hash->tabela[posicao].inicio = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }
    free(atual);
}

void imprimir(Hash* hash) {

    printf("---------------------");
    printf("\n");
    for (int i = 0; i < tam_hash; i++) {
        printf("%d -> ", i);
        Celula* atual = hash->tabela[i].inicio;
        while (atual != NULL) {
            printf("%d ", atual->valor);
            atual = atual->prox;
            }
          printf("\n");
        
        }
         printf("---------------------");
      printf("\n");
    }


int main(void) {
    Hash* hash = start_hash();
    int valor;
    while (1) {
        scanf("%d", &valor);
        if (valor == 0)
            break;
        inserir_hash(hash, valor);
    }
    imprimir(hash);
    while (1) {
        scanf("%d", &valor);
        if (valor == 0)
            break;
        remover_hash(hash, valor);
    }
    imprimir(hash);
    return 0;
}

