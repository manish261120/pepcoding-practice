// LINK - https://www.pepcoding.com/resources/online-java-foundation/generic-tree/is-generic-tree-symmetric-official/ojquestion

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

bool areSimilar(Node *n1, Node *n2)
{
    if (n1->children.size() != n2->children.size())
    {
        return false;
    }

    for (int i = 0; i < n1->children.size(); i++)
    {
        bool res = areSimilar(n1->children[i], n2->children[n2->children.size() - 1 - i]);
        if (!res)
        {
            return res;
        }
    }
    return true;
}

bool IsSymmetric(Node *node)
{
    return areSimilar(node, node);
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
    bool ans = IsSymmetric(root);
    if (ans)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}
