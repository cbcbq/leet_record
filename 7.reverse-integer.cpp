/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        if (x == std::numeric_limits<int32_t>::min()) return 0;
        int sign = 1;
        if (x < 0) {
            sign = -1;
            x = -x;
        }
        constexpr int max = std::numeric_limits<int32_t>::max();
        constexpr int maxdivideten = std::numeric_limits<int32_t>::max()/10;

        uint32_t new_int = 0;
        while (x%10==0) x/=10;
        for (;x / 10 != 0; x /= 10) {
            new_int += x % 10;
            if (new_int > maxdivideten) {
                return 0;
            }

            new_int *= 10;
        }

        if (max - new_int < 10) {
            if (sign > 0 && x % 10 > 7) {
                return 0;
            }
            if (sign < 0 && x % 10 > 8) {
                return 0;
            }
        }

        return (sign * new_int) + (sign * (x%10));
    }
};
// @lc code=end

