// LINK - https://www.pepcoding.com/resources/online-java-foundation/graphs/iterative-dft-official/ojquestion

// TC = O(V+E), SC = O(V)
#include <iostream>
#include <vector>
#include <stack>
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

void dft(vector<Edge> graph[], int src, vector<bool> visited)
{
    stack<pair<int, string>> st;
    st.push({src, to_string(src)});

    while (!st.empty())
    {
        pair<int, string> pair = st.top();
        st.pop();
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
                st.push({edge.nbr, pair.second + to_string(edge.nbr)});
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
    dft(graph, src, visited);
    return 0;
}
