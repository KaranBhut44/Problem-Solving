class Solution {
public:
    int trap(vector<int>& height) {
        int leftmax=0,rightmax=0;
        int n = height.size();
        int i=0,j=n-1;
        int sum =0;
        while(i<j)
        {
            if(height[i] <= height[j])
            {
                if(leftmax < height[i])
                    leftmax = height[i];
                else
                    sum += leftmax - height[i];
                i++;
            }
            else
            {
                if(rightmax < height[j])
                    rightmax = height[j];
                else
                    sum += rightmax - height[j];
                j--;
            }
        }
        return sum;
    }
};
