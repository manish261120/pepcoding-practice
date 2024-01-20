// LINK - https://www.pepcoding.com/resources/online-java-foundation/graphs/perfect-friends-official/ojquestion

// TC = O(V*E), SC = O(n)

#include <iostream>
#include <vector>
using namespace std;

class Edge
{
public:
    int src;
    int nbr;

    Edge(int src, int nbr)
    {
        this->src = src;
        this->nbr = nbr;
    }
};

void getCC(vector<Edge> graph[], int src, vector<bool> &visited, vector<int> &comp)
{
    visited[src] = true;
    comp.push_back(src);
    for (auto &&edge : graph[src])
    {
        if (!visited[edge.nbr])
        {
            getCC(graph, edge.nbr, visited, comp);
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<Edge> graph[n];
    vector<bool> visited(n, false);
    vector<vector<int>> comps;
    int pairs = 0;

    for (int i = 0; i < k; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(Edge(v1, v2));
        graph[v2].push_back(Edge(v2, v1));
    }

    for (int v = 0; v < n; v++)
    {
        if (!visited[v])
        {
            vector<int> comp;
            getCC(graph, v, visited, comp);
            comps.push_back(comp);
        }
    }

    for (int i = 0; i < comps.size() - 1; i++)
    {
        int s = comps[i].size();
        for (int j = i + 1; j < comps.size(); j++)
        {
            pairs += s * comps[j].size();
        }
    }

    cout << pairs;
    return 0;
}
