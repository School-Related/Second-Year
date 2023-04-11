// Graph class with constructor
class Graph {
    int V; // Number of vertices in the graph
    int** adj; // Adjacency matrix to store the graph

public:
    // Constructor to initialize the graph
    Graph(int V) {
        this->V = V; // Set the number of vertices in the graph
        adj = new int*[V]; // Create a 2D array for adjacency matrix with V rows
        for (int i = 0; i < V; i++) {
            adj[i] = new int[V]; // Create V columns for each row
            memset(adj[i], 0, sizeof(int) * V); // Initialize all entries in the matrix to 0
        }
    }

    // Function to add an edge between two vertices with weight w
    void addEdge(int u, int v, int w) {
        adj[u][v] = w; // Set the weight of edge (u, v)
        adj[v][u] = w; // Set the weight of edge (v, u) (since it's an undirected graph)
    }

    // Function to accept the graph as input from the user
    void acceptGraph() {
        int E; // Number of edges in the graph
        cout << "Enter the number of edges: ";
        cin >> E; // Take input from user for the number of edges

        // Loop through all the edges and add them to the graph using the addEdge function
        for (int i = 0; i < E; i++) {
            int u, v, w; // Variables to store the vertices and weight of the edge
            cout << "Enter the edge (u, v, w): ";
            cin >> u >> v >> w; // Take input from user for the edge
            addEdge(u, v, w); // Add the edge to the graph
        }
    }
};
