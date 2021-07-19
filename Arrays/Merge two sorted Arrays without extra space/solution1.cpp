class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = m-1, ptr2 = n-1;
        int index= m+n-1;
        while(index>=0 && ptr1>=0 && ptr2>=0)
        {
            cout<<ptr1<<" "<<ptr2<<" "<<index<<endl;
            if(nums1[ptr1] > nums2[ptr2])
            {
                nums1[index] = nums1[ptr1];
                ptr1--;
            }
            else
            {
                nums1[index] = nums2[ptr2];
                ptr2--;
            }
            index--;
        }
        while(ptr1>=0 && index>=0)
        {
            nums1[index] = nums1[ptr1];
            ptr1--;
            index--;
        }
        while(ptr2>=0 && index>=0)
        {
            nums1[index] = nums2[ptr2];
            ptr2--;
            index--;
        }
    }
};