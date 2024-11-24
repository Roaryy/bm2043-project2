#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    map<int, list<int>> adjList; // Adjacency list representation

public:
    // Add a node to the graph
    void addNode(int node){
        if (adjList.find(node) == adjList.end()){
            adjList[node] = list<int>();
            cout << "Node " << node << " added.\n";
        } 
        else{
            cout << "Node " << node << " already exists.\n";
        }
    }

    // Remove a node and its associated edges from the graph
    void removeNode(int node){
        if (adjList.find(node) != adjList.end()){
            // Remove edges connected to this node
            for (auto& pair : adjList){
                pair.second.remove(node);
            }
            adjList.erase(node);
            cout << "Node " << node << " removed.\n";
        } 
        else{
            cout << "Node " << node << " does not exist.\n";
        }
    }

    // Add an edge between two nodes
    void addEdge(int node1, int node2){
        if (adjList.find(node1) != adjList.end() && adjList.find(node2) != adjList.end()){
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
            cout << "Edge between " << node1 << " and " << node2 << " added.\n";
        } 
        else{
            cout << "One or both nodes do not exist.\n";
        }
    }

    // Remove an edge between two nodes
    void removeEdge(int node1, int node2){
        if (adjList.find(node1) != adjList.end() && adjList.find(node2) != adjList.end()){
            adjList[node1].remove(node2);
            adjList[node2].remove(node1);
            cout << "Edge between " << node1 << " and " << node2 << " removed.\n";
        } 
        else{
            cout << "One or both nodes do not exist.\n";
        }
    }

    // Display the adjacency list of the graph
    void displayGraph(){
        cout << "\nGraph adjacency list:\n";
        for (const auto& pair : adjList){
            cout << pair.first << ": ";
            for (const int& neighbor : pair.second){
                cout << neighbor << " ";
            }
            cout << "\n";
        }
    }

    // Display properties of the graph
    void displayGraphProperties(){
        int numNodes = adjList.size();
        int numEdges = 0;
        for (const auto& pair : adjList){
            numEdges += pair.second.size();
        }
        numEdges /= 2; // Each edge is counted twice in an undirected graph

        cout << "\nGraph properties:\n";
        cout << "Number of nodes: " << numNodes << "\n";
        cout << "Number of edges: " << numEdges << "\n";
        cout << "Degrees of nodes:\n";
        for (const auto& pair : adjList){
            cout << "Node " << pair.first << ": Degree " << pair.second.size() << "\n";
        }
    }
};

int main(){
    Graph g;
    int choice;

    cout << "Welcome to the Interactive Graph Editor!\n";

    while (true){
        cout << "\nMenu:\n";
        cout << "1. Add node\n";
        cout << "2. Remove node\n";
        cout << "3. Add edge\n";
        cout << "4. Remove edge\n";
        cout << "5. Display graph\n";
        cout << "6. Display graph properties\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int node1, node2;
        switch (choice){
            case 1:
                cout << "Enter node to add: ";
                cin >> node1;
                g.addNode(node1);
                break;
            case 2:
                cout << "Enter node to remove: ";
                cin >> node1;
                g.removeNode(node1);
                break;
            case 3:
                cout << "Enter two nodes to connect with an edge (node1 node2): ";
                cin >> node1 >> node2;
                g.addEdge(node1, node2);
                break;
            case 4:
                cout << "Enter two nodes to disconnect (node1 node2): ";
                cin >> node1 >> node2;
                g.removeEdge(node1, node2);
                break;
            case 5:
                g.displayGraph();
                break;
            case 6:
                g.displayGraphProperties();
                break;
            case 7:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
