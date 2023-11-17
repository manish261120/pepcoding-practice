// LINK - https://www.pepcoding.com/resources/online-java-foundation/binary-tree/size-sum-max-height-binarytree-official/ojquestion

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

int size(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int ls = size(node->left);
    int rs = size(node->right);
    return ls + rs + 1;
}

int height(Node *node)
{
    if (node == NULL)
    {
        return -1;
    }
    int lht = height(node->left);
    int rht = height(node->right);
    return max(lht, rht) + 1;
}

int maximum(Node *node)
{
    if (node == NULL)
    {
        return INT16_MIN;
    }
    int lmax = maximum(node->left);
    int rmax = maximum(node->right);
    return max(max(lmax, rmax), node->data);
}

int sum(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int lsum = sum(node->left);
    int rsum = sum(node->right);
    return lsum + rsum + node->data;
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
    cout << size(root) << endl;
    cout << sum(root) << endl;
    cout << maximum(root) << endl;
    cout << height(root) << endl;
    return 0;
}
