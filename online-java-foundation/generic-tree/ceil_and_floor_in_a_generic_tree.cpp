// LINK - https://www.pepcoding.com/resources/online-java-foundation/generic-tree/ceil-and-floor-official/ojquestion

// TC = O(n), SC = O(n)
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

int ceil = INT16_MAX;
int floor = INT16_MIN;

void ceilAndFloor(Node *node, int data)
{
    if (node->data < data)
    {
        floor = max(floor, node->data);
    }

    if (node->data > data)
    {
        ceil = min(ceil, node->data);
    }

    for (auto &&child : node->children)
    {
        ceilAndFloor(child, data);
    }
}

int main()
{

    int n, val;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> val;

    Node *root = construct(arr, n);
    ceilAndFloor(root, val);
    cout << "CEIL = " << ceil << endl;
    cout << "FLOOR = " << floor << endl;
    return 0;
}
