#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &vec, int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && vec[largest] < vec[left])
    {
        largest = left;
    }
    if (right <= n && vec[largest] < vec[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(vec[largest], vec[i]);
        heapify(vec, n, largest);
    }
}

void heapSort(vector<int> &vec, int n)
{
    int size = n;
    for (int i = size / 2; i > 0; i--)
    {
        heapify(vec, size, i);
    }
    while (size > 1)
    {
        swap(vec[1], vec[size]);
        size--;
        heapify(vec, size, 1);
    }
}

int main()
{
    cout << "All About heapify!\n";
    vector<int> vec(6, 0);

    for (int i = 1; i < vec.size(); i++)
    {
        cin >> vec[i];
    }

    // Build the max-heap
    for (int i = vec.size() / 2; i > 0; i--)
    {
        heapify(vec, vec.size() - 1, i);
    }
    cout << "Heap after heapify:\n";
    for (int i = 1; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << '\n';

    cout << "All About Heap Sort\n";

    // Perform heap sort
    heapSort(vec, vec.size() - 1);

    cout << "Sorted array:\n";
    for (int i = 1; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << '\n';

    return 0;
}
