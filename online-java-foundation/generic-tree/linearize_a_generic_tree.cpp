// LINK - https://www.pepcoding.com/resources/online-java-foundation/generic-tree/linearize-generic-tree-official/ojquestion

// TC = O(n^2), SC = O(n)
// TC = O(n), SC = O(n) - efficient
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

Node *getTail(Node *node)
{
    while (node->children.size())
    {
        node = node->children[0];
    }
    return node;
}

void linearize(Node *node)
{
    for (auto &&child : node->children)
    {
        linearize(child);
    }

    while (node->children.size() > 1)
    {
        Node *last_child = node->children.at(node->children.size() - 1);
        node->children.erase(node->children.begin() + node->children.size() - 1);
        Node *second_last_child = node->children.at(node->children.size() - 1);
        Node *second_last_tail = getTail(second_last_child);
        second_last_tail->children.push_back(last_child);
    }
}

Node *linearizeEfficient(Node *node)
{
    if (!node->children.size())
    {
        return node;
    }

    Node *tail = linearizeEfficient(node->children.at(node->children.size() - 1));

    while (node->children.size() > 1)
    {
        Node *last_child = node->children.at(node->children.size() - 1);
        node->children.erase(node->children.begin() + node->children.size() - 1);
        Node *second_last_child = node->children.at(node->children.size() - 1);
        Node *second_tail = linearizeEfficient(second_last_child);
        second_tail->children.push_back(last_child);
    }

    return tail;
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
    // linearize(root);
    linearizeEfficient(root);
    display(root);
    return 0;
}
