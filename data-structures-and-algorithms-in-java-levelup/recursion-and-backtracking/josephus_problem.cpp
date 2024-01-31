// LINK - https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/josephus-problem-official/ojquestion

// TC = O(n), SC = O(n)
#include <iostream>
using namespace std;

int solution(int n, int k)
{
    if (n == 1)
    {
        return 0;
    }
    int pos = solution(n - 1, k);
    return (pos + k) % n;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << solution(n, k) << endl;
    return 0;
}