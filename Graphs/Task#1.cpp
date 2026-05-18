#include <iostream>
#include <iomanip>
using namespace std;

struct edge {
    int adj;
    int weight;
};

class WeightedGraph {
private:
    edge** matrix;
    int n;

public:
    WeightedGraph(int n);
    ~WeightedGraph();
    void addEdge(int from, int to, int weight);
    void removeEdge(int from, int to);
    bool isAdjacent(int from, int to);
    int getWeight(int from, int to);
    void display();
};

WeightedGraph::WeightedGraph(int n) {
    this->n = n;
    matrix = new edge*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new edge[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j].adj = 0;
            matrix[i][j].weight = 0;
        }
    }
    cout << "Graph created with " << n << " vertices." << endl;
}

WeightedGraph::~WeightedGraph() {
    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
}

void WeightedGraph::addEdge(int from, int to, int weight) {
    matrix[from][to].adj = 1;
    matrix[from][to].weight = weight;
}

void WeightedGraph::removeEdge(int from, int to) {
    matrix[from][to].adj = 0;
    matrix[from][to].weight = 0;
}

bool WeightedGraph::isAdjacent(int from, int to) {
    return matrix[from][to].adj == 1;
}

int WeightedGraph::getWeight(int from, int to) {
    if (isAdjacent(from, to))
        return matrix[from][to].weight;
    return -1;
}

void WeightedGraph::display() {
    cout << "  ";
    for (int j = 0; j < n; j++)
        cout << setw(2) << j;
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << i;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j].adj)
                cout << setw(2) << matrix[i][j].weight;
            else
                cout << setw(2) << 0;
        }
        cout << endl;
    }
}

int main() {
    WeightedGraph g(4);

    cout << "\nAdding weighted edges:" << endl;
    g.addEdge(0, 1, 5); cout << "0->1 (weight 5)" << endl;
    g.addEdge(0, 2, 3); cout << "0->2 (weight 3)" << endl;
    g.addEdge(1, 2, 2); cout << "1->2 (weight 2)" << endl;
    g.addEdge(1, 3, 4); cout << "1->3 (weight 4)" << endl;
    g.addEdge(2, 3, 1); cout << "2->3 (weight 1)" << endl;

    cout << "\nAdjacency Matrix (with weights):" << endl;
    g.display();

    cout << "\nChecking adjacency:" << endl;
    cout << "0->1: " << (g.isAdjacent(0,1) ? string("Yes, weight = ") + to_string(g.getWeight(0,1)) : "No") << endl;
    cout << "1->0: " << (g.isAdjacent(1,0) ? string("Yes, weight = ") + to_string(g.getWeight(1,0)) : "No") << endl;
    cout << "2->3: " << (g.isAdjacent(2,3) ? string("Yes, weight = ") + to_string(g.getWeight(2,3)) : "No") << endl;

    cout << "\nRemoving edge 1->2" << endl;
    g.removeEdge(1, 2);
    cout << "After removal:" << endl;
    g.display();

    return 0;
}