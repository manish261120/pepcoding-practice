// LINK - https://www.pepcoding.com/resources/online-java-foundation/hashmap-and-heap/priority-queue-using-heap-official/ojquestion

// TC = O(logn), SC = O(1)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Compare
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

class PriorityQueue
{
private:
    vector<int> vec;

    void upHeapify(int ind)
    {
        while (ind)
        {
            int pi = (ind - 1) / 2;
            if (vec[ind] < vec[pi])
            {
                swap(vec[ind], vec[pi]);
                ind = pi;
            }
            else
            {
                break;
            }
        }
    }

    void downHeapify(int pi)
    {
        while (pi != vec.size())
        {
            int mini = pi;
            int li = 2 * pi + 1;
            int ri = 2 * pi + 2;
            if (li < vec.size() && vec[li] < vec[mini])
            {
                mini = li;
            }
            if (ri < vec.size() && vec[ri] < vec[mini])
            {
                mini = ri;
            }
            if (mini != pi)
            {
                swap(vec[pi], vec[mini]);
                pi = mini;
            }
            else
            {
                break;
            }
        }
    }

public:
    void add(int val)
    {
        vec.push_back(val);
        // push_heap(vec.begin(), vec.end(), Compare());
        upHeapify(vec.size() - 1);
    }

    int remove()
    {
        if (!size())
        {
            cout << "Underflow" << endl;
            return -1;
        }
        int val = peek();
        // pop_heap(vec.begin(), vec.end(), Compare());
        swap(vec[0], vec[size() - 1]);
        vec.pop_back();
        downHeapify(0);
        return val;
    }

    int peek()
    {
        if (!size())
        {
            cout << "Underflow" << endl;
            return -1;
        }
        return vec.front();
    }

    int size()
    {
        return vec.size();
    }
};

int main()
{
    PriorityQueue pq;
    string str;
    getline(cin, str);

    while (str != "quit")
    {
        if (str[0] == 'a')
        {
            string num = str.substr(4);
            pq.add(stoi(num));
        }
        else if (str[0] == 'r')
        {
            int val = pq.remove();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if (str[0] == 'p')
        {
            int val = pq.peek();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if (str[0] == 's')
        {
            cout << pq.size() << endl;
        }
        getline(cin, str);
    }

    return 0;
}