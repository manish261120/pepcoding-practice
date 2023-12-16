// LINK - https://www.pepcoding.com/resources/online-java-foundation/hashmap-and-heap/lcqs-official/ojquestion

// TC = O(n), SC = O(n)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void longestConsecutive(vector<int> nums)
{
    unordered_map<int, bool> umap;
    int max_start_point = 0, max_length = 0;

    for (auto &&num : nums)
    {
        umap[num] = true;
    }

    for (auto &&num : nums)
    {
        if (umap.find(num - 1) != umap.end())
        {
            umap[num] = false;
        }
    }

    for (auto &&num : nums)
    {
        if (umap[num])
        {
            int temp_length = 1;
            int temp_start_point = num;

            while (umap.find(temp_start_point + temp_length) != umap.end())
            {
                temp_length++;
            }
            if (temp_length > temp_start_point)
            {
                max_start_point = temp_start_point;
                max_length = temp_length;
            }
        }
    }

    for (int i = 0; i < max_length; i++)
    {
        cout << max_start_point + i << endl;
    }
}

int main()
{
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        arr.push_back(data);
    }
    longestConsecutive(arr);

    return 0;
}
