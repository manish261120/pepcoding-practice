// LINK - https://www.pepcoding.com/resources/online-java-foundation/hashmap-and-heap/k-largest-elements-official/ojquestion

// TC = O(nlogk), SC = O(k)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void findKthLargest(vector<int> arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto &&num : arr)
    {
        if (pq.size() < k)
        {
            pq.push(num);
        }
        else
        {
            if (num > pq.top())
            {
                pq.pop();
                pq.push(num);
            }
        }
    }

    while (pq.size())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}

int main()
{
    vector<int> arr;
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        arr.push_back(data);
    }

    cin >> k;
    findKthLargest(arr, k);

    return 0;
}