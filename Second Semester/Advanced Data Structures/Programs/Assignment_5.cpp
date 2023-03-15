// Creating of a Network in a Graph
#include <iostream>
#include <stack>

using namespace std;

class GraphNode
{
    int vertex;
    GraphNode *next;
    friend class Graph;
};

class Graph
{
private:
    GraphNode *head[20];
    int no_of_vtex;
    char choice;

public:
    Graph()
    {
        for (int i = 0; i < no_of_vtex; i++)
        {
            head[i] = new GraphNode;
            head[i]->vertex = i;
        }
    }
    void create_graph()
    {
        int current_vertex;
        int choice;
        GraphNode *temp;
        for (int i = 0; i < no_of_vtex; i++)
        {
            temp = head[i];
            do
            {
                cin >> current_vertex;
                if (current_vertex == i)
                {
                    cout << "Self Loops are not allowed" << endl;
                }
                else
                {
                    GraphNode *current = new GraphNode;
                    current->vertex = current_vertex;
                    temp->next = current;
                    temp = temp->next;
                }
                cin >> choice;
            } while (choice == 'y' || choice == 'Y');
        }
    }

    void depth_first_search(int vertex)
    {
        int visited[20];
        for (int i = 0; i < no_of_vtex; i++)
        {
            visited[i] = 0;
        }
        cout << "What is the starting vertex" << endl;
        cin >> vertex;
        dfs(vertex, visited);
    }

    void dfs(int vertex, int visited[])
    {
        GraphNode *temp;
        temp = head[vertex];
        visited[vertex] = 1;
        cout << vertex << " " << endl;
        for (int i = 0; i < no_of_vtex; i++)
        {
            if (visited[temp->vertex] == 0)
            {
                dfs(temp->vertex, visited);
            }
            temp = temp->next;
        }
    }

    void DFS_non_recursive(int vertex)
    {
        int visited[20];
        stack<int> s;
        for (int i = 0; i < no_of_vtex; i++)
        {
            visited[i] = 0;
        }
        s.push(vertex);
        visited[vertex] = 1;
        do
        {
            vertex = s.top();
            s.pop();
            cout << vertex << " ";
            for (int w = 0; w < no_of_vtex; w++)
            {
                if (!visited[w])
                {
                    s.push(w);
                    visited[w] = 1;
                }
            }
        } while (!s.empty());
    }
};

int main()
{
    Graph g;
    g.create_graph();
    g.depth_first_search(0);
    g.DFS_non_recursive(0);
    return 0;
}
