class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        // Sort to handle duplicates
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0, current, result);

        return result;
    }

private:
    void backtrack(vector<int>& candidates,
                   int target,
                   int start,
                   vector<int>& current,
                   vector<vector<int>>& result) {

        // Target reached
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // If number is bigger than remaining target,
            // no later number can work because array is sorted
            if (candidates[i] > target) {
                break;
            }

            // Skip duplicates at the same recursion level
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Choose current number
            current.push_back(candidates[i]);

            // i + 1 because each number can only be used once
            backtrack(candidates,
                      target - candidates[i],
                      i + 1,
                      current,
                      result);

            // Undo choice
            current.pop_back();
        }
    }
};