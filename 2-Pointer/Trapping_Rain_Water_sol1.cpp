class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0)
            return 0;
        int *left = new int[n];
        left[0] = 0;
        int temp = height[0];
        for(int i=1;i<n;i++)
        {
            left[i] = temp;
            temp = max(height[i],temp);
        }
        
        int *right = new int[n];
        right[n-1] = 0;
        temp = height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right[i] = temp;
            temp = max(height[i],temp);
        }
        
        int count = 0;
        for(int i=0;i<n;i++)
        {
            count += max( 0 , min( left[i] , right[i] ) - height[i] );
        }
        return count;
    }
};
