class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        unordered_map<long long,int> mem;
        return dfs(s, 0, true, 0, k, mem) + 1;  // +1 for the final partition
    }

private:
    int dfs(const string &s, int i, bool canChange, int mask, int k,
            unordered_map<long long,int> &mem) {
        if (i == (int)s.size()) return 0;

        long long key = (static_cast<long long>(i) << 27)
                        | (static_cast<long long>(canChange ? 1LL : 0LL) << 26)
                        | static_cast<long long>(mask);
        if (mem.count(key)) return mem[key];

        auto getRes = [&](int newBit, bool nextCanChange) -> int {
            int newMask = mask | newBit;
            if (__builtin_popcount((unsigned)newMask) > k) {
                // Partition here
                return 1 + dfs(s, i + 1, nextCanChange, newBit, k, mem);
            } else {
                return dfs(s, i + 1, nextCanChange, newMask, k, mem);
            }
        };

        int res = getRes(1 << (s[i] - 'a'), canChange);  // no change

        if (canChange) {  // try changing to any letter
            for (int j = 0; j < 26; ++j) {
                if (j == s[i] - 'a') continue;
                res = max(res, getRes(1 << j, false));
            }
        }

        return mem[key] = res;
    }
};
