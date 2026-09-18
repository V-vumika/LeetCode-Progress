class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        result.reserve(factorial(n)); 
        
        backtrack(nums, 0, n, result);
        return result;
    }
    
private:
    int factorial(int n) {
        int f = 1;
        for (int i = 2; i <= n; i++) f *= i;
        return f;
    }
    
    void backtrack(vector<int>& nums, int start, int n, vector<vector<int>>& result) {
        if (start == n) {
            result.push_back(nums);
            return;
        }
        
        for (int i = start; i < n; i++) {
            swap(nums[start], nums[i]);
            backtrack(nums, start + 1, n, result);
            swap(nums[start], nums[i]);
        }
    }
};