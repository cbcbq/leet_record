/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
/*


*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int median_idx = m + n - 1 >> 1;
        int i = 0, j = 0;
        // find the n-th elem of these two array
        while (0 != median_idx) {
            int step = median_idx - 1 >> 1;
            // one of (i, j) must be able to increase so just need few check here
            if (i + step >= m || (j + step < n && nums1[i + step] > nums2[j + step])) {
                j += step + 1;
            } else {
                i += step + 1;
            }
            median_idx -= step + 1;
        }

        int median1 = i >= m || j < n && nums1[i] > nums2[j] ? nums2[j++] : nums1[i++];
        return (m + n) & 1 ? median1 :
            (i >= m || j < n && nums1[i] > nums2[j] ?
                median1 + nums2[j] : median1 + nums1[i]) * 0.5;
    }
};
// @lc code=end

