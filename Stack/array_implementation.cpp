#include <iostream>
using namespace std;
//pre Conditions
//require an array
//require top variable which tracks the size of stack or elements in stack
//top must be initilized to -1

class stack
{
	public:
	int a[5];
	int t = -1;
    bool isFull(){
        if(t==4)return true;
        else return false;
    }
    bool isEmpty()
    {
        if(t==-1)return true;
        else return false;

    }
	void push()
	{
		if(isFull())
		{
			
			cout<<"Stack is full"<<endl;
		}
		else
		{
            int temp;
			cin>>temp;
			t++;
			a[t] = temp;
			cout<<"Element added successfully !"<<endl;
		}
	}
	void pop() {
    if (!isEmpty()) {
        cout << "Element popped: " << a[t] << endl; 
        t--;
    } else {
        cout << "Stack is empty, cannot pop!" << endl;
    }
}

	void view()
	{
		if(isEmpty())
		{
			cout<<"Stack is empty !";
		}
		else
		{
			cout<<"Top : "<<a[t]<<endl;
		}
	}
};
int main()
{
	stack s;
	int ch= -1;
	do
	{
	int c;
	cout<<"Enter"<<endl<<" 1.Push\n"<<" 2.Pop\n"<<" 3.Top"<<endl;
    cout<<"Enter Choice: ";
	cin>>c;
	switch(c)
	{
		case 1:
			s.push();
		break;
		case 2:
			s.pop();
		break;
		case 3:
			s.view();
		break;
		default:
			cout<<"Invalid Selection "<<endl;
	}
	cout<<"Enter 0 to contnue or 1 to exit !"<<endl;
	cin>>ch;
	} 
	while (ch == 0);
}