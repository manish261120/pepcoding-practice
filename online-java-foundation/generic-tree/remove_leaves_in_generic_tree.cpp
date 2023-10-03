// LINK - https://www.pepcoding.com/resources/online-java-foundation/generic-tree/remove-leaves-generic-tree-official/ojquestion

// TC = O(d), SC = O(n)
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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

int display(Node *node)
{
    string s = to_string(node->data) + " -> ";
    for (auto &&child : node->children)
    {
        s += to_string(child->data) + ", ";
    }
    cout << s << "." << endl;
    for (auto &&child : node->children)
    {
        display(child);
    }
}

void removeLeaves(Node *node)
{

    for (int i = node->children.size() - 1; i >= 0; i--)
    {
        Node *child = node->children[i];
        if (!child->children.size())
        {
            node->children.erase(node->children.begin() + i);
        }
    }

    for (auto &&child : node->children)
    {
        removeLeaves(child);
    }
}

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *root = construct(arr, n);
    removeLeaves(root);
    display(root);
    return 0;
}
