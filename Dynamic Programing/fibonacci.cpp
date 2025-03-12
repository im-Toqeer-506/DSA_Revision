#include <iostream>
#include <unordered_map>
using namespace std;
int fibo(int n, unordered_map<int, int>& memo) {
    if (n == 0 || n == 1)
        return n; 

    if (memo.find(n) != memo.end()) 
        return memo[n];

   
    memo[n] = fibo(n - 1, memo) + fibo(n - 2, memo);
    return memo[n];
}

int fibo(int n) {
    unordered_map<int, int> memo; 
    return fibo(n, memo);
}

int main() {
    cout << fibo(6); 
}
