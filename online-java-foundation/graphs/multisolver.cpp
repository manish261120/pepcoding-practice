// LINK - https://www.pepcoding.com/resources/online-java-foundation/graphs/mutilsovler-graph-official/ojquestion

// TC = O(V*E), SC = O(V+k)

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
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

int spwt = INT16_MAX;
int lpwt = INT16_MIN;
int jlpwt = INT16_MAX;
int jspwt = INT16_MIN;
string spath, lpath, jlpath, jspath;
priority_queue<int, vector<pair<int, string>>, greater<pair<int, string>>> pq;

void multiSolver(vector<Edge> graph[], int src, int dest, int criteria, int k, vector<bool> visited, string path, int wt)
{
    if (src == dest)
    {
        if (wt < spwt)
        {
            spwt = wt;
            spath = path;
        }
        if (wt > lpwt)
        {
            lpwt = wt;
            lpath = path;
        }
        if (wt > criteria && wt < jlpwt)
        {
            jlpwt = wt;
            jlpath = path;
        }
        if (wt < criteria && wt > jspwt)
        {
            jspwt = wt;
            jspath = path;
        }
        if (pq.size() < k)
        {
            pq.push({wt, path});
        }
        else if (wt > pq.top().first)
        {
            pq.pop();
            pq.push({wt, path});
        }

        return;
    }
    visited[src] = true;
    for (auto &&edge : graph[src])
    {
        if (visited[edge.nbr] == false)
        {
            multiSolver(graph, edge.nbr, dest, criteria, k, visited, path + to_string(edge.nbr), wt + edge.wt);
        }
    }
    visited[src] = false;
}

int main()
{
    int vertices, edges, src, dest, criteria, k;
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

    cin >> src >> dest >> criteria >> k;
    multiSolver(graph, src, dest, criteria, k, visited, to_string(src), 0);
    cout << "Smallest Path = " << spath << "@" << spwt << endl;
    cout << "Largest Path = " << lpath << "@" << lpwt << endl;
    cout << "Just Larger Path than = " << jlpath << "@" << jlpwt << endl;
    cout << "Just Smaller Path than = " << jspath << "@" << jspwt << endl;
    cout << k << "th largest path = " << pq.top().second << "@" << pq.top().first << endl;
    return 0;
}
