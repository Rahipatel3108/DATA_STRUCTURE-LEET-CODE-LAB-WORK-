#include <iostream>
#include <queue>
using namespace std;

int graph[20][20];
int visited[20];
int n;

// DFS
void DFS(int v)
{
    cout << v << " ";
    visited[v] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

// BFS
void BFS(int start)
{
    int visited[20] = {0};
    queue<int> q;

    visited[start] = 1;
    q.push(start);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        cout << v << " ";

        for (int i = 0; i < n; i++)
        {
            if (graph[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    int start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    // Reads both 0110 and 0 1 1 0 formats
    char x;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            graph[i][j] = x - '0';
        }
    }

    cout << "Enter starting vertex (0 to " << n - 1 << "): ";
    cin >> start;

    // DFS
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "\nDFS Traversal: ";
    DFS(start);

    // BFS
    cout << "\nBFS Traversal: ";
    BFS(start);

    return 0;
}