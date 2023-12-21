// LINK - https://www.pepcoding.com/resources/online-java-foundation/graphs/has-path-official/ojquestion

// TC = O(V+E), SC = O(V)
#include <iostream>
#include <vector>
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

bool hasPath(vector<Edge> graph[], int src, int dest, vector<bool> visited)
{
    if (src == dest)
    {
        return true;
    }
    visited[src] = true;
    for (auto &&edge : graph[src])
    {
        if (!visited[edge.nbr])
        {
            bool hasNbrPath = hasPath(graph, edge.nbr, dest, visited);
            if (hasNbrPath)
            {
                return true;
            }
        }
    }

    return false;
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
    bool res = hasPath(graph, src, dest, visited);
    res ? cout << "true" : cout << "false";
    return 0;
}
