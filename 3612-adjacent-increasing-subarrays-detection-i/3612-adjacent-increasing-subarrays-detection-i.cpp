class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // Helper lambda to check if subarray nums[start..start+k-1] is strictly increasing
        auto isIncreasing = [&](int start) {
            for (int i = start; i < start + k - 1; i++) {
                if (nums[i] >= nums[i + 1]) return false;
            }
            return true;
        };

        // Iterate over possible starting points of the first subarray
        for (int i = 0; i + 2 * k <= n; i++) {
            // First subarray: starts at i, ends at i+k-1
            // Second subarray: starts at i+k, ends at i+2k-1
            if (isIncreasing(i) && isIncreasing(i + k)) {
                return true;
            }
        }
        return false;
    }
};
