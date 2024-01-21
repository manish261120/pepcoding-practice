// LINK - https://www.pepcoding.com/resources/online-java-foundation/graphs/infection-spread-official/ojquestion

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

int infectedPersons(vector<Edge> graph[], int src, int t, vector<int> visited)
{
    queue<pair<int, int>> q;
    q.push({src, 1});
    int count = 0;

    while (!q.empty())
    {
        pair<int, int> pair = q.front();
        q.pop();
        if (visited[pair.first] != -1)
        {
            continue;
        }
        if (pair.second > t)
        {
            return count;
        }

        visited[pair.first] = pair.second;
        count++;
        for (auto &&edge : graph[pair.first])
        {
            if (visited[edge.nbr] == -1)
            {
                q.push({edge.nbr, pair.second + 1});
            }
        }
    }
    return count;
}

int main()
{
    int vertices, edges, src, t;
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
    cin >> src >> t;
    cout << infectedPersons(graph, src, t, visited) << endl;
    return 0;
}
