#include<iostream>
using namespace std;
//reque an array and front and rear variables which must be initilized to -1
// it perform three functions insert-->(enqueue) ,delete-->(dequeue) ,pop()
int q[3],f=-1,r=-1;

int insert(){
	if(r==2)
		cout<<"Queue is full"<<endl;
	else{
		r++;
		cout<<"Enter a number: ";
		cin>>q[r];
	}
}

int remove(){
	if(r==f)
		cout<<"Queue is empty"<<endl;
	else{
		f++;
		cout<<q[f];
		
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

//limitations 
//it has a limitation of size
//it has a big limitation that onece it full then the deletion is performed but deletion move the front towards rear that is why you can not insert any more element and even the queue is empty 