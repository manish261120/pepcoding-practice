// LINK - https://www.pepcoding.com/resources/online-java-foundation/binary-tree/diameter-of-binary-tree-official/ojquestion

// Sol-1 TC = O(n^2), SC = O(n)
// Sol-2 TC = O(n), SC = O(n)
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

int diameter1(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int ld = diameter1(node->left);
    int rd = diameter1(node->right);
    int lrd = height(node->left) + height(node->right) + 2;
    return max(lrd, max(ld, rd));
}

// pair<dia, height>
pair<int, int> diameter2(Node *node)
{
    pair<int, int> p;
    if (node == NULL)
    {
        p = {0, -1};
        return p;
    }

    pair<int, int> lp = diameter2(node->left);
    pair<int, int> rp = diameter2(node->right);
    int dia = max(lp.second + rp.second + 2, max(lp.first, rp.first));
    int hg = max(lp.second, rp.second) + 1;
    p = {dia, hg};
    return p;
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
    // cout << diameter1(root) << endl;
    cout << diameter2(root).first << endl;
    return 0;
}
