class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = (int)skill.size();
        int m = (int)mana.size();
        if (m == 0) return 0LL;

        long long startSum = 0; // cumulative start offsets (sum of required waits s_j)

        // For each adjacent pair of potions j and j+1, compute the minimal extra delay
        for (int j = 0; j + 1 < m; ++j) {
            long long acc_j = 0;             // sum_{k<=i} time[k][j]
            long long acc_next_before = 0;   // sum_{k< i} time[k][j+1]
            long long maxDiff = LLONG_MIN;

            for (int i = 0; i < n; ++i) {
                acc_j += 1LL * skill[i] * mana[j];         // sum_{k<=i} t[k][j]
                // acc_next_before is currently sum_{k< i} t[k][j+1]
                long long diff = acc_j - acc_next_before;  // required constraint value at wizard i
                if (diff > maxDiff) maxDiff = diff;
                acc_next_before += 1LL * skill[i] * mana[j+1];
            }

            if (maxDiff < 0) maxDiff = 0; // no negative waits
            startSum += maxDiff;
        }

        // Add full processing time of the last potion across all wizards
        long long lastTotal = 0;
        for (int i = 0; i < n; ++i) lastTotal += 1LL * skill[i] * mana[m-1];

        return startSum + lastTotal;
    }
};
