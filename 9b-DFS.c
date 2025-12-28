#include <stdio.h>
#define MAX 20
int visited[MAX];
// DFS function
void DFS(int adj[MAX][MAX], int n, int start)
{
    visited[start] = 1;
    for (int j = 0; j < n; j++)
    {
        if (adj[start][j] == 1 && !visited[j])
        {
            DFS(adj, n, j);
        }
    }
}
int main()
{
    int n;
    int adj[MAX][MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    // Initialize visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    // Perform DFS starting from vertex 0
    DFS(adj, n, 0);
    // Check if all vertices are visited
    int connected = 1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            connected = 0;
            break;
        }
    }
    if (connected)
        printf("The graph is connected.\n");
    else
        printf("The graph is NOT connected.\n");
    return 0;
}