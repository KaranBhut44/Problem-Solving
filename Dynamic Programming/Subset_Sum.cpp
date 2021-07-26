#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int isPossible(int N,int *arr,int sum,int **dp)
    {
        if(sum<0)
            return 0;
        if(N==0 && sum==0)
        {
            dp[N][sum] = 1;
            return 1;
        }
        else if(N==0)
        {
            dp[N][sum] = 0;
            return 0;
        }
        if(dp[N][sum]>-1)
            return dp[N][sum];

        int opt1 = isPossible(N-1,arr+1,sum,dp);
        int opt2 = isPossible(N-1,arr+1,sum-arr[0],dp);
    
        if(opt1 + opt2 >= 1)
            dp[N][sum] = 1;
        else
            dp[N][sum] = 0;
        return dp[N][sum];
    }
    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        int **dp = new int*[N+1];
        for(int i=0;i<=N;i++)
        {
            dp[i] = new int[sum+1];
            for(int j=0;j<=sum;j++)
                dp[i][j] = -1;
        }
        if(isPossible(N,arr,sum,dp))
            return true;
        else 
            return false;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends