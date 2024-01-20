// LINK - https://www.pepcoding.com/resources/online-java-foundation/graphs/gcc-official/ojquestion

// TC = O(V*E), SC = O(V)

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

void display(vector<vector<int>> comps)
{
    cout << "[";
    int n = comps.size();
    for (int i = 0; i < n; i++)
    {

        int m = comps[i].size();
        cout << "[";
        for (int j = 0; j < m; j++)
        {
            cout << comps[i][j];
            j != m - 1 ? cout << ", " : cout << "";
        }
        i != n - 1 ? cout << "], " : cout << "]";
    }
    cout << "]";
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    vector<Edge> graph[vertices];
    vector<bool> visited(vertices, false);
    vector<vector<int>> comps;

    for (int i = 0; i < edges; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph[v1].push_back(Edge(v1, v2, wt));
        graph[v2].push_back(Edge(v2, v1, wt));
    }

    for (int v = 0; v < vertices; v++)
    {
        if (!visited[v])
        {
            vector<int> comp;
            getCC(graph, v, visited, comp);
            comps.push_back(comp);
        }
    }
    display(comps);
    return 0;
}
