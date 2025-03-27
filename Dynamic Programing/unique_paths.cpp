#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int countPaths(int r, int c, vector<vector<string>>& grid, unordered_map<string, int>& memo) {
    int rows = grid.size(), cols = grid[0].size();
    if (r >= rows || c >= cols || grid[r][c] == "X") {
        return 0;
    }
    if (r == rows - 1 && c == cols - 1) {
        return 1;
    }
    string key = to_string(r) + "," + to_string(c);
    if (memo.count(key)) {
        return memo[key];
    }
    memo[key] = countPaths(r + 1, c, grid, memo) + countPaths(r, c + 1, grid, memo);
    return memo[key];
}
int main() {
    vector<vector<string>> grid = {
        {"O", "O", "X"},
        {"O", "O", "O"},
        {"X", "O", "O"}
    };
    unordered_map<string, int> memo; 
    cout << "Number of paths: " << countPaths(0, 0, grid, memo) << endl;
    return 0;
}
