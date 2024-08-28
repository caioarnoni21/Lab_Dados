#include <stdio.h>
#include <stdlib.h>

#define LEN 10

typedef struct {
  int valores[LEN];
  int qtde;
} heap;

int filho_esq(int pai) { return (2 * pai) + 1; }

int filho_dir(int pai) { return (2 * pai) + 2; }

int pai(int filho) { return (filho - 1) / 2; }

int ultimo_pai(heap *h) { return (h->qtde / 2) - 1; }

void peneirar(heap *h, int pai) {
  int esq = filho_esq(pai);
  int dir = filho_dir(pai);
  int maior = pai;

  if (esq < h->qtde && h->valores[esq] > h->valores[maior]) {
    maior = esq;
  }

  if (dir < h->qtde && h->valores[dir] > h->valores[maior]) {
    maior = dir;
  }

  if (maior!= pai) {
    int tmp = h->valores[pai];
    h->valores[pai] = h->valores[maior];
    h->valores[maior] = tmp;
    peneirar(h, maior);
  }
}

void construir(heap *h) {
  for (int i = ultimo_pai(h); i >= 0; i--) {
    peneirar(h, i);
  }
}

void inserir(heap *h, int valor) {
  h->valores[h->qtde] = valor;
  h->qtde++;
  int atual = h->qtde - 1;
  int pai_indice = pai(atual);

  while (atual > 0 && h->valores[atual] > h->valores[pai_indice]) {
    int tmp = h->valores[atual];
    h->valores[atual] = h->valores[pai_indice];
    h->valores[pai_indice] = tmp;
    atual = pai_indice;
    pai_indice = pai(atual);
  }
}

void remover(heap *h) {
  h->valores[0] = h->valores[h->qtde - 1];
  h->qtde--;
  peneirar(h, 0);
}

void mostrar(heap *h) {
  for (int i = 0; i < h->qtde; i++) {
    printf("%d ", h->valores[i]);
  }
  printf("\n");
}

int main(void) {
  heap *h = malloc(sizeof(heap));
  int valor;
  h->qtde = 0;
  for (int i = 0; i < LEN; i++) {
    scanf("%d", &valor);
    inserir(h, valor);
    mostrar(h);
  }
  for (int i = 0; i < LEN; i++) {
    remover(h);
    mostrar(h);
  }

  return 0;
}
