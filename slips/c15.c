#include <stdio.h>


void dfs(int graph[5][5], int visited[5], int v) {
    printf("v%d ", v + 1); // Print the visited node
    visited[v] = 1; // Mark node as visited

    for (int w = 0; w < 5; w++) {
        if (graph[v][w] == 1 && !visited[w]) {
            dfs(graph, visited, w); // Recursive DFS call
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

    int visited[5] = {0}; // Keeps track of visited nodes

    printf("DFS Traversal: ");
    dfs(graph, visited, 0); // Start DFS from node 0 (v1)

    return 0;
}
