class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, int> full;  // lake -> index of last rain
        set<int> dryDays;              // indexes of 0 (dry) days

        for (int i = 0; i < n; i++) {
            int lake = rains[i];
            if (lake == 0) {
                dryDays.insert(i);
            } else {
                ans[i] = -1;
                if (full.find(lake) != full.end()) {
                    int lastRainIndex = full[lake];
                    auto it = dryDays.lower_bound(lastRainIndex);
                    if (it == dryDays.end()) {
                        return {};
                    }
                    int dryIndex = *it;
                    ans[dryIndex] = lake;
                    dryDays.erase(dryIndex);
                }
                full[lake] = i;
            }
        }

        return ans;
    }
};
    
    