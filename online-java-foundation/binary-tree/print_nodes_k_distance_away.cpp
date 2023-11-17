// LINK - https://www.pepcoding.com/resources/online-java-foundation/binary-tree/print-nodes-k-away-binary-tree-official/ojquestion

// TC = O(n), SC = O(n)
#include <iostream>
#include <stack>
#include <vector>
#include <utility>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

Node *construct(int arr[], int n)
{
    Node *root = new Node;
    stack<pair<Node *, int>> stack;
    root->data = arr[0];
    stack.push({root, 1});
    int ind = 1;

    while (stack.size())
    {
        if (stack.top().second == 1)
        {
            Node *node = new Node;
            if (arr[ind] == -1)
            {
                node = NULL;
                stack.top().first->left = node;
                stack.top().second++;
            }
            else
            {
                node->data = arr[ind];
                stack.top().first->left = node;
                stack.top().second++;
                stack.push({node, 1});
            }
            ind++;
        }
        else if (stack.top().second == 2)
        {
            Node *node = new Node;
            if (arr[ind] == -1)
            {
                node = NULL;
                stack.top().first->right = node;
                stack.top().second++;
            }
            else
            {
                node->data = arr[ind];
                stack.top().first->right = node;
                stack.top().second++;
                stack.push({node, 1});
            }
            ind++;
        }
        else if (stack.top().second == 3)
        {
            stack.pop();
        }
    }
    return root;
}

vector<Node *> nodeToRootPath(Node *node, int data)
{
    vector<Node *> ans;
    if (node->data == data)
    {
        ans.push_back(node);
        return ans;
    }
    if (node->left)
    {
        ans = nodeToRootPath(node->left, data);
        if (ans.size())
        {
            ans.push_back(node);
            return ans;
        }
    }
    if (node->right)
    {
        ans = nodeToRootPath(node->right, data);
        if (ans.size())
        {
            ans.push_back(node);
            return ans;
        }
    }
    return ans;
}

void kLevelsDown(Node *node, int k, Node *blocker)
{
    if (node == NULL || k < 0 || node == blocker)
    {
        return;
    }
    if (k == 0)
    {
        cout << node->data << endl;
    }

    kLevelsDown(node->left, k - 1, blocker);
    kLevelsDown(node->right, k - 1, blocker);
}

void printKNodesFar(Node *node, int data, int k)
{
    vector<Node *> path = nodeToRootPath(node, data);
    Node *blocker;
    for (int i = 0; i < path.size(); i++)
    {
        blocker = i ? path[i - 1] : NULL;
        kLevelsDown(path[i], k - i, blocker);
    }
}

int main()
{

    int n, data, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "n")
        {
            arr[i] = -1;
        }
        else
        {
            arr[i] = stoi(s);
        }
    }
    cin >> data >> k;

    Node *root = construct(arr, n);
    printKNodesFar(root, data, k);
    return 0;
}
