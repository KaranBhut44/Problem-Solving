class Solution {
public:
    void find_subseq(vector<int>& arr,int target,vector<int> &current,vector<vector<int>> &ans,int start)
    { 
        int n = arr.size();
        if(start == n)
        {
            if(target == 0)
                ans.push_back(current);
            return;
        }
        if(target >= arr[start])
        {
            current.push_back(arr[start]);
            find_subseq(arr,target-arr[start],current,ans,start);
            current.pop_back();
        }
        find_subseq(arr,target,current,ans,start+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> ans;
        find_subseq(candidates,target,current,ans,0);
        return ans;
    }
};