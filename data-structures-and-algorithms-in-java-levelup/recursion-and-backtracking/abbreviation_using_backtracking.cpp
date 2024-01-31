// LINK - https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/abbreviation-suing-backtracking-official/ojquestion

// TC = O(2^n), SC = O(n)
#include <iostream>
#include <string>
using namespace std;

void solution(string str, string asf, int count, int pos)
{
    if (pos == str.length())
    {
        if (count)
        {
            cout << asf << to_string(count) << endl;
        }
        else
        {
            cout << asf << endl;
        }
        return;
    }
    string st = "";
    if (count)
    {
        st = to_string(count);
    }

    solution(str, asf + st + str[pos], 0, pos + 1);
    solution(str, asf, count + 1, pos + 1);
}

int main()
{
    string str;
    cin >> str;
    solution(str, "", 0, 0);
    return 0;
}