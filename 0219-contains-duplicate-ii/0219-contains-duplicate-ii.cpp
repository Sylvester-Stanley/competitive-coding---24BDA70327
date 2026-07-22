class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastIndex;

        for (int i = 0; i < nums.size(); i++) {

            // If the number has appeared before
            if (lastIndex.find(nums[i]) != lastIndex.end()) {

                // Check if the distance between indices is at most k
                if (i - lastIndex[nums[i]] <= k)
                    return true;
            }

            // Store/update the latest index of the current number
            lastIndex[nums[i]] = i;
        }

        return false;
    }
};