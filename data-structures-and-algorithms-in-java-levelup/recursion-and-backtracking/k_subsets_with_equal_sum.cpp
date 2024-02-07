// LINK - https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/k-subsets-with-equal-sum-official/ojquestion

// TC = O(n^k), SC = (n)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void display(vector<int> &subsetSum, vector<vector<int>> &arr)
{
    int sum = subsetSum[0];
    for (int i = 1; i < subsetSum.size(); i++)
    {
        if (subsetSum[i] != sum)
        {
            return;
        }
    }

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

void solution(vector<int> &arr, int idx, int k, vector<int> &subsetSum, int sssf, vector<vector<int>> &ans)
{
    if (idx == arr.size())
    {
        if (sssf == k)
        {
            display(subsetSum, ans);
        }
        return;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i].size())
        {
            ans[i].push_back(arr[idx]);
            subsetSum[i] += arr[idx];
            solution(arr, idx + 1, k, subsetSum, sssf, ans);
            ans[i].pop_back();
            subsetSum[i] -= arr[idx];
        }
        else
        {
            ans[i].push_back(arr[idx]);
            subsetSum[i] += arr[idx];
            solution(arr, idx + 1, k, subsetSum, sssf + 1, ans);
            ans[i].pop_back();
            subsetSum[i] -= arr[idx];
            break;
        }
    }
}

int main()
{
    int n, k, sum = 0;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    cin >> k;

    if (k == 1)
    {
        cout << "[";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i];
            if (i < n - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
        return 0;
    }

    if (k > n || sum % k)
    {
        cout << -1 << endl;
        return 0;
    }
    vector<int> subsetSum(k, 0);
    vector<vector<int>> ans(k, vector<int>());

    solution(arr, 0, k, subsetSum, 0, ans);
    return 0;
}