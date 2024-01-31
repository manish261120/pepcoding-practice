// LINK - https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/max-score-official/ojquestion

// TC = O(2^n), SC = O(n)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(vector<string> &words, vector<int> &farr, vector<int> &score, int idx)
{
    if (idx == words.size())
    {
        return 0;
    }
    int exscore = solution(words, farr, score, idx + 1);

    bool flag = true;
    int inscore = 0;
    int wscore = 0;

    for (auto &&ch : words[idx])
    {
        if (farr[ch - 'a'] == 0)
        {
            flag = false;
        }
        farr[ch - 'a']--;
        wscore += score[ch - 'a'];
    }

    if (flag)
    {
        inscore = wscore + solution(words, farr, score, idx + 1);
    }

    for (auto &&ch : words[idx])
    {
        farr[ch - 'a']++;
    }
    return max(exscore, inscore);
}

int main()
{
    int n, m;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    cin >> m;
    vector<char> letters(m);
    for (int i = 0; i < m; i++)
    {
        cin >> letters[i];
    }

    vector<int> score(26);
    for (int i = 0; i < 26; i++)
    {
        cin >> score[i];
    }

    vector<int> farr(26, 0);
    for (auto &&ch : letters)
    {
        farr[ch - 'a']++;
    }

    cout << solution(words, farr, score, 0) << endl;
    return 0;
}