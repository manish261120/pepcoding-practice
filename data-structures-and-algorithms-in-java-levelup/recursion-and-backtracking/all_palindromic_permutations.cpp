// LINK - https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/all-palindromic-permutations-official/ojquestion

// n = length of string
// TC = O(-), SC = (n)
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void solution(int i, int n, unordered_map<char, int> &fmp, string odd, string ssf)
{
    if (i > n)
    {
        string rev;
        for (int i = ssf.length() - 1; i >= 0; i--)
        {
            rev += ssf[i];
        }
        cout << ssf << odd << rev << endl;
        return;
    }

    for (auto &&it : fmp)
    {
        if (it.second)
        {
            fmp[it.first]--;
            solution(i + 1, n, fmp, odd, ssf + it.first);
            fmp[it.first]++;
        }
    }
}

int main()
{
    string str, ostr = "";
    int odds = 0, slen = 0;
    cin >> str;
    unordered_map<char, int> fmp;
    for (auto &&ch : str)
    {
        fmp[ch]++;
    }
    for (auto &&it : fmp)
    {
        if (it.second % 2)
        {
            odds++;
            ostr = it.first;
        }
        slen += it.second / 2;
        fmp[it.first] = it.second / 2;
    }
    if (odds > 1)
    {
        cout << -1 << endl;
        return 0;
    }
    solution(1, slen, fmp, ostr, "");
    return 0;
}