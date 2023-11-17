// LINK - https://www.pepcoding.com/resources/online-java-foundation/binary-tree/find-nodetorootpath-binary-tree-official/ojquestion

// TC = O(n), SC = O(n)
#include <iostream>
#include <stack>
#include <vector>
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

bool find(Node *node, int data)
{
    if (node->data == data)
    {
        return true;
    }
    else if (node->left && find(node->left, data))
    {
        return true;
    }
    else if (node->right && find(node->right, data))
    {
        return true;
    }
    return false;
}

vector<int> nodeToRootPath(Node *node, int data)
{
    vector<int> ans;
    if (node->data == data)
    {
        ans.push_back(node->data);
        return ans;
    }
    if (node->left)
    {
        ans = nodeToRootPath(node->left, data);
        if (ans.size())
        {
            ans.push_back(node->data);
            return ans;
        }
    }
    if (node->right)
    {
        ans = nodeToRootPath(node->right, data);
        if (ans.size())
        {
            ans.push_back(node->data);
            return ans;
        }
    }
    return ans;
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
    bool found = find(root, data);
    found == 1 ? cout << "true" << endl : cout << "false" << endl;
    vector<int> path = nodeToRootPath(root, data);

    cout << "[";
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];
        if (i != path.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}
