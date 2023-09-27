// LINK - https://www.pepcoding.com/resources/online-java-foundation/generic-tree/levelorder-linewise-zigzag-official/ojquestion

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
    cout << s << endl;
    for (auto &&child : node->children)
    {
        display(child);
    }
}

void levelOrderLinewiseZZ(Node *node)
{
    stack<Node *> ps;
    stack<Node *> cs;

    ps.push(node);
    int level = 1;

    while (ps.size())
    {
        node = ps.top();
        ps.pop();
        cout << node->data << " ";

        if (level % 2)
        {
            for (int i = 0; i < node->children.size(); i++)
            {
                cs.push(node->children[i]);
            }
        }
        else
        {
            for (int i = node->children.size() - 1; i >= 0; i--)
            {
                cs.push(node->children[i]);
            }
        }
        if (!ps.size())
        {
            ps.swap(cs);
            cout << endl;
            level++;
        }
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
    levelOrderLinewiseZZ(root);
    return 0;
}