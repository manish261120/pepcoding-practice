// LINK - https://www.pepcoding.com/resources/online-java-foundation/binary-tree/binary-tree-path-to-leaves-from-root-official/ojquestion

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

void pathToLeafFromRoot(Node *node, string path, int sum, int lo, int hi)
{
    if (node == NULL)
    {
        return;
    }
    sum += node->data;
    path += to_string(node->data);
    if (node->left == NULL && node->right == NULL)
    {
        if (sum >= lo && sum <= hi)
        {
            cout << path << endl;
        }
        return;
    }

    pathToLeafFromRoot(node->left, path + " ", sum, lo, hi);
    pathToLeafFromRoot(node->right, path + " ", sum, lo, hi);
}

int main()
{

    int n, lo, hi;
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
    cin >> lo >> hi;

    Node *root = construct(arr, n);
    pathToLeafFromRoot(root, "", 0, lo, hi);
    return 0;
}
