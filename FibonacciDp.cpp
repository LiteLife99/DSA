class Solution {
public:
    int getFib(int n, vector<int> &dp) {
        if(n <= 1)
            return n;

        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = getFib(n-1, dp) + getFib(n-2, dp);
        
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        dp.push_back(0);
        dp.push_back(1);
        return getFib(n, dp);
    }
};
