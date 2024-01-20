// LINK - https://www.pepcoding.com/resources/online-java-foundation/graphs/knights-tour-official/ojquestion

// TC = O(8^(n^2)), SC = O(n^2)

#include <iostream>
#include <vector>
using namespace std;

void display(vector<vector<int>> chess)
{
    int n = chess.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << chess[i][j] << " ";
        }
        cout << endl;
    }
}

void knightsTours(vector<vector<int>> chess, int row, int col, int move)
{
    int n = chess.size();
    if (row < 0 || row >= n || col < 0 || col >= n || chess[row][col] >= 1)
    {
        return;
    }
    if (move == n * n)
    {
        chess[row][col] = move;
        display(chess);
        chess[row][col] = 0;
        return;
    }

    chess[row][col] = move;

    knightsTours(chess, row - 2, col + 1, move + 1);
    knightsTours(chess, row - 1, col + 2, move + 1);
    knightsTours(chess, row + 1, col + 2, move + 1);
    knightsTours(chess, row + 2, col + 1, move + 1);
    knightsTours(chess, row + 2, col - 1, move + 1);
    knightsTours(chess, row + 1, col - 2, move + 1);
    knightsTours(chess, row - 1, col - 2, move + 1);
    knightsTours(chess, row - 2, col - 1, move + 1);

    chess[row][col] = 0;
}

int main()
{
    int n, r, c;
    cin >> n >> r >> c;
    vector<vector<int>> chess(n, vector<int>(n, 0));
    knightsTours(chess, r, c, 1);
    return 0;
}
