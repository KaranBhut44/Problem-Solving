class Solution {
public:
    int check(int n,int *arr)
    {
        if(n <= 0)
            return 0;
        if(arr[n] > -1)
            return arr[n];
        if(n == 1 || n==2)
            return arr[n] = n;
        return arr[n] = check(n-1,arr)+check(n-2,arr);
    }
    int climbStairs(int n) {
        int arr[n+1];
        for(int i=0;i<=n;i++)
            arr[i] = -1;
        return check(n,arr);
    }
};
