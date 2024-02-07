// LINK - https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/all-palindromic-partitions-official/ojquestion

// n = length of string
// TC = O(2^n), SC = (2^n)
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s)
{
    int left = 0, right = s.length() - 1;
    while (left < right)
    {
        if (s[left] != s[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

void solution(string str, string ssf)
{
    if (!str.length())
    {
        cout << ssf << endl;
        return;
    }

    for (int i = 1; i <= str.length(); i++)
    {
        string pre = str.substr(0, i);
        string newstr = str.substr(i);
        if (isPalindrome(pre))
        {
            solution(newstr, ssf + "(" + pre + ") ");
        }
    }
}

int main()
{
    string str;
    cin >> str;
    solution(str, "");
    return 0;
}