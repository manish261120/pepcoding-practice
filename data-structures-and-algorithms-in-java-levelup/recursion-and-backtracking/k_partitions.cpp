// LINK - https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/k-partitions-official/ojquestion

// TC = O(n^k), SC = (n)
#include <iostream>
#include <vector>
using namespace std;

int counter = 0;

void display(vector<vector<int>> &arr)
{
    counter++;
    cout << counter << ". ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j];
            if (j < arr[i].size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;
}

void solution(int i, int n, int k, int sets_count, vector<vector<int>> &ans)
{
    if (i > n)
    {
        if (sets_count == k)
        {
            display(ans);
        }
        return;
    }

    for (int j = 0; j < ans.size(); j++)
    {
        if (ans[j].size())
        {
            ans[j].push_back(i);
            solution(i + 1, n, k, sets_count, ans);
            ans[j].pop_back();
        }
        else
        {
            ans[j].push_back(i);
            solution(i + 1, n, k, sets_count + 1, ans);
            ans[j].pop_back();
            break;
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> ans(k, vector<int>());

    solution(1, n, k, 0, ans);
    return 0;
}