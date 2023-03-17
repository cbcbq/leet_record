/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> value_to_idx;
        for (int idx = 0; idx < nums.size(); idx++) {
            if (value_to_idx.find(target - nums[idx]) != value_to_idx.end()) {
                return {idx, value_to_idx[target-nums[idx]]};
            }

            value_to_idx[nums[idx]] = idx;
        }

        return {};
    }
};
// @lc code=end

