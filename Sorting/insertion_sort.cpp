#include <iostream>
#include <vector>
using namespace std;
void Insertion_sort(vector<int> &vec1)
{
    for (int i = 0; i < vec1.size(); i++)
    {
        int j = i;
        while (j > 0 && vec1[j - 1] > vec1[j])
        {
            //shifting has same code as swap 
            int temp = vec1[j];
            vec1[j] = vec1[j - 1];
            vec1[j - 1] = temp;
            j--;
        }
    }
}
void display(vector<int> vec1)
{
    for (int i = 0; i < vec1.size(); i++)
    {
        cout << vec1[i] << " ";
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
    Insertion_sort(vec1);
    display(vec1);
}