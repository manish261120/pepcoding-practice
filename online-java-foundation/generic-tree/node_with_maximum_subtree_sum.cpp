// LINK - https://www.pepcoding.com/resources/online-java-foundation/generic-tree/node-with-maximum-subtree-sum-official/ojquestion

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

int max_subtree_sum = INT16_MIN;
int max_subtree_sum_node = 0;

int maxSubtreeSum(Node *node)
{
    int subtree_sum = 0;
    for (auto &&child : node->children)
    {
        subtree_sum += maxSubtreeSum(child);
    }
    subtree_sum += node->data;
    if (subtree_sum > max_subtree_sum)
    {
        max_subtree_sum = subtree_sum;
        max_subtree_sum_node = node->data;
    }
    return subtree_sum;
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
    maxSubtreeSum(root);
    cout << max_subtree_sum_node << "@" << max_subtree_sum << endl;
    return 0;
}
