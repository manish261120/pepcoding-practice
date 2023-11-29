// LINK - https://www.pepcoding.com/resources/online-java-foundation/binary-tree/print-single-child-nodes-official/ojquestion

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

void printSingleChildNodes(Node *node, Node *parent)
{
    if (node == NULL)
    {
        return;
    }

    if (parent && parent->left == node && parent->right == NULL)
    {
        cout << node->data << endl;
    }
    else if (parent && parent->left == NULL && parent->right == node)
    {
        cout << node->data << endl;
    }

    printSingleChildNodes(node->left, node);
    printSingleChildNodes(node->right, node);
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
    printSingleChildNodes(root, NULL);
    return 0;
}
