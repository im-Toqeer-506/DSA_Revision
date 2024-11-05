#include<iostream>
#include<vector>
using namespace std;
// Binary search is very efficient algorithem that is particularly use to search an element from the sorted array .The binary search algorithem each time divides the array into 2 parts that is why it called the divide and conquor approch .The array of hundered element whould be sorted in 4 passes .Done
int Binary_Search(vector<int>&vec1,int ele){
if(vec1.size()<0)return -1;
int l=0,h=vec1.size();
while(l<=h){
int mid=(l+h)/2;
if(ele>mid){
    l=mid+1;
}
else if(ele<mid)
{
    h=mid-1;
}
else return mid;
}
return -1;

}
int main()
{
    vector<int>vec1;
    int n;
    cout<<"Enter the size of the Vector: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {    
        int temp;
        cin>>temp;
        vec1.push_back(temp);
    } 
    int p=Binary_Search(vec1,5);
    if(p)
    {
        cout<<"Element is found at the Postion: "<<p;
    }
    else
    {
        cout<<"Element Not Found!";
    }
}