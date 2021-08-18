#include<bits/stdc++.h>
using namespace std;

int Lower(vector<int> &arr,int s,int e,int target,int index)
{
    if(s>e)
        return index;
    int m = (s+e)/2;
    if(arr[m] == target)
            return Lower(arr,s,m-1,target,m);
    else if(arr[m] > target)
        return Lower(arr,s,m-1,target,index);
    else
        return Lower(arr,m+1,e,target,index);
}
int Upper(vector<int> &arr,int s,int e,int target,int index)
{
    if(s>e)
        return index;
    int m = (s+e)/2;
    if(arr[m] == target)
        return Upper(arr,m+1,e,target,m);
    else if(arr[m] < target)
        return Upper(arr,m+1,e,target,index);
    else
        return Upper(arr,s,m-1,target,index);
}
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> v;
        v.push_back(Lower(nums,0,n-1,target,-1));
        v.push_back(Upper(nums,0,n-1,target,-1));
        return v;
    }
};
