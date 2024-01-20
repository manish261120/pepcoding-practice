// LINK - https://www.pepcoding.com/resources/online-java-foundation/graphs/is-cyclic-official/ojquestion

// TC = O(V), SC = O(V)
#include <iostream>
#include <vector>
#include <queue>
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

bool isCyclic(vector<Edge> graph[], int src, vector<bool> &visited)
{
    queue<pair<int, string>> q;
    q.push({src, to_string(src)});

    while (!q.empty())
    {
        pair<int, string> pair = q.front();
        q.pop();
        if (visited[pair.first])
        {
            return true;
        }

        visited[pair.first] = true;
        for (auto &&edge : graph[pair.first])
        {
            if (!visited[edge.nbr])
            {
                q.push({edge.nbr, pair.second + to_string(edge.nbr)});
            }
        }
    }
    return false;
}

int main()
{
    int vertices, edges, src;
    cin >> vertices >> edges;
    vector<Edge> graph[vertices];
    vector<bool> visited(vertices, false);

    for (int i = 0; i < edges; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph[v1].push_back(Edge(v1, v2, wt));
        graph[v2].push_back(Edge(v2, v1, wt));
    }
    cin >> src;
    bool iscycle;

    for (int v = 0; v < vertices; v++)
    {
        if (!visited[v])
        {
            if (isCyclic(graph, src, visited))
            {
                iscycle = true;
                break;
            }
        }
    }
    iscycle ? cout << "true\n" : cout << "false\n";
    return 0;
}
