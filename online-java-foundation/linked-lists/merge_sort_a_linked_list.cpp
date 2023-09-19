// LINK - https://www.pepcoding.com/resources/online-java-foundation/linked-lists/mergesort-linkedlist-official/ojquestion

// Solution TC = O(nlogn), SC = O(n)
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
};

linkedlist mergeTwoSortedLists(linkedlist l1, linkedlist l2)
{
    linkedlist ans;
    node *nodel = l1.head;
    node *node2 = l2.head;
    while (nodel != NULL && node2 != NULL)
    {
        if (nodel->data <= node2->data)
        {
            ans.addLast(nodel->data);
            nodel = nodel->next;
        }
        else
        {
            ans.addLast(node2->data);
            node2 = node2->next;
        }
    }
    while (nodel != NULL)
    {
        ans.addLast(nodel->data);
        nodel = nodel->next;
    }
    while (node2 != NULL)
    {
        ans.addLast(node2->data);
        node2 = node2->next;
    }
    return ans;
}

node *getMid(node *head, node *tail)
{
    node *slow = head;
    node *fast = head;
    while (fast != tail && fast->next != tail)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

linkedlist mergeSort(node *head, node *tail)
{
    linkedlist ans;
    if (head == tail)
    {
        ans.addLast(head->data);
        return ans;
    }

    node *mid = getMid(head, tail);
    linkedlist left = mergeSort(head, mid);
    linkedlist right = mergeSort(mid->next, tail);
    ans = mergeTwoSortedLists(left, right);
    return ans;
}

linkedlist makeList()
{
    linkedlist l;
    int n1;
    cin >> n1;

    for (int i = 0; i < n1; i++)
    {
        int val;
        cin >> val;
        l.addLast(val);
    }
    return l;
}

int main()
{
    linkedlist l = makeList();

    linkedlist sorted = mergeSort(l.head, l.tail);

    cout << sorted.toString() << endl;
    cout << l.toString() << endl;

    return 0;
}