// LINK - https://www.pepcoding.com/resources/online-java-foundation/hashmap-and-heap/merge-k-sorted-lists-official/ojquestion

// TC = O(nlogk), SC = O(k)
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Container
{
public:
    int data;
    int li;
    int di;
    Container(int val, int list_index, int data_index)
    {
        data = val;
        li = list_index;
        di = data_index;
    }
};

class Compare
{
public:
    bool operator()(Container con1, Container con2)
    {
        return con1.data > con2.data;
    }
};

vector<int> mergeKSortedLists(vector<vector<int>> lists)
{
    vector<int> rv;
    priority_queue<Container, vector<Container>, Compare> pq;

    for (int i = 0; i < lists.size(); i++)
    {
        pq.push(Container(lists[i][0], i, 0));
    }

    while (pq.size())
    {
        Container con = pq.top();
        pq.pop();
        con.di++;
        if (con.di < lists[con.li].size())
        {
            pq.push(Container(lists[con.li][con.di], con.li, con.di));
        }
        rv.push_back(con.data);
    }
    return rv;
}

int main()
{
    int k;
    cin >> k;
    vector<vector<int>> lists;
    for (int i = 0; i < k; i++)
    {
        vector<int> list;

        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int data;
            cin >> data;
            list.push_back(data);
        }

        lists.push_back(list);
    }

    vector<int> mlist = mergeKSortedLists(lists);
    for (int val : mlist)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}