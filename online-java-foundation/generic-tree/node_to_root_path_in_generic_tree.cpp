// LINK - https://www.pepcoding.com/resources/online-java-foundation/generic-tree/node-to-root-path-official/ojquestion

// TC = O(n), SC = O(n)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    vector<Node *> children;
};

Node *construct(int arr[], int n)
{
    Node *root;
    stack<Node *> stack;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
        {
            stack.pop();
        }
        else
        {
            Node *node = new Node();
            node->data = arr[i];

            if (stack.size())
            {
                Node *parent = stack.top();
                parent->children.push_back(node);
            }
            else
            {
                root = node;
            }

            stack.push(node);
        }
    }
    return root;
}

int display(Node *node)
{
    string s = to_string(node->data) + " -> ";
    for (auto &&child : node->children)
    {
        s += to_string(child->data) + ", ";
    }
    cout << s << "." << endl;
    for (auto &&child : node->children)
    {
        display(child);
    }
}

vector<int> nodeToRootPath(Node *node, int data)
{
    vector<int> ans;
    if (node->data == data)
    {
        ans.push_back(node->data);
        return ans;
    }

    for (auto &&child : node->children)
    {
        ans = nodeToRootPath(child, data);
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
        cin >> arr[i];
    }
    cin >> data;

    Node *root = construct(arr, n);

    vector<int> ans = nodeToRootPath(root, data);

    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i != ans.size() - 1)
            cout << ", ";
    }
    cout << "]";

    return 0;
}
