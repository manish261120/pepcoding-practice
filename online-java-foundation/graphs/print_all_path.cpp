// LINK - https://www.pepcoding.com/resources/online-java-foundation/graphs/print-all-paths-official/ojquestion

// TC = O(V+E), SC = O(V)
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Edge
{
public:
    int src;
    int nbr;
    int wt;

    Edge(int src, int nbr, int wt)
    {
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};

void printAllPaths(vector<Edge> graph[], int src, int dest, vector<bool> visited, string path)
{
    if (src == dest)
    {
        cout << path << endl;
        return;
    }
    visited[src] = true;
    for (auto &&edge : graph[src])
    {
        if (visited[edge.nbr] == false)
        {
            printAllPaths(graph, edge.nbr, dest, visited, path + to_string(edge.nbr));
        }
    }
    visited[src] = false;
}

int main()
{
    int vertices, edges, src, dest;
    cin >> vertices;
    vector<Edge> graph[vertices];
    vector<bool> visited(vertices, false);
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph[v1].push_back(Edge(v1, v2, wt));
        graph[v2].push_back(Edge(v2, v1, wt));
    }

    cin >> src >> dest;
    printAllPaths(graph, src, dest, visited, to_string(src));
    return 0;
}
