// LINK - https://www.pepcoding.com/resources/online-java-foundation/binary-search-tree/pir-bst-official/ojquestion

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

void pir(Node *node, int d1, int d2)
{
    if (node == NULL)
    {
        return;
    }
    if (node->data > d1 && node->data > d2)
    {
        pir(node->left, d1, d2);
    }
    else if (node->data < d1 && node->data < d2)
    {
        pir(node->right, d1, d2);
    }
    else
    {
        pir(node->left, d1, d2);
        cout << node->data << endl;
        pir(node->right, d1, d2);
    }
}

int main()
{

    int n, a, b;
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
    cin >> a >> b;

    Node *root = construct(arr, n);
    pir(root, a, b);

    return 0;
}
