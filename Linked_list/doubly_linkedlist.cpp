#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* prev;
Node* next;
public:
Node(int data)
{
    this->data=data;
    prev=NULL;
    next=NULL;
}
};
class d_list{
    Node* head;
    Node* tail;
    public:
    d_list(){
        head=NULL;
        tail=NULL;
    }
    void insertAtStart(int val)
    {
        Node* new_Node=new Node(val);
        if(head==NULL)
        {
            head=new_Node;
            tail=new_Node;
            return;
        }
        new_Node->next=head;
        head->prev=new_Node;
        head=new_Node;
        return;
    }
    void display()
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void insertAtEnd(int val)
    {
        Node* newNode=new Node(val);
        if(tail==NULL)
        {
            head=newNode;
            tail=newNode;
            return;
        }
        else
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
        return;
    }
    void insertAtPostion(int val,int k)
    {
        Node*newNode=new Node(val); 
        Node* temp=head;
        int count=0;
        while(count<k-1)
        {
            temp=temp->next;
            count++;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        newNode->prev=temp;
        newNode->next->prev=newNode;
        return;

    }
    void deleteAtHead()
    {
        if(head==NULL)
        {
            return;
        }
        Node*temp=head;
        head=head->next;
        if(head==NULL)
        {
            tail=NULL;
        
        }
        else{
            head->prev=NULL;
        }
        free(temp);
        return;
    }
    
};
int main()
{
   d_list l1;
   l1.insertAtStart(4); 
   l1.insertAtStart(3); 
   l1.insertAtStart(2); 
   l1.insertAtStart(1); 
   l1.insertAtStart(0); 
   l1.insertAtStart(-1); 
   l1.insertAtEnd(5);
   l1.insertAtEnd(6);
   l1.insertAtEnd(7);
   l1.insertAtEnd(8);
   l1.display();
   l1.insertAtPostion(14,5);
   l1.display();
   l1.deleteAtHead();
   l1.display();

   
} 


