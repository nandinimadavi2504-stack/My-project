import java.util.*;

class Solution {
    public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
        
        // Step 1: Sort
        Collections.sort(robot);
        Arrays.sort(factory, (a,b) -> a[0] - b[0]);
        
        // Step 2: Expand factories
        List<Integer> fac = new ArrayList<>();
        for(int[] f : factory){
            int pos = f[0];
            int limit = f[1];
            for(int i=0;i<limit;i++){
                fac.add(pos);
            }
        }
        
        int n = robot.size();
        int m = fac.size();
        
        // Step 3: DP
        long[][] dp = new long[n+1][m+1];
        
        // initialize
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i], Long.MAX_VALUE);
        }
        
        for(int j=0;j<=m;j++){
            dp[0][j] = 0; // 0 robots = 0 cost
        }
        
        // Step 4: Fill DP
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                // skip factory j
                dp[i][j] = dp[i][j-1];
                
                // assign robot i to factory j
                if(dp[i-1][j-1] != Long.MAX_VALUE){
                    long cost = dp[i-1][j-1] + Math.abs(robot.get(i-1) - fac.get(j-1));
                    dp[i][j] = Math.min(dp[i][j], cost);
                }
            }
        }
        
        return dp[n][m];
    }
}