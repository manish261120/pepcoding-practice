// LINK - https://www.pepcoding.com/resources/online-java-foundation/generic-tree/iterative-preorder-postorder-generic-tree-official/ojquestion

// TC = O(n), SC = O(n)
#include <iostream>
#include <vector>
#include <stack>
#include <utility>
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

void iterativePreAndPostOrder(Node *node)
{
    string pre_order = "";
    string post_order = "";
    stack<pair<Node *, int>> stack;
    stack.push({node, -1});

    while (stack.size())
    {
        pair<Node *, int> pair = stack.top();
        if (pair.second == -1)
        {
            pre_order += to_string(pair.first->data) + " ";
            stack.top().second++;
        }
        else if (pair.second < pair.first->children.size())
        {
            stack.top().second++;
            stack.push({pair.first->children[pair.second], -1});
        }
        else if (pair.second == pair.first->children.size())
        {
            post_order += to_string(pair.first->data) + " ";
            stack.pop();
        }
    }
    cout << pre_order << endl;
    cout << post_order << endl;
}

int main()
{

    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *root = construct(arr, n);
    iterativePreAndPostOrder(root);
    return 0;
}
