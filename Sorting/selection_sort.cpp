#include<iostream>
#include<vector>
using namespace std;
// it select the minimums and place it on the first postion 
//get the minimum and swap it 
//the minimum is placed at the first location
void selection_sort(vector<int>&vec1)
{
    for (int i = 0; i <= vec1.size()-2; i++)
    {
        int min=i;
        for (int j = i; j <= vec1.size()-1; j++)
        {
            if(vec1[j]<vec1[min])
            {
                min=j;
            }
          
        }
        int temp=vec1[min];
        vec1[min]=vec1[i];
        vec1[i]=temp;
        
    }
    
}
void display(vector<int>vec1)
{
    for (int i = 0; i < vec1.size(); i++)
    {
        cout<<vec1[i]<<" ";
    }
    
}
int main()
{
    vector<int>vec1;
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
   
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin>>temp;
        vec1.push_back(temp);
    }
    selection_sort(vec1);
    display(vec1);
    

}