#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *link;
    Node(int val)
    {
        data = val;
        link = NULL;
    }
    Node(int val, Node *next)
    {
        data = val;
        link = next;
    }
    ~Node()
    {
        cout << "~Node()\n";
        if (link != NULL)
        {
            delete link;
            link = NULL;
        }
    }
};
class list
{
private:
    Node *start;
    Node *end;
    int size;

public:
    list()
    {
        start = NULL;
        end = NULL;
        size = 0;
    }
    bool isEmpty()
    {
        return start == NULL;
    }
    void insertAthead(int val)
    {
        Node *newNode = new Node(val); // dynamic
        size++;
        if (isEmpty())
        { // Same Here!
            // start=newNode;
            // end=start;
            start = end = newNode;
        }
        else
        {

            newNode->link = start;
            start = newNode;
        }
    }
    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);
        size++;
        if (isEmpty())
        {
            start = end = newNode;
        }
        else
        {
            end->link = newNode;
            end = newNode;
        }
    }
    void print()
    {
        cout << "The total Node: " << size << endl;
        Node *temp = start;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->link;
        }
    }
    void insertAtPosition(int val, int pos)
    {
        // this will work according to position
        Node *temp = start;
        while (temp != NULL)
        {
            if (temp->data == pos)
                break;
            temp = temp->link;
        }

        temp->link = new Node(val, temp->link);
        size++;
    }
    void pop_front()
    {
        Node *temp = start;
        if (isEmpty())
        {
            cout << "Linked List is empty() \n";
        }
        size--;
        start = start->link;
        temp->link = NULL;
        delete temp;
    }
    void Pop_Back()
    {
        Node *temp = start;
        while (temp->link->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = NULL;
        delete end;
        end = temp;
        size--;
    }
    int SearchIter(int val)
    {
        Node *temp = start;
        int idx = 0;
        while (temp != NULL)
        {
            if (temp->data == val)
                return idx;
            else
                temp = temp->link;
            idx++;
        }
        return -1;
    }
    int Helper(Node *temp, int key)
    {
        if (temp == NULL)
            return -1;
        if (temp->data == key)
            return 0;
        int idx = Helper(temp->link, key);
        if (idx == -1)
            return -1;
        return idx + 1;
    }
    int RecSearch(int key)
    {
        return Helper(start, key);
    }
    void insertAtIndex(int val, int pos)
    {
        // this work according to the index
        Node *newNode = new Node(val);
        Node *temp = start;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Invaild Position! ";
            }
            temp = temp->link;
        }
        temp->link = newNode->link;
        temp->link = newNode;
        size++;
    }
    ~list()
    {
        cout << "~List()\n";
        if (start != NULL)
        {
            delete start;
            start = NULL;
        }
    }
};
int main()
{
    list l;
    l.insertAthead(8);
    l.insertAthead(7);
    l.insertAthead(6);
    l.insertAthead(5);
    l.insertAtTail(9);
    l.insertAtTail(10);
    l.insertAtTail(11);
    l.insertAtPosition(200, 7);
    l.print();
    l.pop_front();
    l.pop_front();
    l.print();
    l.Pop_Back();
    l.Pop_Back();
    l.print();
    // int find = l.SearchIter(200);
    int find = l.RecSearch(200);

    if (find)
        cout << "\nNode found at index: " << find << endl;
    else
        cout << "Node does`nt Found!" << endl;

    cout << endl;
}