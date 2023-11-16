// LINK - https://www.pepcoding.com/resources/online-java-foundation/generic-tree/pred-succ-generic-tree-official/ojquestion

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

void display(Node *node)
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

Node *pre = NULL;
Node *suc = NULL;
int state = 0;

void predecessorAndSuccessor(Node *node, int data)
{

    if (node->data == data)
    {
        state++;
    }
    else if (state == 0)
    {
        pre = node;
    }
    else if (state == 1)
    {
        suc = node;
        state++;
    }
    else
    {
        return;
    }

    for (auto &&child : node->children)
    {
        predecessorAndSuccessor(child, data);
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
    predecessorAndSuccessor(root, val);
    if (pre == NULL)
    {
        cout << "Predecessor = Not found" << endl;
    }
    else
    {
        cout << "Predecessor = " << pre->data << endl;
    }

    if (suc == NULL)
    {
        cout << "Successor = Not found";
    }
    else
    {
        cout << "Successor = " << suc->data;
    }
    return 0;
}
