/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) { return s; }
        std::string r;
        r.resize(s.size());
        const int p = numRows*2-2;
        const int m = s.size() / p + 1;
        for (int i=0, k=0; i<numRows; i++) {
            for (int j=i; j<s.size(); j+=p) {
                r[k++] = s[j];
                if (i > 0 && i < numRows-1 && j+(numRows-1-i)*2<s.size()) {
                    r[k++] = s[j+(numRows-1-i)*2];
                }
            }
        }

        return r;
    }
};
// @lc code=end

