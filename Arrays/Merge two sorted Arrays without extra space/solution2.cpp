class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int gap = ceil((m + (float)n) / 2);
            while(gap>=1)
            {
                int left = 0;
                int right = left + gap;
                while(right < n+m)
                {
                    if(left < n)
                    {
                        if(right < n)
                        {
                            if(arr1[left] > arr1[right])
                                swap(arr1[left],arr1[right]);
                        }
                        else
                        {
                            if(arr1[left] > arr2[right-n])
                                swap(arr1[left],arr2[right-n]);
                        }
                    }
                    else
                    {
                        if(arr2[left-n] > arr2[right-n])
                                swap(arr2[left-n],arr2[right-n]);
                    }
                    left++;
                    right++;
                }
                if(gap==1)
                    break;
                gap = ceil((float)gap/2);
            }
            
        } 
};