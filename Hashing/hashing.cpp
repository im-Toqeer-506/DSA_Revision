#include <iostream>
#include <vector>
#include <list>
#include <algorithm> 
using namespace std;
class Hashing
{
public:
    vector<list<int>> hashtable;
    int buckets;
    Hashing(int size)
    {
        buckets = size;
        hashtable.resize(size);
    }
    int hashvalue(int key)
    {
        return (key % buckets);
    }
    void add(int key)
    {
        int idx = hashvalue(key);
        hashtable[idx].push_back(key);
    }
    list<int>::iterator search(int key)
    {
        int idx = hashvalue(key);
        return find(hashtable[idx].begin(), hashtable[idx].end(), key);
    }
    void Delete(int key)
    {
        int idx = hashvalue(key);
        if (search(key) != hashtable[idx].end())
        {
            hashtable[idx].erase(search(key));
            cout << key << " is deleted!";
        }
        else
        {
            cout << "Key is not present!";
        }
    }
};

int main()
{
    Hashing hashTable(7); 
    hashTable.add(10);
    hashTable.add(20);
    hashTable.add(15);
    hashTable.add(7);

    hashTable.Delete(20);
    hashTable.Delete(25); 
}