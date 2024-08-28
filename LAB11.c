#include <stdio.h>

#define V 8
#define E 20
#define INF 9999

int get_index(char x) {
    return x - 'r'; // 'r' é o primeiro vértice na lista de vértices
}

void inicia_arestas(int arestas[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            arestas[i][j] = 0;
        }
    }
}

void cria_arestas(int arestas[V][V], int v, int u) {
    arestas[v][u] = 1;
}

void mostra_arestas(int arestas[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", arestas[i][j]);
        }
        printf("\n");
    }
}

void mostra_adjacentes(int arestas[V][V], char v) {
    int index = get_index(v);
    for (int i = 0; i < V; i++) {
        if (arestas[index][i] == 1) {
            printf("%c -> %c\n", v, 'r' + i);
        }
    }
}


void mostra_distancias(int arestas[V][V], char v) {
    int index = get_index(v);
    int distancias[V];

    // Inicializa todas as distâncias como infinito
    for (int i = 0; i < V; i++) {
        distancias[i] = INF;
    }

    // A distância de um vértice para ele mesmo é 0
    distancias[index] = 0;

    // Atualiza as distâncias para todos os vértices
    for (int count = 0; count < V - 1; count++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (arestas[i][j] == 1 && distancias[i] + 1 < distancias[j]) {
                    distancias[j] = distancias[i] + 1;
                }
            }
        }
    }

    // Mostra as distâncias
    for (int i = 0; i < V; i++) {
        printf("%d ", distancias[i]);
    }
    printf("\n");
}

int main(void) {
    char lista_de_vertices[V] = {'r', 's', 't', 'u', 'v', 'w', 'x', 'y'};
    char lista_de_arestas[E][2] = {"vr", "rv", "rs", "sr", "sw", "ws", "wt", "tw", "wx", "xw", "tx", "xt", "tu", "ut", "xu", "ux", "xy", "yx", "uy", "yu"};
    int arestas[V][V];
    inicia_arestas(arestas);
    printf("Matriz de adjacências\n");
    for (int i = 0; i < E; i++) {
        cria_arestas(arestas, get_index(lista_de_arestas[i][0]), get_index(lista_de_arestas[i][1]));
    }
    mostra_arestas(arestas);
    printf("Lista de adjacências\n");
    for (int i = 0; i < V; i++) {
        mostra_adjacentes(arestas, lista_de_vertices[i]);
    }
    printf("Matriz de distâncias\n");
    for (int i = 0; i < V; i++) {
        mostra_distancias(arestas, lista_de_vertices[i]);
    }
    return 0;
}

