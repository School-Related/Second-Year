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

public:
    Graph(int no_of_vtex = 0)
    {
        this->no_of_vtex = no_of_vtex;
        for (int i = 0; i < no_of_vtex; i++)
        {
            head[i] = new GraphNode();
            head[i]->vertex = i;
        }
    }
    void create_graph()
    {
        int current_vertex;
        char choice;
        GraphNode *temp;
        for (int i = 0; i < no_of_vtex; i++)
        {
            temp = head[i];
            do
            {
                cout << "Enter the vertex to which " << i << " is connected" << endl;
                cin >> current_vertex;
                if (current_vertex == i)
                {
                    cout << "Self Loops are not allowed" << endl;
                }
                else
                {
                    GraphNode *current = new GraphNode();
                    current->vertex = current_vertex;
                    temp->next = current;
                    temp = temp->next;
                }
                cout << "Do you want to add more edges" << endl;
                cin >> choice;
            } while (choice == 'y' || choice == 'Y');
        }
    }

    void DFS_recursive()
    {
        int vertex;
        int visited[20];
        for (int i = 0; i < no_of_vtex; i++)
        {
            visited[i] = 0;
        }
        cout << "What is the starting vertex" << endl;
        cin >> vertex;
        DFS_recursive_worker(vertex, visited);
    }

    void DFS_recursive_worker(int vertex, int visited[])
    {
        GraphNode *temp;
        temp = head[vertex];
        visited[vertex] = 1;
        cout << vertex << " " << endl;
        for (int i = 0; i < no_of_vtex; i++)
        {
            if (visited[temp->vertex] == 0)
            {
                DFS_recursive_worker(temp->vertex, visited);
            }
            temp = temp->next;
        }
    }

    void DFS_non_recursive(int vertex)
    {
        int visited[20];
        stack<int> s;
        for (int i = 0; i < no_of_vtex; i++)
            visited[i] = 0;
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

    void breadth_first_traversal()
    {
        int visited[20];
        int starting_vertex;
        for (int i = 0; i < no_of_vtex; i++)
        {
            visited[i] = 0;
        }
        cout << "What is the starting vertex" << endl;
        cin >> starting_vertex;
        breadth_first_traversal(starting_vertex, visited);
    }

    void breadth_first_traversal(int vertex, int visited[])
    {
        GraphNode *temp;
        temp = head[vertex];
        visited[vertex] = 1;
        cout << vertex << " " << endl;
        for (int i = 0; i < no_of_vtex; i++)
        {
            if (visited[temp->vertex] == 0)
            {
                DFS_recursive_worker(temp->vertex, visited);
            }
            temp = temp->next;
        }
    }
};

int main()
{
    int no_of_vtex, starting_vertex;
    cout << "Enter the number of vertices" << endl;
    cin >> no_of_vtex;
    Graph g(no_of_vtex);
    g.create_graph();
    cout << "Depth First Search Recursive" << endl;
    g.DFS_recursive();
    cout << "Depth First Search Non Recursive" << endl;
    cout << "What is the starting vertex" << endl;
    cin >> starting_vertex;
    g.DFS_non_recursive(starting_vertex);
    cout << "Breadth First Search" << endl;
    g.breadth_first_traversal();
    return 0;
}
