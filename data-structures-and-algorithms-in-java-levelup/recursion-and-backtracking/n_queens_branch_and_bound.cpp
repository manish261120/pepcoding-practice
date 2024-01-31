// LINK - https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/nqueens-branch-and-bound-official/ojquestion

// TC = O(n!) or (nlogn), SC = O(n)
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void solution(vector<vector<bool>> &board, int r, vector<bool> &cols, vector<bool> &nd, vector<bool> &rd, string asf)
{
    int n = board.size();
    if (r == n)
    {
        cout << asf << "." << endl;
        return;
    }
    int c = 0;
    for (c = 0; c < n; c++)
    {
        if (cols[c] == false && nd[r + c] == false && rd[r - c + n - 1] == false)
        {
            cols[c] = true;
            nd[r + c] = true;
            rd[r - c + n - 1] = true;
            solution(board, r + 1, cols, nd, rd, asf + to_string(r) + "-" + to_string(c) + ", ");
            cols[c] = false;
            nd[r + c] = false;
            rd[r - c + n - 1] = false;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<bool>> board(n, vector<bool>(n));
    vector<bool> cols(n, false);
    vector<bool> nd(2 * n - 1, false);
    vector<bool> rd(2 * n - 1, false);

    solution(board, 0, cols, nd, rd, "");
    return 0;
}