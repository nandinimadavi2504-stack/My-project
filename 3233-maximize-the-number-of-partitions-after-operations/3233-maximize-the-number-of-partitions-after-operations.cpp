class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        unordered_map<long long,int> mem;
        // dp(0, true, 0) returns number of *additional* partitions after the first,
        // so we add 1 at the end to count the final partitioning properly.
        return dfs(s, 0, true, 0, k, mem) + 1;
    }

private:
    // dfs returns the maximum number of partitions for s[i..end) given:
    //  - canChange: whether we still have the one allowed change available
    //  - mask: bitmask of letters seen in the *current* prefix (bits 0..25)
    // We memoize on (i, canChange, mask) packed into a 64-bit key.
    int dfs(const string &s, int i, bool canChange, int mask, int k,
            unordered_map<long long,int> &mem) {
        if (i == (int)s.size()) return 0;

        // pack (i, canChange, mask) into key:
        // i in higher bits, canChange in one bit, mask in low 26 bits.
        long long key = (static_cast<long long>(i) << 27)
                        | (static_cast<long long>(canChange ? 1LL : 0LL) << 26)
                        | static_cast<long long>(mask);
        auto it = mem.find(key);
        if (it != mem.end()) return it->second;

        auto getRes = [&](int newBit, bool nextCanChange) -> int {
            int newMask = mask | newBit;
            // if adding this char makes distinct > k, we must finish the
            // current partition and start a new one with this character.
            if (__builtin_popcount((unsigned)newMask) > k) {
                // count the finished partition (1) + result from i+1 where
                // new partition's mask is newBit (only this character so far).
                return 1 + dfs(s, i + 1, nextCanChange, newBit, k, mem);
            } else {
                // otherwise continue current prefix
                return dfs(s, i + 1, nextCanChange, newMask, k, mem);
            }
        };

        // Option 1: do not change this character
        int res = getRes(1 << (s[i] - 'a'), canChange);

        // Option 2: change this character to any letter j (if allowed)
        // (we try all 26 letters here — DP + memo keeps it fast)
        if (canChange) {
            for (int j = 0; j < 26; ++j) {
                res = max(res, getRes(1 << j, false));
            }
        }

        mem[key] = res;
        return res;
    }
};
