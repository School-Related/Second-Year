// Creating of a Network in a Graph
#include <iostream>
#include <stack>
#include <queue>
#include <list>

using namespace std;

class Graph
{

private:
    int nodes;
    list<int> *adjlist;

public:
    Graph()
    {
    }

    Graph(int nodes)
    { // Allocate resources
        adjlist = new list<int>[nodes];
        this->nodes = nodes;
    }

    ~Graph()
    { // Free allocated resources
        delete[] adjlist;
    }

    void AddEdge(int src, int dst)
    {
        adjlist[src].push_back(dst);
        adjlist[dst].push_back(src);
    }

    void Iterate(int src)
    {
        cout << src << " : ";
        for (auto &adj_node : adjlist[src])
        {
            cout << adj_node << " ";
        }
        cout << endl;
    }

    void DFS_recursive()
    {
        bool *visited = new bool[nodes];
        for (int i = 0; i < nodes; i++)
        {
            visited[i] = false;
        }
        for (int i = 0; i < nodes; i++)
        {
            if (visited[i] == false)
            {
                DFS_recursive(i, visited);
            }
        }
        cout << endl;
    }

    void DFS_recursive(int src, bool *visited)
    {
        visited[src] = true;
        cout << src << " ";
        for (auto &adj_node : adjlist[src])
        {
            if (visited[adj_node] == false)
            {
                DFS_recursive(adj_node, visited);
            }
        }
    }

    void breadth_first_traversal()
    {
        bool *visited = new bool[nodes];
        for (int i = 0; i < nodes; i++)
        {
            visited[i] = false;
        }
        for (int i = 0; i < nodes; i++)
        {
            if (visited[i] == false)
            {
                breadth_first_traversal(i, visited);
            }
        }
        cout << endl;
    }

    void breadth_first_traversal(int src, bool *visited)
    {
        queue<int> q;
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";
            for (auto &adj_node : adjlist[node])
            {
                if (visited[adj_node] == false)
                {
                    q.push(adj_node);
                    visited[adj_node] = true;
                }
            }
        }
    }

    void create_graph()
    {
        int src, dst;
        char ch;
        do
        {
            cout << "Enter the source and destination" << endl;
            cin >> src >> dst;
            if (src >= nodes || dst >= nodes || src < 0 || dst < 0)
            {
                cout << "Invalid edge" << endl;
                continue;
            }
            if (src == dst)
            {
                cout << "Invalid edge, self loops not allowed." << endl;
                continue;
            }
            AddEdge(src, dst);
            cout << "Do you want to continue" << endl;
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
    }
};

int main()
{
    Graph g(10);

    // g.AddEdge(0, 1);
    // g.AddEdge(0, 2);
    // g.AddEdge(1, 3);
    // g.AddEdge(1, 4);
    // g.AddEdge(2, 3);
    // g.AddEdge(3, 5);
    // g.AddEdge(4, 6);
    // g.AddEdge(5, 6);
    // g.AddEdge(5, 7);
    // g.AddEdge(6, 7);
    // g.AddEdge(6, 8);
    // g.AddEdge(7, 8);
    // g.AddEdge(7, 9);
    // g.AddEdge(8, 9);

    // cout << "Adjacency list implementation for graph" << endl;

    // g.Iterate(0);
    // g.Iterate(1);
    // g.Iterate(4);

    g.create_graph();

    cout << "Depth First Search Recursive" << endl;
    g.DFS_recursive();
    cout << "Breadth First Search" << endl;
    g.breadth_first_traversal();

    return 0;
}
