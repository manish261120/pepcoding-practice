// LINK - https://www.pepcoding.com/resources/online-java-foundation/graphs/compilation-order-official/ojquestion

// TOPOLOGICAL SORT
// TC = O(V*E), SC = O(V)

#include <iostream>
#include <vector>
#include <stack>
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

stack<int> st;

void topologicalSort(vector<Edge> graph[], int src, vector<bool> &visited)
{
    visited[src] = true;
    for (auto &&edge : graph[src])
    {
        if (!visited[edge.nbr])
        {
            topologicalSort(graph, edge.nbr, visited);
        }
    }
    st.push(src);
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    vector<Edge> graph[vertices];
    vector<bool> visited(vertices, false);

    for (int i = 0; i < edges; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(Edge(v1, v2));
    }

    for (int v = 0; v < vertices; v++)
    {
        if (!visited[v])
        {
            topologicalSort(graph, v, visited);
        }
    }
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}
