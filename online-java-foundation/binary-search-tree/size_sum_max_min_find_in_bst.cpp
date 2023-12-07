// LINK - https://www.pepcoding.com/resources/online-java-foundation/binary-search-tree/size-sum-max-min-find-in-bst-official/ojquestion

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
    if (node == NULL)
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

// avg TC = O(logn), SC = O(logn) worst TC = O(n), SC = O(n)
int min(Node *node)
{
    if (node->left == NULL)
    {
        return node->data;
    }
    return min(node->left);
}

// avg TC = O(logn), SC = O(logn) worst TC = O(n), SC = O(n)
int max(Node *node)
{
    if (node->right == NULL)
    {
        return node->data;
    }
    return max(node->right);
}

// TC = O(n), SC = O(n)
int sum(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return sum(node->left) + sum(node->right) + node->data;
}

// TC = O(n), SC = O(n)
int size(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return size(node->left) + size(node->right) + 1;
}

// avg TC = O(logn), SC = O(logn) worst TC = O(n), SC = O(n)
bool find(Node *node, int data)
{
    if (node == NULL)
    {
        return false;
    }

    if (data == node->data)
    {
        return true;
    }
    else if (data < node->data)
    {
        return find(node->left, data);
    }
    else
    {
        return find(node->right, data);
    }
}

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        string st;
        cin >> st;
        if (st == "n")
        {
            arr[i] = -1;
        }
        else
        {
            arr[i] = stoi(st);
        }
    }
    int data;
    cin >> data;
    Node *root = construct(arr, n);
    cout << size(root) << endl;
    cout << sum(root) << endl;
    cout << max(root) << endl;
    cout << min(root) << endl;
    find(root, data) ? cout << "true" << endl : cout << "false" << endl;

    return 0;
}