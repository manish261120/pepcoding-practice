// LINK - https://www.pepcoding.com/resources/online-java-foundation/linked-lists/odd-even-linked-list-official/ojquestion

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
    void oddEven()
    {
        linkedlist odd;
        linkedlist even;

        while (this->size)
        {
            int val = this->getFirst();
            this->removeFirst();
            if (val % 2)
            {
                odd.addLast(val);
            }
            else
            {
                even.addLast(val);
            }
        }
        if (odd.size && even.size)
        {

            this->head = odd.head;
            odd.tail->next = even.head;
            this->tail = even.tail;
        }
        else if (odd.size)
        {
            this->head = odd.head;
            this->tail = odd.tail;
        }
        else
        {

            this->head = even.head;
            this->tail = even.tail;
        }

        this->size = odd.size + even.size;
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
    l1.oddEven();
    l1.display();
    l1.addFirst(a);
    l1.addLast(b);
    l1.display();

    return 0;
}