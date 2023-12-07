// LINK - https://www.pepcoding.com/resources/online-java-foundation/binary-search-tree/remove-node-in-bst-official/ojquestion

// avg TC = O(logn), SC = O(logn) worst TC = O(n), SC = O(n)
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

void display(Node *node)
{
    if (!node)
    {
        return;
    }
    string st = "";
    st += node->left ? to_string(node->left->data) : ".";
    st += " <- " + to_string(node->data) + " -> ";
    st += node->right ? to_string(node->right->data) : ".";
    cout << st << endl;

    display(node->left);
    display(node->right);
}

int max(Node *node)
{
    if (node->right == NULL)
    {
        return node->data;
    }
    return max(node->right);
}

Node *remove(Node *node, int val)
{
    if (node == NULL)
    {
        return NULL;
    }

    if (val < node->data)
    {
        node->left = remove(node->left, val);
    }
    else if (val > node->data)
    {
        node->right = remove(node->right, val);
    }
    else
    {
        if (node->left && node->right)
        {
            int lmax = max(node);
            node->data = lmax;
            node->left = remove(node->left, lmax);
        }
        else if (node->left)
        {
            return node->left;
        }
        else if (node->right)
        {
            return node->right;
        }
        else
        {
            node = NULL;
        }
    }
    return node;
}

int main()
{

    int n, data;
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
    cin >> data;

    Node *root = construct(arr, n);
    root = remove(root, data);
    display(root);

    return 0;
}
