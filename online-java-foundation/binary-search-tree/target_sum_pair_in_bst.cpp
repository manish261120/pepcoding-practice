// LINK - https://www.pepcoding.com/resources/online-java-foundation/binary-search-tree/tsp-bst-official/ojquestion

#include <iostream>
#include <stack>
#include <utility>
#include <vector>
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

bool find(Node *node, int data)
{
    if (node == NULL)
    {
        return false;
    }

    if (data == node->data)
    {
        return true;
    }
    else if (data < node->data)
    {
        return find(node->left, data);
    }
    else
    {
        return find(node->right, data);
    }
}

Node *getNextFromNormalInorder(stack<pair<Node *, int>> &st)
{
    while (st.size())
    {
        pair<Node *, int> p = st.top();
        if (st.top().second == 0)
        {
            st.top().second++;
            if (st.top().first->left != NULL)
            {
                st.push({p.first->left, 0});
            }
        }
        else if (st.top().second == 1)
        {
            st.top().second++;
            if (st.top().first->right != NULL)
            {
                st.push({st.top().first->right, 0});
            }
            return p.first;
        }
        else
        {
            st.pop();
        }
    }
    return NULL;
}

Node *getNextFromReverseInorder(stack<pair<Node *, int>> &st)
{
    while (st.size())
    {
        pair<Node *, int> p = st.top();
        if (st.top().second == 0)
        {
            st.top().second++;
            if (st.top().first->right != NULL)
            {
                st.push({p.first->right, 0});
            }
        }
        else if (st.top().second == 1)
        {
            st.top().second++;
            if (st.top().first->left != NULL)
            {
                st.push({st.top().first->left, 0});
            }
            return p.first;
        }
        else
        {
            st.pop();
        }
    }
    return NULL;
}

// avg TC = O(nlogn), SC = O(logn) worst TC = O(n^2), SC = O(n)
void tsp1(Node *root, Node *node, int tar)
{
    if (node == NULL)
    {
        return;
    }
    tsp1(root, node->left, tar);
    if (node->data < tar - node->data && find(root, tar - node->data))
    {
        cout << node->data << " " << tar - node->data << endl;
    }
    tsp1(root, node->right, tar);
}

// avg TC = O(logn), SC = O(n) worst TC = O(n), SC = O(n)
void tsp2(Node *node, vector<int> &arr)
{
    if (node == NULL)
    {
        return;
    }
    tsp2(node->left, arr);
    arr.push_back(node->data);
    tsp2(node->right, arr);
}

// avg TC = O(n), SC = O(h) worst TC = O(n), SC = O(n)
void tsp3(Node *node, int tar)
{
    stack<pair<Node *, int>> ls;
    stack<pair<Node *, int>> rs;
    ls.push({node, 0});
    rs.push({node, 0});

    Node *left = getNextFromNormalInorder(ls);
    Node *right = getNextFromReverseInorder(rs);

    while (left->data < right->data)
    {
        if (left->data + right->data == tar)
        {
            cout << left->data << " " << right->data << endl;
            left = getNextFromNormalInorder(ls);
            right = getNextFromReverseInorder(rs);
        }
        else if (left->data + right->data > tar)
        {
            right = getNextFromReverseInorder(rs);
        }
        else if (left->data + right->data < tar)
        {
            left = getNextFromNormalInorder(ls);
        }
    }
}

int main()
{

    int n, k;
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
    cin >> k;

    Node *root = construct(arr, n);
    // tsp1(root, root, k);
    vector<int> vec;
    // tsp2(root, vec);
    int lo = 0, hi = vec.size() - 1;

    while (lo < hi)
    {
        if (vec[lo] + vec[hi] == k)
        {
            lo++;
            hi--;
        }
        else if (vec[lo] + vec[hi] > k)
        {
            hi--;
        }
        else if (vec[lo] + vec[hi] < k)
        {
            lo++;
        }
    }

    tsp3(root, k);
    return 0;
}
