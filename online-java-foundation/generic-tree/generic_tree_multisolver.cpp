// LINK - https://www.pepcoding.com/resources/online-java-foundation/generic-tree/size-generic-tree-official/ojquestion

// TC = O(n), SC = O(n)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int size = 0;
int mingt = INT16_MAX;
int maxgt = INT16_MIN;
int height = 0;

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
    cout << s << endl;
    for (auto &&child : node->children)
    {
        display(child);
    }
}

void multiSolver(Node *node, int depth)
{
    size++;
    mingt = min(mingt, node->data);
    maxgt = max(maxgt, node->data);
    height = max(height, depth);

    for (auto &&child : node->children)
    {
        multiSolver(child, depth + 1);
    }
}

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *root = construct(arr, n);
    multiSolver(root, height);
    cout << "Size=" << size << endl;
    cout << "Min=" << mingt << endl;
    cout << "Max=" << maxgt << endl;
    cout << "Height=" << height << endl;
    return 0;
}
