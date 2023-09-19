// LINK - https://www.pepcoding.com/resources/online-java-foundation/linked-lists/merge-two-sorted-linked-lists-official/ojquestion

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
public:
    node *head, *tail;
    int size = 0;

public:
    linkedlist()
    {
        head = NULL;
        tail = NULL;
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
    void display()
    {
        for (node *tmp = head; tmp != NULL; tmp = tmp->next)
        {
            cout << tmp->data << " ";
        }
        cout << endl;
    }
    string toString()
    {
        node *curr = head;
        string sb = "";

        while (curr != NULL)
        {
            sb += to_string(curr->data);
            if (curr->next != NULL)
                sb += " ";
            curr = curr->next;
        }
        return sb;
    }

    void mergeTwoSortedLists(linkedlist l1, linkedlist l2)
    {
        node *nodel = l1.head;
        node *node2 = l2.head;
        while (nodel != NULL && node2 != NULL)
        {
            if (nodel->data <= node2->data)
            {
                addLast(nodel->data);
                nodel = nodel->next;
            }
            else
            {
                addLast(node2->data);
                node2 = node2->next;
            }
        }
        while (nodel != NULL)
        {
            addLast(nodel->data);
            nodel = nodel->next;
        }
        while (node2 != NULL)
        {
            addLast(node2->data);
            node2 = node2->next;
        }
    }
};

int main()
{
    linkedlist l1;
    linkedlist l2;

    int n1;
    cin >> n1;

    for (int i = 0; i < n1; i++)
    {
        int val;
        cin >> val;
        l1.addLast(val);
    }

    int n2;
    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        int val;
        cin >> val;
        l2.addLast(val);
    }

    linkedlist merged;
    merged.mergeTwoSortedLists(l1, l2);

    cout << merged.toString() << endl;
    cout << l1.toString() << endl;
    cout << l2.toString() << endl;

    return 0;
}