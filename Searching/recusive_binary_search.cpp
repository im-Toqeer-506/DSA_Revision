#include<iostream>
#include<vector>
using namespace std;
// Binary search is very efficient algorithem that is particularly use to search an element from the sorted array .The binary search algorithem each time divides the array into 2 parts that is why it called the divide and conquor approch .The array of hundered element whould be sorted in 4 passes .Done
int Helper(vector<int>vec, int left, int right, int target)
{
    if(left> right)return -1;

    int mid = (left + right) / 2;
  
    if (vec[mid] == target)
        return mid;
    else if (vec[mid] < target)
        return Helper(vec, mid + 1, right, target);//right half
    else
        return Helper(vec, left, mid - 1, target);//left half
}
int B_S(vector<int>vec, int target) {
    return Helper(vec, 0, vec.size()-1, target);
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
    int p=B_S(vec1 ,7);
    if(p)
    {
        cout<<"Element is found at the Postion: "<<p;
    }
    else
    {
        cout<<"Element Not Found!";
    }
}