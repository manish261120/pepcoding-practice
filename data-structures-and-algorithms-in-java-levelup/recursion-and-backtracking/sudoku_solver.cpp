// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/solve-sudoku-official/ojquestion

// TC = O(9^(n*n)), SC = (n^2)
#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<vector<int>> &sudoku, int r, int c, int num)
{
    for (int j = 0; j < sudoku.size(); j++)
    {
        if (sudoku[r][j] == num)
        {
            return false;
        }
    }

    for (int i = 0; i < sudoku.size(); i++)
    {
        if (sudoku[i][c] == num)
        {
            return false;
        }
    }
    int sr = r / 3 * 3;
    int sc = c / 3 * 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (sudoku[sr + i][sc + j] == num)
            {
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>> &sudoku, int r, int c)
{
    if (r == sudoku.size())
    {
        for (int i = 0; i < sudoku.size(); i++)
        {
            for (int j = 0; j < sudoku[0].size(); j++)
            {
                cout << sudoku[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }

    int nr, nc;
    if (c == sudoku.size() - 1)
    {
        nr = r + 1;
        nc = 0;
    }
    else
    {
        nr = r;
        nc = c + 1;
    }

    if (sudoku[r][c])
    {
        solveSudoku(sudoku, nr, nc);
    }
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            if (isValid(sudoku, r, c, i))
            {
                sudoku[r][c] = i;
                solveSudoku(sudoku, nr, nc);
                sudoku[r][c] = 0;
            }
        }
    }
}

int main()
{
    int n = 9;
    vector<vector<int>> sudoku(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> sudoku[i][j];
        }
    }
    solveSudoku(sudoku, 0, 0);

    return 0;
}