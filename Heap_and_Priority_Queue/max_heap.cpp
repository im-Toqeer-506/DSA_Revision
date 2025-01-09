#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int>PQ;
    PQ.push(10);
    PQ.push(11);
    PQ.push(56);
    PQ.push(23);
    PQ.push(5);
    PQ.push(68);
    PQ.push(55);
    PQ.push(1);

    cout<<"TOP: "<<PQ.top()<<" ";
    PQ.pop();
    cout<<"TOP: "<<PQ.top()<<" ";
    PQ.pop();
    while (!PQ.empty())
    {
        cout<<PQ.top()<<" ";
        PQ.pop();
    }
    
}