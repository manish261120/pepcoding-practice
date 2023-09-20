// LINK - https://www.pepcoding.com/resources/online-java-foundation/linked-lists/add-two-linkedlists-official/ojquestion

// Solution TC = O(n), SC = O(n)
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class linkedlist
{
private:
    int addTwoListsHelper(node *first, int pv1, node *second, int pv2, linkedlist *ans)
    {
        if (first == NULL && second == NULL)
        {
            return 0;
        }
        int carry, val;
        if (pv1 > pv2)
        {
            carry = addTwoListsHelper(first->next, --pv1, second, pv2, ans);
            val = carry + first->data;
        }
        else if (pv1 < pv2)
        {
            carry = addTwoListsHelper(first, pv1, second->next, --pv2, ans);
            val = carry + second->data;
        }
        else
        {
            carry = addTwoListsHelper(first->next, --pv1, second->next, --pv2, ans);
            val = carry + first->data + second->data;
        }

        ans->addFirst(val % 10);
        return val / 10;
    }

public:
    node *head, *tail;
    int size = 0;

public:
    linkedlist()
    {
        head = NULL;
        tail = NULL;
    }
    void addFirst(int val)
    {
        if (head == NULL)
        {
            addLast(val);
        }
        else
        {
            node *newnode = new node;
            newnode->data = val;
            newnode->next = head;
            head = newnode;
        }
    }

    void addLast(int n)
    {
        node *temp = new node();
        temp->data = n;
        temp->next = NULL;
        if (size)
        {
            tail->next = temp;
            tail = temp;
        }
        else
        {
            head = temp;
            tail = temp;
        }
        size++;
    }
    int getFirst()
    {
        return head->data;
    }
    void display()
    {
        for (node *tmp = head; tmp != NULL; tmp = tmp->next)
        {
            cout << tmp->data << " ";
        }
        cout << endl;
    }
    linkedlist addTwoLists(linkedlist a, linkedlist b)
    {
        linkedlist ans;
        int carry = addTwoListsHelper(a.head, a.size, b.head, b.size, &ans);
        if (carry)
        {
            ans.addFirst(carry);
        }

        return ans;
    }
};

int main()
{
    linkedlist l1, l2, res;
    int n1, n2, a, b;

    cin >> n1;
    for (int i = 0; i < n1; i++)
    {
        int val;
        cin >> val;
        l1.addLast(val);
    }

    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        int val;
        cin >> val;
        l2.addLast(val);
    }

    cin >> a >> b;
    res = res.addTwoLists(l1, l2);
    l1.display();
    l2.display();
    res.display();
    res.addFirst(a);
    res.addLast(b);
    res.display();

    return 0;
}