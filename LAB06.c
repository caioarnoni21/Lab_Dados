#include <stdio.h>
#include <stdlib.h>

#define LEN 100

typedef struct {
  char data[LEN];
  int head;
  int tail;
  int qtde;
} Queue;

int is_full(Queue *queue) { return queue->qtde == LEN; }

int is_empty(Queue *queue) { return queue->qtde == 0; }

int enqueue(Queue *queue, char caracter) {
  if (!is_full(queue)) {
    queue->data[queue->tail % LEN] = caracter;
    queue->tail++;
    queue->qtde++;
    return 1;
  }

  return 0;
}

char dequeue(Queue *queue) {
  if (!is_empty(queue)) {
    int value = queue->data[queue->head % LEN];
    queue->head++;
    queue->qtde--;
    return value;
  }

  return -1;
}

void show(Queue *queue) {
  for (int i = queue->head; i < queue->tail; i++) {
    printf("%c ", queue->data[i % LEN]);
  }
}

Queue *create_queue() {
  Queue *queue = malloc(sizeof(Queue));
  queue->head = 0;
  queue->tail = 0;
  queue->qtde = 0;

  return queue;
}

int main(void) {
  Queue *queue = create_queue();
  Queue *parenteses = create_queue();

  char s[LEN];

  fgets(s, sizeof(s), stdin);

  int certo = 1;

  for (int i = 0; s[i] != '\0'; i++) {

    enqueue(queue, s[i]);
  }

  for (int i = 0; s[i] != '\0'; i++) {
    dequeue(queue);

    if (s[i] == '(') {
      enqueue(parenteses, s[i]);
    } else if (s[i] == ')') {
      int res = dequeue(parenteses);
      certo = res != -1;
    }
    if (certo) {
      show(queue);
    }
  }

  if (certo && !parenteses->qtde) {
    printf("correto");
  } else {
    printf("incorreto");
  }

  return 0;
}
