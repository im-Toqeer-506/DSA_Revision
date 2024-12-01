#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data; // Correctly assign to the member variable
        next = nullptr;
    }
};

class Stack
{
    Node *head;

public:
    Stack() { 
        head = nullptr;
    }
    bool isEmpty()
    {
        return head == nullptr;
    }
    void push(int data)
    {
        Node *new_node = new Node(data);

        if (!new_node)
        {
            cout << "\nStack Overflow";
            return;
        }

        new_node->next = head;
        head = new_node;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "\nStack Underflow" << endl;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    int peek()
    {
        if (!isEmpty())
            return head->data;
        else
        {
            cout << "\nStack is empty";
            return 0;
        }
    }
};

int main()
{
    Stack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    cout << "Top element is " << st.peek() << " " << endl;
    cout << "Removing two elements..." << endl;
    st.pop();
    st.pop();
    cout << "Top element is " << st.peek() << " " << endl;

    return 0;
}
