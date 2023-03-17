/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> show(127);
        int ml = 0;
        for (int i = 0, j = 0; j < s.size(); i++) {
            for (; j < s.size() && !show[s[j]]; j++)
                show[s[j]] = true;
            ml = max(ml, j-i);
            show[s[i]] = false;
        }
        return ml;
    } 
};
// @lc code=end

