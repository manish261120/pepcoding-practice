// LINK - https://www.pepcoding.com/resources/online-java-foundation/linked-lists/is-linkedlist-palindromic-official/ojquestion

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
    bool isPalindromeHelper(node *right)
    {
        if (right == NULL)
        {
            return true;
        }
        bool res = isPalindromeHelper(right->next);

        if (res == false)
        {
            return false;
        }
        else if (right->data != left->data)
        {
            return false;
        }
        else
        {
            left = left->next;
            return true;
        }
    }

public:
    node *head, *tail, *left;
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
    bool IsPalindrome()
    {
        left = head;
        return isPalindromeHelper(head);
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

    cout << l1.IsPalindrome() << endl;

    return 0;
}