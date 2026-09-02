class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        
        // Sort so duplicate values are next to each other
        sort(nums.begin(), nums.end());
        
        vector<int> current;
        
        backtrack(nums, 0, current, result);
        
        return result;
    }

private:
    void backtrack(vector<int>& nums, int start,
                   vector<int>& current,
                   vector<vector<int>>& result) {
        
        // Every current combination is a valid subset
        result.push_back(current);
        
        for (int i = start; i < nums.size(); i++) {
            
            // Skip duplicates at the same recursion level
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // Choose nums[i]
            current.push_back(nums[i]);
            
            // Move to the next index
            backtrack(nums, i + 1, current, result);
            
            // Undo the choice
            current.pop_back();
        }
    }
};