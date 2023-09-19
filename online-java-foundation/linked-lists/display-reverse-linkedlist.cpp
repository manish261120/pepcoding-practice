// LINK - https://www.pepcoding.com/resources/online-java-foundation/linked-lists/display-reverse-linkedlist-official/ojquestion

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
    void displayReverseRecursiveHelper(node *node)
    {
        if (node == NULL)
        {
            return;
        }
        displayReverseRecursiveHelper(node->next);
        cout << node->data;
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
    void displayReverseRecursive()
    {
        displayReverseRecursiveHelper(head);
        cout << endl;
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
    l1.displayReverseRecursive();
    l1.addFirst(a);
    l1.addLast(b);
    l1.display();

    return 0;
}