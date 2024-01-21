// LINK - https://www.pepcoding.com/resources/online-java-foundation/graphs/is-bipartite-official/ojquestion

// TC = O(V+E), SC = O(V)
#include <iostream>
#include <vector>
#include <queue>
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

bool isCompBipartite(vector<Edge> graph[], int src, vector<int> &visited)
{
    queue<pair<int, int>> q;
    q.push({src, 0});

    while (!q.empty())
    {
        pair<int, int> pair = q.front();
        q.pop();
        if (visited[pair.first] != -1)
        {
            if (visited[pair.first] != pair.second)
            {
                return false;
            }
        }
        visited[pair.first] = pair.second;

        for (auto &&edge : graph[pair.first])
        {
            if (visited[edge.nbr] == -1)
            {
                q.push({edge.nbr, pair.second + 1});
            }
        }
    }
    return true;
}

int main()
{
    int vertices, edges, src;
    cin >> vertices >> edges;
    vector<Edge> graph[vertices];
    vector<int> visited(vertices, -1);

    for (int i = 0; i < edges; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph[v1].push_back(Edge(v1, v2, wt));
        graph[v2].push_back(Edge(v2, v1, wt));
    }
    cin >> src;
    bool isbipartite = true;

    for (int v = 0; v < vertices; v++)
    {
        if (visited[v] == -1)
        {
            cout << "src " << v << endl;
            if (!isCompBipartite(graph, v, visited))
            {

                isbipartite = false;
                break;
            }
        }
    }
    isbipartite ? cout << "true\n" : cout << "false\n";
    return 0;
}
