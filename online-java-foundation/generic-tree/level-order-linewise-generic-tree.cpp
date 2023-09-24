// LINK - https://www.pepcoding.com/resources/online-java-foundation/generic-tree/levelorder-linewise-generic-tree-official/ojquestion

// TC = O(n), SC = O(n)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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

void levelOrderLinewise(Node *node)
{
    queue<Node *> pq;
    queue<Node *> cq;

    pq.push(node);

    while (pq.size())
    {
        node = pq.front();
        pq.pop();
        cout << node->data << " ";
        for (auto &&child : node->children)
        {
            cq.push(child);
        }
        if (!pq.size())
        {
            while (cq.size())
            {
                pq.push(cq.front());
                cq.pop();
            }
            cout << endl;
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
    levelOrderLinewise(root);
    return 0;
}
