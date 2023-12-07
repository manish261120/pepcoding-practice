// LINK - https://www.pepcoding.com/resources/online-java-foundation/binary-search-tree/bst-constructor/video

// TC = O(n), SC = O(logn)
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

Node *construct(int arr[], int n, int lo, int hi)
{
    if (lo > hi)
    {
        return NULL;
    }

    int mid = (lo + hi) / 2;
    Node *node = new Node;
    node->data = arr[mid];

    node->left = construct(arr, n, lo, mid - 1);
    node->right = construct(arr, n, mid + 1, hi);

    return node;
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

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> arr[i];
    }
    Node *root = construct(arr, n, 0, n - 1);
    display(root);
    return 0;
}