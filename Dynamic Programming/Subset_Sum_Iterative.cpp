class Solution{   
public:
    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        bool **dp = new bool*[N+1];
        for(int i=0;i<=N;i++)
        {
            dp[i] = new bool[sum+1];
            for(int j=0;j<=sum;j++)
                dp[i][j] = false;
        }
        for(int i=0;i<=N;i++)
        {
            dp[i][0] = true;
        }
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                bool opt1 = dp[i-1][j];
                bool opt2 = false;
                if(j>=arr[i-1])
                    opt2 = dp[i-1][j-arr[i-1]];
                dp[i][j] = opt1 || opt2;
            }
        }
        return dp[N][sum];
    }
};
