// Creating of a Network in a Graph
#include <iostream>
#include <stack>

using namespace std;

// Class to store the vertex and its adjacent nodes
class GraphNode
{
    int vertex; // Stores the vertex
    GraphNode *next; // Pointer to the next node
    friend class Graph; // Making Graph class as a friend of GraphNode
};

// Graph class to create a graph and perform traversal operations
class Graph
{
private:
    GraphNode *head[20]; // Array of pointers to store the head of each linked list
    int no_of_vtex; // Stores the number of vertices

public:
    // Constructor to initialize the number of vertices
    Graph(int no_of_vtex = 0)
    {
        this->no_of_vtex = no_of_vtex;
        for (int i = 0; i < no_of_vtex; i++)
        {
            head[i] = new GraphNode(); // Allocating memory for each head node
            head[i]->vertex = i; // Assigning the vertex value to the head node
        }
    }
    
    // Function to create the graph
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
                    GraphNode *current = new GraphNode(); // Allocating memory for the current node
                    current->vertex = current_vertex; // Assigning the vertex value to the current node
                    temp->next = current; // Linking the current node to the previous node
                    temp = temp->next; // Moving the pointer to the current node
                }
                cout << "Do you want to add more edges" << endl;
                cin >> choice;
            } while (choice == 'y' || choice == 'Y');
        }
    }

    // Function to perform Depth First Search using recursion
    void DFS_recursive()
    {
        int vertex;
        int visited[20];
        for (int i = 0; i < no_of_vtex; i++)
        {
            visited[i] = 0; // Initializing all the vertices as unvisited
        }
        cout << "What is the starting vertex" << endl;
        cin >> vertex;
        DFS_recursive_worker(vertex, visited); // Calling the recursive worker function
    }

    // Recursive worker function to traverse the graph
    void DFS_recursive_worker(int vertex, int visited[])
    {
        GraphNode *temp;
        temp = head[vertex];
        visited[vertex] = 1; // Marking the vertex as visited
        cout << vertex << " " << endl;
        for (int i = 0; i < no_of_vtex; i++)
        {
            if (visited[temp->vertex] == 0)
            {
                DFS_recursive_worker(temp->vertex, visited); // Recursively calling the worker function
            }
            temp = temp->next;
        }
    }

    // Function to perform Depth First Search without recursion
    void DFS_non_recursive(int vertex)
    {
        int visited[20];
        stack<int> s;
        for (int i = 0; i < no_of_vtex; i++)
            visited[i] = 0;
        s.push(vertex); // Pushing the starting vertex into the stack
        visited[vertex] = 1;
        do
        {
            vertex = s.top(); // Taking out the top element from the stack
            s.pop();
            cout << vertex << " ";
            for (int w = 0; w < no_of_vtex; w++)
            {
                if (!visited[w])
                {
                    s.push(w); // Pushing the unvisited vertex into the stack
                    visited[w] = 1;
                }
            }
        } while (!s.empty());
    }

    // Function to perform Breadth First Search
    void breadth_first_traversal()
    {
        int visited[20];
        int starting_vertex;
        for (int i = 0; i < no_of_vtex; i++)
        {
            visited[i] = 0; // Initializing all the vertices as unvisited
        }
        cout << "What is the starting vertex" << endl;
        cin >> starting_vertex;
        breadth_first_traversal(starting_vertex, visited); // Calling the BFS function
    }

    // Worker function to traverse the graph
    void breadth_first_traversal(int vertex, int visited[])
    {
        GraphNode *temp;
        temp = head[vertex];
        visited[vertex] = 1; // Marking the vertex as visited
        cout << vertex << " " << endl;
        for (int i = 0; i < no_of_vtex; i++)
        {
            if (visited[temp->vertex] == 0)
            {
                DFS_recursive_worker(temp->vertex, visited); // Calling the recursive worker function
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