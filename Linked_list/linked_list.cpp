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
        {
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
    void  print()
    {
        cout<<"The total Node: "<<size<<endl;
        Node* temp=start;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->link;
        }

    }
    void insertAtPosition(int val,int pos)
    {
        // this will work according to position
        Node* temp=start;
        while(temp!=NULL)
        {
            if(temp->data==pos)break;
            temp=temp->link;
        }

      temp->link=new Node(val,temp->link);
      size++;


    }

    void insertAtIndex(int val,int pos)
    {
        // this work according to the index
        Node* newNode=new Node(val);
        Node* temp=start;
      for (int i = 0; i < pos-1; i++)
      {
        if(temp==NULL)
        {
            cout<<"Invaild Position! ";
        }
        temp=temp->link;
      }
      temp->link=newNode->link;
      temp->link=newNode;
      size++;
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
    l.insertAtPosition(200,7);
    l.print();
}