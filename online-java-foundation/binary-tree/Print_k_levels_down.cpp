// LINK - https://www.pepcoding.com/resources/online-java-foundation/binary-tree/print-k-levels-down-official/ojquestion

// TC = O(n), SC = O(n)
#include <iostream>
#include <stack>
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

// iterative
void kLevelsDown1(Node *node, int k)
{
    int level = 0;
    stack<pair<Node *, int>> stack;
    stack.push({node, 1});

    while (stack.size())
    {
        pair<Node *, int> pair = stack.top();
        if (k == level)
        {
            cout << pair.first->data << endl;
            stack.pop();
            level--;
        }
        else if (pair.second == 1)
        {
            stack.top().second++;
            if (pair.first->left)
            {
                stack.push({pair.first->left, 1});
                level++;
            }
        }
        else if (pair.second == 2)
        {
            stack.top().second++;
            if (pair.first->right)
            {
                stack.push({pair.first->right, 1});
                level++;
            }
        }
        else
        {
            stack.pop();
            level--;
        }
    }
}

// recursive
void kLevelsDown2(Node *node, int k)
{
    if (node == NULL || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        cout << node->data << endl;
    }

    kLevelsDown2(node->left, k - 1);
    kLevelsDown2(node->right, k - 1);
}

int main()
{

    int n, k;
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
    cin >> k;

    Node *root = construct(arr, n);
    // kLevelsDown1(root, k);
    kLevelsDown2(root, k);
    return 0;
}
