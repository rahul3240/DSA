#include <stdio.h>
#define MAX 20
int queue[MAX], front = -1, rear = -1;
int visited[MAX];
// Enqueue
void enqueue(int v)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}
// Dequeue
int dequeue()
{
    if (front == -1 || front > rear)
    {
        return -1;
    }
    return queue[front++];
}
// BFS function
void BFS(int adj[MAX][MAX], int n, int start)
{
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    enqueue(start);
    visited[start] = 1;
    printf("BFS Traversal starting from node %d: ", start);
    while (front != -1 && front <= rear)
    {
        int node = dequeue();
        printf("%d ", node);
        for (int j = 0; j < n; j++)
        {
            if (adj[node][j] == 1 && !visited[j])
            {
                enqueue(j);
                visited[j] = 1;
            }
        }
    }
    printf("\n");
}
int main()
{
    int n, start;
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
    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);
    BFS(adj, n, start);
    return 0;
}