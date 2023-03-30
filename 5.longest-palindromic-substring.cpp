/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#define FOR(i, a, b) for (decltype(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
class Solution {
public:
/*
    string longestPalindrome(string s) {
        const int n = s.size();
        std::string p(2*n+1, '#');
        for (int i=0; i < n; i++) {
            p[2*i+1] = s[i];
        }
        std::cout << p << std::endl;

        int l=0, r=0;
        std::vector<int> d(2*n+1);
        d[0] = 1;
        for (int i=0; i < p.size(); i++) {
            if (i <= r) {
                d[i] = std::min(d[l + r - i], r-i+1);
            }
            while (i-d[i] >= 0 && i+d[i] < p.size() && p[i-d[i]] == p[i+d[i]]) {
                d[i]++;
            }
            if (i+d[i]-1 > r) {
                r = i+d[i]-1;
                l = i-d[i]+1;
            }
        }

        const int max_idx = std::max_element(d.begin(), d.end()) - d.begin();
        const int radius = d[max_idx];
        return s.substr((max_idx - radius) * 0.5 + 1, radius - 1);
    }
*/
    string longestPalindrome(string s) {
        string a(2*s.size()+1, '.');
        vector<int> z(2*s.size()+1);
        REP(i, s.size())
        a[2*i+1] = s[i];
        for (int f, g = 0, i = 0; i < a.size(); i++)
        if (i < g && z[2*f-i] != g-i)
            z[i] = min(z[2*f-i], g-i);
        else {
            f = i;
            g = max(g, i);
            while (g < a.size() && 2*f-g >= 0 && a[g] == a[2*f-g]) g++;
            z[i] = g-f;
        }
        int x = max_element(z.begin(), z.end()) - z.begin();
        return s.substr((x-z[x]+1)/2, z[x]-1);
    }
};
// @lc code=end

