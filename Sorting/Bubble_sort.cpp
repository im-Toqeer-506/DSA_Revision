#include <iostream>
using namespace std;
#include <vector>
// it pushaes the maximum to the left
// maximum element comes to the surface like a bubble
// it works with the adjacent swaps
void Bubble_Sort(vector<int> &vec1)
{
    for (int i = vec1.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (vec1[j] > vec1[j + 1])
            {
                int temp = vec1[j + 1];
                vec1[j + 1] = vec1[j];
                vec1[j] = temp;
            }
        }
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
    vector<int> vec1;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        vec1.push_back(temp);
    }
   Bubble_Sort(vec1);
    display(vec1);
}