#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
bool sumPossible(int amount, vector<int> &numbers, unordered_map<int, bool> &memo)
{
    if (amount == 0)
        return true;
    if (amount < 0)
        return false;
    if (memo.find(amount) != memo.end())
        return memo[amount];
    for (int num : numbers)
    {
        int subAmount = amount - num;
        if (sumPossible(subAmount, numbers, memo))
        {
            memo[amount] = true;
            return true;
        }
    }
    memo[amount] = false;
    return false;
}
bool sumPossible(int amount, vector<int> &numbers)
{
    unordered_map<int, bool> memo;
    return sumPossible(amount, numbers, memo);
}
int main()
{
    vector<int> numbers = {2, 3, 5};
    int amount = 8;
    if (sumPossible(amount, numbers))
    {
        cout << "Yes, sum is possible!" << endl;
    }
    else
    {
        cout << "No, sum is not possible!" << endl;
    }
    return 0;
}
// Time Complexity: O(n * m) where n is the amount and m is the number of coins
// Space Complexity: O(n) where n is the amount