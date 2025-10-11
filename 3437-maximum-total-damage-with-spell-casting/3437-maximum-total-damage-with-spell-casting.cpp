class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> freq;
        for (int p : power) freq[p]++;

        // Extract unique damage values and sort them
        vector<int> damages;
        for (auto &entry : freq) damages.push_back(entry.first);
        sort(damages.begin(), damages.end());

        int n = damages.size();
        vector<long long> dp(n, 0);

        for (int i = 0; i < n; i++) {
            long long takeDamage = damages[i] * freq[damages[i]]; // contribution if taken

            // Find the previous index j which doesn't conflict with damages[i]
            int j = i - 1;
            while (j >= 0 && damages[i] - damages[j] <= 2) {
                j--;
            }

            long long take = takeDamage + (j >= 0 ? dp[j] : 0);
            long long skip = (i > 0 ? dp[i - 1] : 0);

            dp[i] = max(take, skip);
        }

        return dp[n - 1];
        
    }
};