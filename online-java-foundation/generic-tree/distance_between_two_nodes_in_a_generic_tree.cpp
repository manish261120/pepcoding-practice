// LINK - https://www.pepcoding.com/resources/online-java-foundation/generic-tree/distance-between-nodes-official/ojquestion

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

int distanceBetweenNodes(Node *node, int data1, int data2)
{

    vector<int> a1 = nodeToRootPath(node, data1);
    vector<int> a2 = nodeToRootPath(node, data2);

    int i = a1.size() - 1;
    int j = a2.size() - 1;

    while (i >= 0 && j >= 0 && a1[i] == a2[j])
    {
        i--;
        j--;
    }

    return i + j + 2;
}

int main()
{

    int n, data1, data2;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> data1 >> data2;

    Node *root = construct(arr, n);
    int dist = distanceBetweenNodes(root, data1, data2);
    cout << dist << endl;

    return 0;
}
