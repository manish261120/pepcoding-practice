// LINK - https://www.pepcoding.com/resources/online-java-foundation/generic-tree/levelorder-linewise-generic-tree-official/ojquestion

// TC = O(n), SC = O(n)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
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

void levelOrderLinewise1(Node *node)
{
    queue<Node *> queue;
    queue.push(node);
    queue.push(NULL);

    while (queue.size())
    {
        node = queue.front();
        queue.pop();
        if (node)
        {
            cout << node->data << " ";
            for (auto &&child : node->children)
            {
                queue.push(child);
            }
        }
        else
        {
            if (queue.size())
            {
                queue.push(NULL);
                cout << endl;
            }
        }
    }
}

void levelOrderLinewise2(Node *node)
{
    queue<Node *> queue;
    queue.push(node);

    while (queue.size())
    {
        int sz = queue.size();
        for (int i = 0; i < sz; i++)
        {

            node = queue.front();
            queue.pop();
            cout << node->data << " ";
            for (auto &&child : node->children)
            {
                queue.push(child);
            }
        }
        cout << endl;
    }
}

void levelOrderLinewise3(Node *node)
{
    queue<pair<Node *, int>> queue;
    queue.push({node, 1});

    int level = 1;
    while (queue.size())
    {

        pair<Node *, int> pair = queue.front();
        queue.pop();

        if (pair.second > level)
        {
            level = pair.second;
            cout << endl;
        }

        cout << pair.first->data << " ";
        for (auto &&child : pair.first->children)
        {
            queue.push({child, pair.second + 1});
        }
    }
    cout << endl;
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
    // levelOrderLinewise1(root);
    // levelOrderLinewise2(root);
    levelOrderLinewise3(root);
    return 0;
}
