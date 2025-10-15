class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        // inc[i] = length of strictly increasing subarray ending at index i
        vector<int> inc(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                inc[i] = inc[i - 1] + 1;
            }
        }

        // dec[i] = length of strictly increasing subarray starting at index i
        // (basically forward increasing lengths but reversed)
        vector<int> startInc(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                startInc[i] = startInc[i + 1] + 1;
            }
        }

        int maxK = 0;
        // Check for adjacent subarrays: [i - k + 1 .. i] and [i+1 .. i+k]
        // inc[i] is length of inc subarray ending at i
        // startInc[i+1] is length of inc subarray starting at i+1
        for (int i = 0; i < n - 1; i++) {
            int left = inc[i];
            int right = startInc[i + 1];
            int possibleK = min(left, right);
            maxK = max(maxK, possibleK);
        }

        return maxK;
    }
};
