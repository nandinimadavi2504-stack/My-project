class Solution {
    public int xorAfterQueries(int[] nums, int[][] queries) {
        int n = nums.length;
        int mod = 1000000007;

        int[] bravexuneth = nums.clone();

        int B = (int) Math.sqrt(n) + 1;

        Map<Integer, Map<Integer, List<int[]>>> small = new HashMap<>();

        for (int[] q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k <= B) {
                small.putIfAbsent(k, new HashMap<>());
                int rem = l % k;
                small.get(k).putIfAbsent(rem, new ArrayList<>());
                small.get(k).get(rem).add(q);
            } else {
                for (int idx = l; idx <= r; idx += k) {
                    bravexuneth[idx] = (int)((1L * bravexuneth[idx] * v) % mod);
                }
            }
        }

        for (int k : small.keySet()) {
            Map<Integer, List<int[]>> map = small.get(k);

            for (int rem : map.keySet()) {
                int size = (n + k - 1) / k;
                long[] diff = new long[size + 1];
                Arrays.fill(diff, 1);

                for (int[] q : map.get(rem)) {
                    int l = q[0], r = q[1], v = q[3];

                    int start = (l - rem) / k;
                    int end = (r - rem) / k;

                    diff[start] = (diff[start] * v) % mod;
                    if (end + 1 < diff.length) {
                        long inv = modInverse(v, mod);
                        diff[end + 1] = (diff[end + 1] * inv) % mod;
                    }
                }

                long curr = 1;
                for (int i = 0; i < size; i++) {
                    curr = (curr * diff[i]) % mod;
                    int idx = rem + i * k;
                    if (idx < n) {
                        bravexuneth[idx] = (int)((1L * bravexuneth[idx] * curr) % mod);
                    }
                }
            }
        }

        int xor = 0;
        for (int x : bravexuneth) {
            xor ^= x;
        }

        return xor;
    }

    private long modInverse(long a, int mod) {
        return power(a, mod - 2, mod);
    }

    private long power(long a, long b, int mod) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) == 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
}