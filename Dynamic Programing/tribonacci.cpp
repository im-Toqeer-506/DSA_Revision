#include <iostream>
#include <unordered_map>
using namespace std;
int tribonacci(int n, unordered_map<int, int> &memo)
{
    if (n == 0 || n == 1)
        return 0;
    if (n == 2)
        return 1;

    if (memo.find(n) != memo.end())
        return memo[n];

    memo[n] = tribonacci(n - 1, memo) + tribonacci(n - 2, memo) + tribonacci(n - 3, memo);
    return memo[n];
}

int tribonacci(int n)
{
    unordered_map<int, int> memo;
    return tribonacci(n, memo);
}

int main()
{
    cout << tribonacci(8);
}
