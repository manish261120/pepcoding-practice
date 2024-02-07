// LINK - https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/gold-mine-2-official/ojquestion

// TC = O(4^(n*m)), SC = (n*m)
#include <iostream>
#include <vector>
using namespace std;

int getMaxGold(vector<vector<int>> &grid, vector<vector<bool>> &visited, int r, int c)
{
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0 || visited[r][c] == true)
    {
        return 0;
    }
    visited[r][c] = true;
    int left = getMaxGold(grid, visited, r, c - 1);
    int up = getMaxGold(grid, visited, r - 1, c);
    int right = getMaxGold(grid, visited, r, c + 1);
    int down = getMaxGold(grid, visited, r + 1, c);
    return grid[r][c] + left + up + right + down;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int maxg = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j])
            {
                int ans = getMaxGold(grid, visited, i, j);
                maxg = max(maxg, ans);
            }
        }
    }
    cout << maxg << endl;
    return 0;
}