#include <iostream>
using namespace std;

class Graph
{
    int adj[20][20];
    int n;
    bool visited[20] = {false};

public:

    void createGraph()
    {
        cout << "Enter number of vertices: ";
        cin >> n;

        // Initialize adjacency matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = 0;
            }
        }

        int edges;
        cout << "Enter number of edges: ";
        cin >> edges;

        cout << "Enter edges (source destination):\n";

        for (int i = 0; i < edges; i++)
        {
            int u, v;
            cin >> u >> v;

            adj[u][v] = 1;
            adj[v][u] = 1;   // For undirected graph
        }
    }

    void displayMatrix()
    {
        cout << "\nAdjacency Matrix:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    // DFS Traversal
    void DFS(int start)
    {
        visited[start] = true;

        cout << start << " ";

        for (int i = 0; i < n; i++)
        {
            if (adj[start][i] == 1 && !visited[i])
            {
                DFS(i);
            }
        }
    }

    // BFS Traversal
    void BFS(int start)
    {
        bool visited[20] = {false};
        int queue[20];
        int front = 0, rear = 0;

        queue[rear] = start;
        rear++;
        visited[start] = true;

        while (front < rear)
        {
            int current = queue[front];
            front++;

            cout << current << " ";

            for (int i = 0; i < n; i++)
            {
                if (adj[current][i] == 1 && !visited[i])
                {
                    queue[rear] = i;
                    rear++;

                    visited[i] = true;
                }
            }
        }
    }
};

int main()
{
    Graph g;

    int choice, start;

    do
    {
        cout << "\n===== Graph Menu =====";
        cout << "\n1. Create a Graph";
        cout << "\n2. Display Graph (Adjacency Matrix)";
        cout << "\n3. DFS Traversal";
        cout << "\n4. BFS Traversal";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            g.createGraph();
            break;

        case 2:
            g.displayMatrix();
            break;

        case 3:
            cout << "\nEnter starting vertex: ";
            cin >> start;

            cout << "DFS Traversal: ";
            g.DFS(start);
            cout << endl;
            break;

        case 4:
            cout << "\nEnter starting vertex: ";
            cin >> start;

            cout << "BFS Traversal: ";
            g.BFS(start);
            cout << endl;
            break;

        case 5:
            cout << "Program Exited.";
            break;

        default:
            cout << "Invalid Choice!";
        }

    } while (choice != 5);

    return 0;
}