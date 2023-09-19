// LINK - https://www.pepcoding.com/resources/online-java-foundation/linked-lists/reverse-linkedlist-pr-official/ojquestion

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
    void displayReversePointerRecHelper(node *node1)
    {
        if (node1 == NULL)
        {
            return;
        }

        displayReversePointerRecHelper(node1->next);

        node *temp = node1->next;
        if (node1 != tail)
        {
            node1->next->next = node1;
        }
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
    void removeFirst()
    {
        if (!size)
        {
            cout << "List is empty" << endl;
        }
        else if (size == 1)
        {
            head = NULL;
            tail = NULL;
            size--;
        }
        else
        {
            head = head->next;
            size--;
        }
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
    void displayReversePointerRec()
    {
        displayReversePointerRecHelper(head);
        head->next = NULL;
        node *temp = head;
        head = tail;
        tail = temp;
    }
};

int main()
{
    linkedlist l1;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        l1.addLast(val);
    }

    int a, b;
    cin >> a >> b;

    l1.display();
    l1.displayReversePointerRec();
    l1.addLast(a);
    l1.addFirst(b);
    l1.display();

    return 0;
}