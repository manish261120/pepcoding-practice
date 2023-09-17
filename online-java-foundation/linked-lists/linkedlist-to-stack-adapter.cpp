// LINK - https://www.pepcoding.com/resources/online-java-foundation/linked-lists/linkedlist-to-stack-adapter-official/ojquestion

// Solution TC = O(1), SC = O(1)
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

private:
    node *getNodeAt(int idx)
    {
        node *temp = head;
        for (int i = 0; i < idx; i++)
        {
            temp = temp->next;
        }

        return temp;
    }

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
        else if (pos == sz)
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
    void reverseDi()
    {
        int left = 0, right = size - 1;
        while (left < right)
        {
            node *leftNode = getNodeAt(left);
            node *rightNode = getNodeAt(right);
            int data = leftNode->data;
            leftNode->data = rightNode->data;
            rightNode->data = data;
            left++;
            right--;
        }
    }
    void reversePi()
    {
        node *pre = NULL;
        node *cur = head;
        while (cur != NULL)
        {
            node *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        node *tmp = head;
        head = tail;
        tail = tmp;
    }
};

class LLToStackAdapter
{
public:
    linked_list l1;

    int size1()
    {
        return l1.getSize();
    }
    void push(int val)
    {
        l1.addFirst(val);
    }
    int pop()
    {
        if (!size1())
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        int data = l1.getFirst();
        l1.removeFirst();
        return data;
    }
    int top()
    {
        if (!size1())
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return l1.getFirst();
    }
};
int main()
{
    LLToStackAdapter l1;
    string s;
    cin >> s;
    while (s != "quit")
    {
        if (s == "push")
        {
            int val;
            cin >> val;
            l1.push(val);
        }
        else if (s == "pop")
        {
            int val = l1.pop();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if (s == "top")
        {
            int val = l1.top();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if (s == "size")
        {
            cout << l1.size1() << endl;
        }
        cin >> s;
    }
}