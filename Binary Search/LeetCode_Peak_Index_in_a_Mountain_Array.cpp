class Solution {
public:
    int n;
    int BS(vector<int>&arr,int s,int e)
    {
        if(s>e)
            return -1;
        int mid = (s+e)/2;
        if(mid-1>=0 && mid+1 < n && arr[mid-1] < arr[mid] && arr[mid]>arr[mid+1])
            return mid;
        if(mid-1<0 || (arr[mid-1] < arr[mid] && arr[mid]<arr[mid+1]))
            return BS(arr,mid+1,e);
        return BS(arr,s,mid-1);
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        n = arr.size();
        return BS(arr,0,n-1);
    }
};
