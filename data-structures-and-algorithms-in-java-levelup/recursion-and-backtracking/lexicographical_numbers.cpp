// LINK - https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/lexicographical-numbers-official/ojquestion

// TC = O(n), SC O(-)
#include <iostream>
using namespace std;
void solution(int i, int n)
{
    if (i > n)
    {
        return;
    }

    cout << i << endl;
    for (int j = 0; j < 10; j++)
    {
        solution(10 * i + j, n);
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= 9; i++)
    {
        solution(i, n);
    }
    return 0;
}