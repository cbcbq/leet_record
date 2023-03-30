/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
constexpr int32_t intmax = std::numeric_limits<int32_t>::max();
constexpr int32_t intmin = std::numeric_limits<int32_t>::min();
class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        bool neg = false;
        while (i<s.size() && s[i]==' ') i++;
        if (i == s.size()) return 0;
        if (s[i] == '-') { neg = true; i++; }
        else if (s[i] == '+') { i++; }
        int64_t r=0;
        for (; i<s.size() && isdigit(s[i]); i++) {
            int a=s[i]-'0';
            if (neg) {
                r = r*10-a;
                if (r<intmin) {
                    return intmin;
                }
            } else {
                r = r*10+a;
                if (r>intmax) {
                    return intmax;
                }
            }
        }

        return r;
    }
};
// @lc code=end

