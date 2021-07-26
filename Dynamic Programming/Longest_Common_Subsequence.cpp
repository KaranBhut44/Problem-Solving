class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size()+1;
        int m = text2.size()+1;
        int **dp = new int*[2];
        for(int i=0;i<2;i++)
        {
            dp[i] = new int[m];
        }
        for(int i=0;i<2;i++)
            dp[i][0] = 0;
        for(int j=0;j<m;j++)
            dp[0][j] = 0;
        int flag = 0;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    dp[1-flag][j] = dp[flag-0][j-1] + 1;
                }
                else
                {
                    dp[1-flag][j] = max(dp[flag-0][j], dp[1-flag][j-1]);
                }
            }
            flag = 1 - flag;
        }
        return dp[flag][m-1];
    }
};