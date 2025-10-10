class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n, 0);

        // dp[i] = max energy starting from i
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = energy[i];
            if (i + k < n) {
                dp[i] += dp[i + k]; // add energy from jump destination
            }
        }

        // answer is the max dp[i] over all starting points
        return *max_element(dp.begin(), dp.end());
    }
};
        
 