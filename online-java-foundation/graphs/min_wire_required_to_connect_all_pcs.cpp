// LINK - https://www.pepcoding.com/resources/online-java-foundation/graphs/minimum-wire-to-connect-all-pcs-official/ojquestion

// PRIMS ALGORITHM(MINIMUM SPANNING TREE)
// TC = O(V+E), SC = O(V)
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

class Pair
{
public:
    int src;
    int aqv;
    int wt;

    Pair(int src, int aqv, int wt)
    {
        this->src = src;
        this->aqv = aqv;
        this->wt = wt;
    }
};

class Compare
{
public:
    bool operator()(Pair p1, Pair p2)
    {
        return p1.wt > p2.wt;
    }
};

void minWireRequired(vector<Edge> graph[], int src, vector<bool> visited)
{
    priority_queue<Pair, vector<Pair>, Compare> pq;
    Pair p = Pair(src, -1, 0);
    pq.push(p);

    while (!pq.empty())
    {
        Pair pair = pq.top();
        pq.pop();
        if (visited[pair.src])
        {
            continue;
        }

        visited[pair.src] = true;
        if (pair.aqv != -1)
        {
            cout << "[" << pair.src << "-" << pair.aqv << "@" << pair.wt << "]" << endl;
        }

        for (auto &&edge : graph[pair.src])
        {
            if (!visited[edge.nbr])
            {
                pq.push(Pair(edge.nbr, pair.src, edge.wt));
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
    minWireRequired(graph, src, visited);
    return 0;
}
