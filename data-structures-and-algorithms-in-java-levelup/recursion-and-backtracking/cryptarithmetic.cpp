// LINK - https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/cryptarithmetic-official/ojquestion

// n = length of unique string
// TC = O(10^n), SC = (n)
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int getNum(string s, unordered_map<char, int> &mp)
{
    string num = "";
    for (auto &&ch : s)
    {
        num += to_string(mp[ch]);
    }
    return stoi(num);
}

void solution(unordered_map<char, int> &mp, vector<bool> &used_nums, string unique, int ind, string s1, string s2, string s3)
{
    if (ind == unique.size())
    {
        int n1 = getNum(s1, mp);
        int n2 = getNum(s2, mp);
        int n3 = getNum(s3, mp);
        if (n1 + n2 == n3)
        {
            for (int i = 0; i < 26; i++)
            {
                char ch = 'a' + i;
                if (mp.find(ch) != mp.end())
                {
                    cout << ch << "-" << mp[ch] << " ";
                }
            }
            cout << endl;
        }

        return;
    }
    for (int i = 0; i < 10; i++)
    {
        if (!used_nums[i])
        {
            mp[unique[ind]] = i;
            used_nums[i] = true;
            solution(mp, used_nums, unique, ind + 1, s1, s2, s3);
            mp[unique[ind]] = -1;
            used_nums[i] = false;
        }
    }
}

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    string unique = "";
    unordered_map<char, int> mp;
    vector<bool> used_nums(10, false);
    for (auto &&ch : s1)
    {
        if (mp.find(ch) == mp.end())
        {
            mp[ch] = -1;
            unique += ch;
        }
    }
    for (auto &&ch : s2)
    {
        if (mp.find(ch) == mp.end())
        {
            mp[ch] = -1;
            unique += ch;
        }
    }
    for (auto &&ch : s3)
    {
        if (mp.find(ch) == mp.end())
        {
            mp[ch] = -1;
            unique += ch;
        }
    }
    solution(mp, used_nums, unique, 0, s1, s2, s3);
    return 0;
}