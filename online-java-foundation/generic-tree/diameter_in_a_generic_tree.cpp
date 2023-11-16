// LINK - https://www.pepcoding.com/resources/online-java-foundation/generic-tree/diameter-of-generic-tree-official/ojquestion

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

int dia = 0;

int diameter(Node *node)
{
    int max_height = -1;
    int sec_max_height = -1;
    for (auto &&child : node->children)
    {
        int height = diameter(child);
        if (height > max_height)
        {
            sec_max_height = max_height;
            max_height = max(max_height, height);
        }
        else if (height > sec_max_height)
        {
            sec_max_height = height;
        }
    }
    dia = max(dia, max_height + sec_max_height + 2);
    return max_height + 1;
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

    Node *root = construct(arr, n);
    diameter(root);
    cout << dia << endl;
    return 0;
}
