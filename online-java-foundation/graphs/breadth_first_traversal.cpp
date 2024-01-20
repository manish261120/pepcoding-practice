// LINK - https://www.pepcoding.com/resources/online-java-foundation/graphs/bfs-graph-official/ojquestion

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

void bft(vector<Edge> graph[], int src, vector<bool> visited)
{
    queue<pair<int, string>> q;
    q.push({src, to_string(src)});

    while (!q.empty())
    {
        pair<int, string> pair = q.front();
        q.pop();
        if (visited[pair.first])
        {
            continue;
        }

        visited[pair.first] = true;
        cout << pair.first << "@" << pair.second << endl;
        for (auto &&edge : graph[pair.first])
        {
            if (!visited[edge.nbr])
            {
                q.push({edge.nbr, pair.second + to_string(edge.nbr)});
            }
        }
    }
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
    bft(graph, src, visited);
    return 0;
}
