#include<iostream>
using namespace std;
// preconditions
// the circular queue can be implemented using the is_array
// it require an array
//the front and rear variables must be initilezed to zero and an extra variable p 
//circular queue is implemented using the concept of moduls operator 
//in the circular queue if once fulled then it can dequeue and then anelement can easily be inserted in the reaming space 
int cq[4],f=0,r=0,n=4,p;

void insert(){
	p=r;
	r=(r+1)%n;
	if(r==f)
		cout<<"Queue is full"<<endl;
	else{
		cout<<"Enter a number: ";
		cin>>cq[r];
	}
}
void remove(){
	if(f==r)
		cout<<"Queue is empty"<<endl;
	else{
		f=(f+1)%n;
		cout<<cq[f];		
	}
}
int main(){
	int ch;
	do{
		cout<<"Choose an option:"<<endl;
		cout<<"1.insert"<<endl;
		cout<<"2.delete"<<endl;
		cout<<"3.exit"<<endl;
		cin>>ch;		
		switch(ch){
			case 1:
				insert();
				break;
			case 2:
				remove();
				break;
			case 3: 
				break;
			default:
				cout<<"Invalid input:"<<endl;			
		}			
	}while(ch!=3);
	return 0;
}