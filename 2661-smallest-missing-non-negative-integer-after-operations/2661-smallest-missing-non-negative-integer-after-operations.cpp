class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        // Frequency map for remainders modulo 'value'
        unordered_map<int, int> freq;

        for (int num : nums) {
            // Handle negative numbers correctly for modulo
            int r = ((num % value) + value) % value;
            freq[r]++;
        }

        int mex = 0;

        while (true) {
            int rem = mex % value;
            // If we have a number to cover this remainder, use it
            if (freq[rem] > 0) {
                freq[rem]--;
                mex++;
            } else {
                break;
            }
        }

        return mex;
    }
};
