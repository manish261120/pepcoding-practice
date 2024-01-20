// LINK - https://www.pepcoding.com/resources/online-java-foundation/graphs/count-islands-official/ojquestion

// TC = O(4^(n*m)), SC = O(n*m)

#include <iostream>
#include <vector>
using namespace std;

void countIslands(vector<vector<int>> graph, int row, int col, vector<vector<bool>> &visited)
{
    if (row < 0 || row == graph.size() || col < 0 || col == graph[0].size() || visited[row][col] || graph[row][col] == 1)
    {
        return;
    }
    visited[row][col] = true;

    countIslands(graph, row, col - 1, visited);
    countIslands(graph, row - 1, col, visited);
    countIslands(graph, row, col + 1, visited);
    countIslands(graph, row + 1, col, visited);
}

int main()
{
    int n, m, val;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> val;
            graph[i][j] = val;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 0 && visited[i][j] == false)
            {
                count++;
                countIslands(graph, i, j, visited);
            }
        }
    }

    cout << count;
    return 0;
}
