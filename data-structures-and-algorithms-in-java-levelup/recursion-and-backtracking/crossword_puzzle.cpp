// LINK - https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/crossword-puzzle-official/ojquestion

// N = size of grid, M = size of grid[i], n = size of words
// TC = O(N*M*n), SC = (-)
#include <iostream>
#include <vector>
using namespace std;

bool canPlaceH(vector<vector<char>> &grid, string word, int r, int c)
{
    int s = word.size();
    if (c - 1 >= 0 && grid[r][c - 1] != '+')
    {
        return false;
    }
    if (c + s < grid[0].size() && grid[r][c + s] != '+')
    {
        return false;
    }

    for (int j = 0; j < s; j++)
    {
        if (c + j >= grid[0].size())
        {
            return false;
        }
        if (grid[r][c + j] == '-' || grid[r][c + j] == word[j])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool canPlaceV(vector<vector<char>> &grid, string word, int r, int c)
{
    int s = word.size();
    if (r - 1 >= 0 && grid[r - 1][c] != '+')
    {
        return false;
    }
    if (r + s < grid.size() && grid[r + s][c] != '+')
    {
        return false;
    }

    for (int j = 0; j < s; j++)
    {
        if (r + j >= grid.size())
        {
            return false;
        }
        if (grid[r + j][c] == '-' || grid[r + j][c] == word[j])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

vector<bool> placeH(vector<vector<char>> &grid, string word, int r, int c)
{
    vector<bool> placed(word.size(), false);
    for (int j = 0; j < word.size(); j++)
    {
        if (grid[r][c + j] == '-')
        {
            grid[r][c + j] = word[j];
            placed[j] = true;
        }
    }
    return placed;
}

void unPlaceH(vector<vector<char>> &grid, vector<bool> placed, int r, int c)
{
    for (int j = 0; j < placed.size(); j++)
    {
        if (placed[j])
        {
            grid[r][c + j] = '-';
        }
    }
}

vector<bool> placeV(vector<vector<char>> &grid, string word, int r, int c)
{
    vector<bool> placed(word.size(), false);
    for (int i = 0; i < word.size(); i++)
    {
        if (grid[r + i][c] == '-')
        {
            grid[r + i][c] = word[i];
            placed[i] = true;
        }
    }
    return placed;
}

void unPlaceV(vector<vector<char>> &grid, vector<bool> placed, int r, int c)
{
    for (int i = 0; i < placed.size(); i++)
    {
        if (placed[i])
        {
            grid[r + i][c] = '-';
        }
    }
}

void display(vector<vector<char>> &grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

void solution(vector<vector<char>> &grid, vector<string> &words, int vidx)
{
    if (vidx == words.size())
    {
        display(grid);
        return;
    }

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '-' || grid[i][j] == words[vidx][0])
            {
                if (canPlaceH(grid, words[vidx], i, j))
                {
                    vector<bool> placed = placeH(grid, words[vidx], i, j);
                    solution(grid, words, vidx + 1);
                    unPlaceH(grid, placed, i, j);
                }
                if (canPlaceV(grid, words[vidx], i, j))
                {
                    vector<bool> placed = placeV(grid, words[vidx], i, j);
                    solution(grid, words, vidx + 1);
                    unPlaceV(grid, placed, i, j);
                }
            }
        }
    }
}

int main()
{
    int n;
    vector<vector<char>> grid(10, vector<char>(10));

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> grid[i][j];
        }
    }
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    solution(grid, words, 0);

    return 0;
}