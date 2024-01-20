// LINK - https://www.pepcoding.com/resources/online-java-foundation/graphs/hamiltonian-official/ojquestion

// TC = O(V*E), SC = O(V)
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
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

void printAllPaths(vector<Edge> graph[], int src, unordered_set<int> visited, string path, int size, int osrc)
{
    if (visited.size() == size - 1)
    {
        bool iscycle = false;
        for (auto &&edge : graph[src])
        {
            if (edge.nbr == osrc)
            {
                iscycle = true;
                break;
            }
        }
        iscycle ? cout << path + "*\n" : cout << path + ".\n";
        return;
    }
    visited.insert(src);
    for (auto &&edge : graph[src])
    {
        if (visited.find(edge.nbr) == visited.end())
        {
            printAllPaths(graph, edge.nbr, visited, path + to_string(edge.nbr), size, osrc);
        }
    }
    visited.erase(src);
}

int main()
{
    int vertices, edges, src;
    cin >> vertices >> edges;
    vector<Edge> graph[vertices];
    unordered_set<int> visited;

    for (int i = 0; i < edges; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph[v1].push_back(Edge(v1, v2, wt));
        graph[v2].push_back(Edge(v2, v1, wt));
    }

    cin >> src;
    printAllPaths(graph, src, visited, to_string(src), vertices, src);
    return 0;
}
