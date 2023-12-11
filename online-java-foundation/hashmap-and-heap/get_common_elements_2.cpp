// LINK - https://www.pepcoding.com/resources/online-java-foundation/hashmap-and-heap/gce2-official/ojquestion

// TC = O(n2), SC = O(n1)
#include <iostream>
#include <unordered_map>
using namespace std;

void printIntersection(int arr1[], int arr2[], int n1, int n2)
{
    unordered_map<char, int> umap;
    for (int i = 0; i < n1; i++)
    {
        umap[arr1[i]]++;
    }

    for (int i = 0; i < n2; i++)
    {
        if (umap.find(arr2[i]) != umap.end() && umap[arr2[i]] > 0)
        {
            cout << arr2[i] << endl;
            umap[arr2[i]]--;
        }
    }
}

int main()
{
    int n1, n2;
    cin >> n1;
    int arr1[n1];

    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    cin >> n2;
    int arr2[n2];
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n1, n2);
    return 0;
}
