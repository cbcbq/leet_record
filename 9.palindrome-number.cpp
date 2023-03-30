/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        int ti = 1;
        for(;x/ti>=10;ti*=10) ;
        while (x) {
            if (x%10 != x/ti) return false;
            x = x%ti/10;
            ti/=100;
        }

        return true;
    }
};
// @lc code=end

