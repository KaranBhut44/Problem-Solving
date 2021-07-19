class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        vector<int>v2 ={1};
        v.push_back(v2);
        if(numRows==1)
        {
            return v;
        }
        v2={1,1};
        v.push_back(v2);
        
        
        while(numRows-2!=0)
        {
            int m =v.size()-1;
            vector<int>v1={1};
            vector<int> &arr = v[m];
            int n=arr.size()-1;
            for(int i=0;i<n;i++)
            {
                v1.push_back(arr[i]+arr[i+1]);
            }
            v1.push_back(1);
            v.push_back(v1);
            numRows--;
        }
        return v;
    }
};