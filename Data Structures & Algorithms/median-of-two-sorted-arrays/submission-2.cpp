class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // nums1 should be the smaller array always
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        // taking the range and total sizes
        int m = nums1.size(), n = nums2.size();
        int lo = 0, hi = m; 
        double median = 0;
        // the binary search
        while(true) {
            // taking the i and j pointers
            int i = (lo + hi) / 2;
            int j = (m + n + 1) / 2 - i;

            // taking the actual elements that we need to compare to find the median and checking the edge-cases
            int l1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int r1 = (i == m) ? INT_MAX : nums1[i];
            int l2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int r2 = (j == n) ? INT_MAX : nums2[j];

            if (l1 <= r2 && l2 <= r1) {
                if((m+n)%2 == 0){
                    median = (max(l1, l2) + min(r1, r2)) / 2.0;
                    break;
                }
                else{
                    median = max(l1, l2);
                    break;
                }
            } else if(l1 > r2)
                hi = i - 1;
            else
                lo = i + 1;

        }

        return median;

    }
};
