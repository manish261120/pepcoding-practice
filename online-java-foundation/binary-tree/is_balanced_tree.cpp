// LINK - https://www.pepcoding.com/resources/online-java-foundation/binary-tree/is-balanced-binary-tree-official/ojquestion

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

class BTPair
{
public:
    bool isBT;
    int height;
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

BTPair isbalance1(Node *node)
{
    BTPair pair;
    if (node == NULL)
    {
        pair.isBT = true;
        pair.height = 0;
        return pair;
    }
    BTPair left = isbalance1(node->left);
    BTPair right = isbalance1(node->right);

    pair.isBT = left.isBT && right.isBT && abs(left.height - right.height) <= 1;
    pair.height = max(left.height, right.height) + 1;
    return pair;
}

bool isBT = true;

int isBalance2(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int lh = isBalance2(node->left);
    int rh = isBalance2(node->right);

    if (abs(lh - rh) > 1)
    {
        isBT = false;
    }
    return max(lh, rh) + 1;
}

int main()
{

    int n;
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

    Node *root = construct(arr, n);
    // BTPair pair = isbalance1(root);
    // pair.isBT ? cout << "true" : cout << "false";

    int ans = isBalance2(root);
    isBT ? cout << "true" : cout << "false";

    return 0;
}
