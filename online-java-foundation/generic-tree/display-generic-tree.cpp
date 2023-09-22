// LINK - https://www.pepcoding.com/resources/online-java-foundation/generic-tree/display-generic-tree/video

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

int display(Node *node)
{
    string s = to_string(node->data) + " -> ";
    for (auto &&child : node->children)
    {
        s += to_string(child->data) + ", ";
    }
    cout << s << endl;
    for (auto &&child : node->children)
    {
        display(child);
    }
}

int main()
{
    int arr[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node *root;
    stack<Node *> stack;

    for (int i = 0; i < size; i++)
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
    display(root);
    return 0;
}
