// LINK - https://www.pepcoding.com/resources/online-java-foundation/binary-tree/largest-bst-subtree-official/ojquestion

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

class BSTPair
{
public:
    bool isBST;
    int min;
    int max;
    Node *node;
    int size;
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

BSTPair lbst(Node *node)
{
    BSTPair pair;
    if (node == NULL)
    {
        pair.isBST = true;
        pair.max = INT16_MIN;
        pair.min = INT16_MAX;
        pair.node = NULL;
        pair.size = 0;
        return pair;
    }

    BSTPair lp = lbst(node->left);
    BSTPair rp = lbst(node->right);

    pair.isBST = lp.isBST && rp.isBST && node->data >= lp.max && node->data <= rp.min;
    pair.max = max(node->data, max(lp.max, rp.max));
    pair.min = max(node->data, max(lp.min, rp.min));

    if (pair.isBST)
    {
        pair.size = lp.size + rp.size + 1;
        pair.node = node;
    }
    else if (lp.size > rp.size)
    {
        pair.node = lp.node;
        pair.size = lp.size;
    }
    else
    {
        pair.node = rp.node;
        pair.size = rp.size;
    }

    return pair;
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
    BSTPair pair = lbst(root);
    cout << pair.node->data << "@" << pair.size << endl;

    return 0;
}
