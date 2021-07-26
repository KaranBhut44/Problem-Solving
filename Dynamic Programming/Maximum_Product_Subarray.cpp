class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long int nmax=INT_MAX,pmax=INT_MIN;
        long long int till_n=INT_MAX,till_p=INT_MIN;
    
        for(auto i:nums)
        {
            if(i<0)
            {
                long long int old_n = till_n;
                till_n = min(till_p*i,(long long)i);
                till_p = max(old_n*i,(long long)i);
            }
            else if(i>0)
            {
                till_n = min((long long)i,till_n*i);
                till_p = max((long long)i,i*till_p);
            }
            else
            {
                till_n = 0;
                till_p = 0;
            }
            
            pmax = max(pmax,till_p);
        }
        return pmax;
    }
};