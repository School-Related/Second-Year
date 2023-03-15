// Creating of a Network in a Graph
#include <iostream>

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
                    current->vertex = v;
                    temp->next = current;
                    temp = temp->next;
                }
                cin >> choice;
            } while (choice == 'y' || choice == 'Y');
        }
    }
};
int main()
{
    return 0;
}
