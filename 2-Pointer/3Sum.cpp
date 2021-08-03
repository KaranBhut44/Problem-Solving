#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> v;
        if(n<3)
            return v;
        
        sort(arr.begin(),arr.end());
        set<vector<int>>s;
        for(int i=0;i<n-2;i++)
        {
            int l = i+1,r = n-1;
            while(l<r)
            {
                if(arr[l] + arr[r] +arr[i] == 0)
                {
                    vector<int> v1 = {arr[i],arr[l],arr[r]};
                    s.insert(v1);
                    l++;
                    r--;
                    while(arr[l]==arr[l-1] && l<r)
                        l++;
                }
                else if(arr[l] + arr[r] + arr[i] < 0)
                    l++;
                else
                    r--;
                
            }
        }
        for(auto i:s)
            v.push_back(i);
        return v;
    }
};