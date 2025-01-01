#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set<int> s;

    s.insert(5);
    s.insert(10);
    if (s.find(5) == s.end())
    {
        cout << "Not Found" << endl; // If 5 is not in the set
    }
    else
    {
        cout << "Found" << endl; // If 5 is in the set
    }

    // Step 5: Iterate through all elements in the set and print them
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    s.clear(); // Step 6: Clear all elements from the set

    // Step 7: Print the size of the set after clearing
    cout << "Size of set: " << s.size() << endl;

    return 0;
}
