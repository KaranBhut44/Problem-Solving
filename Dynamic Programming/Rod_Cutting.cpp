// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int fun(int *arr,int arr_len,int rod_len,int weight,int **dp)
    {
        if(rod_len==0 || arr_len==0)
        {
            return 0;
        }
        if(dp[arr_len][rod_len] > -1)
            return dp[arr_len][rod_len];
        int max1 = fun(arr+1,arr_len-1,rod_len,weight+1,dp);
        if(weight <= rod_len)
        {
            max1 = max(max1, arr[0] + fun(arr,arr_len,rod_len-weight,weight,dp));
        }
        dp[arr_len][rod_len] = max1;
        return max1;
    }
    int cutRod(int price[], int n) {
        //code here
        int arr_len = n;
        int rod_len = n;
        int **dp = new int*[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i] = new int[n+1];
            for(int j=0;j<=n;j++)
            {
                dp[i][j] = -1;
            }
        }
        fun(price,arr_len,rod_len,1,dp);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends