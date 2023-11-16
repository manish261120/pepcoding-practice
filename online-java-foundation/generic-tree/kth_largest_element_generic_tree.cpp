// LINK - https://www.pepcoding.com/resources/online-java-foundation/generic-tree/kth-largest-element-generic-tree-official/ojquestion

// TC = O(n*k), SC = O(n)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    vector<Node *> children;
};

Node *construct(int arr[], int n)
{
    Node *root;
    stack<Node *> stack;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
        {
            stack.pop();
        }
        else
        {
            Node *node = new Node();
            node->data = arr[i];

            if (stack.size())
            {
                Node *parent = stack.top();
                parent->children.push_back(node);
            }
            else
            {
                root = node;
            }

            stack.push(node);
        }
    }
    return root;
}

int floor = INT16_MIN;

void getFloor(Node *node, int data)
{
    if (node->data < data)
    {
        floor = max(floor, node->data);
    }

    for (auto &&child : node->children)
    {
        getFloor(child, data);
    }
}

int kthlarge(Node *node, int k)
{
    int data = INT16_MAX;
    for (int i = 0; i < k; i++)
    {
        getFloor(node, data);
        data = floor;
        floor = INT16_MIN;
    }
    return data;
}

int main()
{

    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;

    Node *root = construct(arr, n);
    cout << kthlarge(root, k) << endl;
    return 0;
}
