// C program to implement BFS Traversal on a graph

#include <stdio.h>
#define MAXSIZE 20

// Queue structure for BFS
typedef struct {
    int data[MAXSIZE];
    int front, rear;
} QUEUE;

// Queue functions
void initq(QUEUE *q) {
    q->front = q->rear = -1;
}

void addq(QUEUE *q, int value) {
    q->data[++q->rear] = value;
}

int removeq(QUEUE *q) {
    return q->data[++q->front];
}

int isempty(QUEUE *q) {
    return q->front == q->rear;
}

// BFS function
void bfs(int graph[5][5], int nodes) {
    int visited[5] = {0}; // Keeps track of visited nodes
    QUEUE q;
    initq(&q);

    printf("BFS Traversal: ");

    int start = 0; // Start from node 0
    visited[start] = 1;
    addq(&q, start);

    while (!isempty(&q)) {
        int v = removeq(&q);
        printf("v%d ", v + 1);

        for (int w = 0; w < nodes; w++) {
            if (graph[v][w] == 1 && !visited[w]) {
                addq(&q, w);
                visited[w] = 1;
            }
        }
    }
}

int main() {
    int graph[5][5] = {
        {0, 0, 1, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };

    bfs(graph, 5);
    return 0;
}
