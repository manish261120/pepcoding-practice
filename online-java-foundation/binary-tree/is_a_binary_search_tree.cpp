// LINK - https://www.pepcoding.com/resources/online-java-foundation/binary-tree/is-bst-official/ojquestion

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

BSTPair bst(Node *node)
{
    BSTPair pair;
    if (node == NULL)
    {
        pair.isBST = true;
        pair.min = INT16_MAX;
        pair.max = INT16_MIN;
        return pair;
    }

    BSTPair left = bst(node->left);
    BSTPair right = bst(node->right);

    pair.isBST = left.isBST && right.isBST && node->data >= left.max && node->data <= right.min;
    pair.max = max(node->data, max(left.max, right.max));
    pair.min = min(node->data, min(left.min, right.min));
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
    BSTPair pair = bst(root);
    pair.isBST ? cout << "true" : cout << "false";

    return 0;
}
