#include <iostream>
using namespace std;
class Heap
{
public:
    int arr[100];
    int size;
    Heap(){
        size=0;
        arr[0]=-1;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
           cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;
        // swaping the parent element to below if the parent value is lesser then the child node
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void Delete()
    {
        if (size == 0)
        {
            cout<<"there is nothing to delete!";
            return;
        }
        int i = 1;
        arr[i] = arr[size];
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }
};
int main()
{
    Heap h1;
    h1.insert(34);
    h1.insert(23);
    h1.insert(56);
    h1.insert(76);
    h1.insert(21);
    h1.insert(90);
    h1.insert(34);
    h1.print();
}