// LINK - https://www.pepcoding.com/resources/online-java-foundation/hashmap-and-heap/sort-ksorted-official/ojquestion

// TC = O(nlogk), SC = O(k)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void sortK(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        if (i > k)
        {
            cout << pq.top() << endl;
            pq.pop();
        }
        pq.push(arr[i]);
    }
    while (pq.size())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}

int main()
{
    int n, k, data;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        arr[i] = data;
    }
    cin >> k;
    sortK(arr, n, k);

    return 0;
}