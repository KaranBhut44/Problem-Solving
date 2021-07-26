#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void fill_matrix(vector<vector<int>> v, int **dp,int n,int row)
    {
        if(row<0)
            return;
        
        for(int col=0;col<n;col++)
        {
            int max1=0;
            if(row+1<n && col+1<n)
                max1 = max(max1,dp[row+1][col+1]);
            if(row+1<n && col-1>=0)
                max1 = max(max1,dp[row+1][col-1]);
            if(row+1<n)
                max1 = max(max1,dp[row+1][col]);
            dp[row][col] = max1 + v[row][col];
        }
        return fill_matrix(v,dp,n,row-1);
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int **dp = new int*[N];
        for(int i=0;i<N;i++)
        {
            dp[i] = new int[N];
            for(int j=0;j<N;j++)
            {
                dp[i][j] = 0;
            }
        }
        for(int i=0;i<N;i++)
        {
            dp[N-1][i] = Matrix[N-1][i];
        }
        fill_matrix(Matrix,dp,N,N-2);
        int max1 =0;
        
        for(int i=0;i<N;i++)
        {
            max1 = max(max1,dp[0][i]);
        }
        return max1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends