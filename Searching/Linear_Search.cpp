#include<iostream>
#include<vector>
using namespace std;
void binary_Seacrh(vector<int>&vec,int ele){
    for (int i = 0; i < vec.size(); i++)
    {
        if(vec[i]==ele)
        {
        cout<<"Position found: "<<i+1;
           return;
        }
    }
    cout<<"Element Not Found!"<<endl;
    
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
    binary_Seacrh(vec1,8);

}