// LINK - https://www.pepcoding.com/resources/online-java-foundation/linked-lists/intersection-of-linked-lists-official/ojquestion

// Solution TC = O(n), SC = O(1)
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
    node *getNodeAt(int p)
    {
        node *temp = head;
        for (int i = 0; i < p; i++)
        {
            temp = temp->next;
        }
        cout << temp->data << endl;
        return temp;
    }
    void display()
    {
        for (node *tmp = head; tmp != NULL; tmp = tmp->next)
        {
            cout << tmp->data << " ";
        }
        cout << endl;
    }
};

int findIntersection(linkedlist one, linkedlist two)
{
    node *first = one.head;
    node *second = two.head;
    int size1 = one.size;
    int size2 = two.size;

    while (first != second)
    {
        if (size1 > size2)
        {
            first = first->next;
            size1--;
        }
        else if (size1 < size2)
        {
            second = second->next;
            size2--;
        }
        else
        {
            first = first->next;
            second = second->next;
            size1--;
            size2--;
        }
    }
    return first->data;
}

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
    if (a == 1)
    {
        node *n = l1.getNodeAt(b);

        if (l2.size > 0)
        {
            l2.tail->next = n;
        }
        else
        {
            l2.head = n;
        }

        l2.tail = l1.tail;
        l2.size += l1.size - b;
    }
    else
    {
        node *n = l2.getNodeAt(b);

        if (l1.size > 0)
        {
            l1.tail->next = n;
        }
        else
        {
            l1.head = n;
        }

        l1.tail = l2.tail;
        l1.size += l2.size - b;
    }

    int s = findIntersection(l1, l2);
    cout << s << endl;
    return 0;
}