#include <stdio.h>
int a[20][20], g[20] = {0}, visited[20] = {0}, f = 0, r = -1;
void bfs(int v, int m)
{
    int i;
    for (i = 0; i < m; i++)
        if (a[v][i] == 1 && !visited[i])
            g[++r] = 1;
    if (f <= r)
    {
        visited[g[f]] = 1;
        bfs(g[f++], m);
    }
}
int display(int m)
{
    int i;
    printf("\nBFS sequence: \n");
    for (i = 0; i < m; i++)
        if (visited[i])
            printf("%d ", i);
        else
            printf(" Unreachable ");
}
int main()
{
    int n, i, j;
    printf("Enter no. of vertices: ");
    scanf("%d", &n);
    printf("\nEnter adjacency matrix of graph: \n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    bfs(0, n);
    display(n);
    return 0;
}