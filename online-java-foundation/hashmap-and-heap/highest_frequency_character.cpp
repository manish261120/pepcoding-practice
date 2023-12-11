// LINK - https://www.pepcoding.com/resources/online-java-foundation/hashmap-and-heap/hfc-official/ojquestion

// TC = O(n), SC = O(n)
#include <iostream>
#include <unordered_map>
using namespace std;

char hfc(string str)
{
    unordered_map<char, int> umap;
    char ch = str[0];

    for (auto &&c : str)
    {
        if (umap.find(c) != umap.end())
        {
            umap[c] += 1;
        }
        else
        {
            umap[c] = 1;
        }
        if (umap[c] > umap[ch])
        {
            ch = c;
        }
    }
    return ch;
}

int main()
{
    string str;
    cin >> str;

    cout << hfc(str) << endl;
    return 0;
}
