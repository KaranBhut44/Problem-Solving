class Solution {
public:
    void find_subseq(vector<int>& arr,int target,vector<int> &current,vector<vector<int>> &ans,int start,int prev)
    { 
        int n = arr.size();
        if(start == n)
        {
            if(target == 0)
                ans.push_back(current);
            return;
        }
        if(target >= arr[start] && prev!=arr[start])
        {
            current.push_back(arr[start]);
            find_subseq(arr,target-arr[start],current,ans,start+1,-1);
            current.pop_back();
        }

        find_subseq(arr,target,current,ans,start+1,arr[start]);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        find_subseq(candidates,target,current,ans,0,-1);
        return ans;
    }
};