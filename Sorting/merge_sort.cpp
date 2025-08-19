#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void merge_sort(vector<int>& A, int l, int h) {
        if (l >= h) {
            return;
        }
        
        int mid = (l + h) / 2;
        merge_sort(A, l, mid);
        merge_sort(A, mid + 1, h);
        Merging(A, l, h, mid);
    }
    void Merging(vector<int>& A, int l, int h, int mid) {
        int i, j, k;
        i = l;
        j = mid + 1;
        k = 0;
        vector<int> B;
        while (i <= mid && j <= h) {
            if (A[i] < A[j]) {
                B.push_back(A[i++]);
            } else {
                B.push_back(A[j++]);
            }
        }
        while (i <= mid) {
            B.push_back(A[i++]);
        }
        while (j <= h) {
            B.push_back(A[j++]);
        }
        for (int i = l; i <= h; i++) {
            A[i] = B[k++];
        } return ;
    }
    vector<int> sortArray(vector<int>& nums) {
        int h = nums.size() - 1;
        int l = 0;
        
        merge_sort(nums, l, h);

        return nums;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {5, 2, 3, 1};
    vector<int> sorted_nums = sol.sortArray(nums);
    for (int num : sorted_nums) {
        cout << num << " ";
    }
}