// LINK - https://www.pepcoding.com/resources/online-java-foundation/linked-lists/remove-last-in-linked-list/ojquestion

// TC = O(n), SC = O(1)
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class linked_list
{
public:
    node *head, *tail;
    int size = 0;

public:
    linked_list()
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
    void removeLast()
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
            node *temp = head;
            for (node *tmp = head; tmp->next->next != NULL; tmp = tmp->next)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            tail = temp;
            size--;
        }
    }
    int getSize()
    {
        return size;
    }
    int getFirst()
    {
        if (!head)
        {
            return -1;
        }

        return head->data;
    }
    int getLast()
    {
        if (!tail)
        {
            return -1;
        }

        return tail->data;
    }
    int getAt(int p)
    {
        node *temp = head;
        for (int i = 0; i < p; i++)
        {
            temp = temp->next;
        }

        return temp->data;
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
            size++;
        }
    }
    void addAt(int pos, int data)
    {
        int sz = getSize();
        if (pos < 0 || pos > sz)
        {
            cout << "Invalid arguments" << endl;
        }
        else if (pos == 0)
        {
            addFirst(data);
        }
        else if (pos == size)
        {
            addLast(data);
        }
        else
        {
            node *temp = head;
            for (int i = 1; i < pos; i++)
            {
                temp = temp->next;
            }
            node *newNode = new node;
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
            size++;
        }
    }
};

int main()
{
    linked_list l1;
    string s;
    cin >> s;
    while (s != "quit")
    {
        if (s == "addLast")
        {
            int data;
            cin >> data;
            l1.addLast(data);
        }
        else if (s == "addFirst")
        {
            int data;
            cin >> data;
            l1.addFirst(data);
        }
        else if (s == "getFirst")
        {
            int val = l1.getFirst();
            if (val == -1)
            {
                cout << "List is empty" << endl;
            }
            else
            {
                cout << val << endl;
            }
        }
        else if (s == "getLast")
        {
            int val = l1.getLast();
            if (val == -1)
            {
                cout << "List is empty" << endl;
            }
            else
            {
                cout << val << endl;
            }
        }
        else if (s == "removeFirst")
        {
            l1.removeFirst();
        }
        else if (s == "removeLast")
        {
            l1.removeLast();
        }
        else if (s == "addAt")
        {
            int val, i;
            cin >> i >> val;
            l1.addAt(i, val);
        }
        else if (s == "getAt")
        {
            int i;
            cin >> i;
            if (i >= l1.getSize())
            {
                cout << "Invalid arguments" << endl;
            }
            else
            {
                cout << l1.getAt(i) << endl;
            }
        }
        else if (s == "display")
        {
            l1.display();
        }
        else if (s == "size")
        {
            cout << l1.getSize() << endl;
        }
        cin >> s;
    }
}