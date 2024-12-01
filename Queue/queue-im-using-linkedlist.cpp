#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int new_data)
    {
        data = new_data;
        next = nullptr;
    }
};
class Queue
{

    Node *front, *rear;

public:
    Queue() {
        front = rear = nullptr; 
         }

    bool isEmpty()
    {

        if (front == nullptr)
        {
            return true;
        }
        return false;
    }

    void enqueue(int new_data)
    {

        Node *new_node = new Node(new_data);

        if (isEmpty())
        {
            front = rear = new_node;
            return;
        }

        rear->next = new_node;
        rear = new_node;
    }

    void dequeue()
    {

        if (isEmpty())
        {
            cout << "Queue Underflow\n";
            return;
        }

        Node *temp = front;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }

    int getFront()
    {

        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return 0;
        }
        return front->data;
    }

    int getRear()
    {

        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return 0;
        }

        return rear->data;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);

    cout << "Queue Front: " << q.getFront() << endl;
    cout << "Queue Rear: " << q.getRear() << endl;

    q.dequeue();
    q.dequeue();

    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.dequeue();

    cout << "Queue Front: " << q.getFront() << endl;
    cout << "Queue Rear: " << q.getRear() << endl
         << endl;

    return 0;
}