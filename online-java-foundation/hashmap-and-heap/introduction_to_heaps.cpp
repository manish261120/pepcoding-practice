// LINK - https://www.pepcoding.com/resources/online-java-foundation/hashmap-and-heap/heaps-intro/video

// TC = O(nlogn), SC = O(nlogn)
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int arr[] = {22, 99, 3, 11, 88, 4, 1};
    // priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto &&num : arr)
    {
        pq.push(num);
    }

    while (pq.size())
    {
        cout << pq.top() << endl;
        pq.pop();
    }

    return 0;
}
