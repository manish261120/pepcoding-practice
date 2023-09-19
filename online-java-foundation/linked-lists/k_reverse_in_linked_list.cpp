// LINK - https://www.pepcoding.com/resources/online-java-foundation/linked-lists/kreverse-linkedlist-official/ojquestion

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
    void kReverse(int k)
    {
        linkedlist l;
        while (this->size / k >= 1)
        {
            linkedlist ll;
            for (int i = 0; i < k; i++)
            {
                int val = this->getFirst();
                this->removeFirst();
                ll.addFirst(val);
            }
            if (!l.size)
            {
                l.head = ll.head;
                l.tail = ll.tail;
                l.size = ll.size;
            }
            else
            {
                l.tail->next = ll.head;
                l.tail = ll.tail;
                l.size += ll.size;
            }
        }

        if (this->size)
        {
            l.tail->next = this->head;
            l.size += this->size;
        }
        this->head = l.head;
        this->tail = l.tail;
        this->size = l.size;
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

    int k, a, b;
    cin >> k >> a >> b;

    l1.display();
    l1.kReverse(k);
    l1.display();
    l1.addFirst(a);
    l1.addLast(b);
    l1.display();

    return 0;
}