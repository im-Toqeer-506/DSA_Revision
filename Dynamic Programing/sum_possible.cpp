#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
bool sumPossibleHelper(int amount, vector<int> &numbers, unordered_map<int, bool> &memo) {
    if (amount == 0) return true;  
    if (amount < 0) return false;  
    if (memo.find(amount) != memo.end()) return memo[amount];  
    for (int num : numbers) {
        int subAmount = amount - num;
        if (sumPossibleHelper(subAmount, numbers, memo)) {
            memo[amount] = true;
            return true;
        }
    }
    memo[amount] = false;
    return false;
}
bool sumPossible(int amount, vector<int> &numbers) {
    unordered_map<int, bool> memo;
    return sumPossibleHelper(amount, numbers, memo);
}
int main() {
    vector<int> numbers = {5, 3, 4, 7};  
    int amount = 7;                       
    if (sumPossible(amount, numbers)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
