// LINK - https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/friends-pairing-2-official/ojquestion

// TC = O(n^n), SC = (n)
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int counter = 1;
void solution(int num, int n, vector<bool> &used, string sf)
{
    if (num > n)
    {
        cout << counter << "." << sf << endl;
        counter++;
        return;
    }

    if (used[num])
    {
        solution(num + 1, n, used, sf);
    }
    else
    {
        used[num] = true;
        solution(num + 1, n, used, sf + "(" + to_string(num) + ") ");
        for (int i = num + 1; i <= n; i++)
        {
            if (!used[i])
            {
                used[i] = true;
                solution(num + 1, n, used, sf + "(" + to_string(num) + "," + to_string(i) + ") ");
                used[i] = false;
            }
        }
        used[num] = false;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<bool> used(n + 1, false);
    solution(1, n, used, "");
    return 0;
}