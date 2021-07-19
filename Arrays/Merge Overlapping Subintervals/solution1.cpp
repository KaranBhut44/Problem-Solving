class Solution {
public:
    static bool compare(vector<int>v1,vector<int>v2)
    {
        return v1[0]<v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        vector<vector<int>>res;
        int index=0;
        while(index<intervals.size())
        {
            if(res.empty())
                res.push_back(intervals[index]);
            else
            {
                if(res[res.size()-1][1]==intervals[index][0])
                {
                    res[res.size()-1][1]=intervals[index][1];
                }
                else if(res[res.size()-1][1]>intervals[index][0])
                {
                    res[res.size()-1][1]=max(res[res.size()-1][1],intervals[index][1]);
                }
                else
                {
                    res.push_back(intervals[index]);
                }
                index++;
            }
        }
        return res;
    }
};