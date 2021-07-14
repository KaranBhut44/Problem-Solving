class Solution {
public:
    void sortColors(vector<int>& arr) {
        int l=0,m=0,r=arr.size()-1;
        while(m<=r)
        {
            if(arr[m]==0)
            {
                swap(arr[l],arr[m]);
                l++;
                m++;
            }
            else if(arr[m]==1)
            {
                m++;
            }
            else if(arr[m]==2)
            {
                swap(arr[r],arr[m]);
                r--;
            }
        }
    }
};