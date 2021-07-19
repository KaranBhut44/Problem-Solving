vector<int> Solution::repeatedNumber(const vector<int> &arr) {
    int x_xor_y = 0;
    int n = arr.size();
    for(int i=0;i<n;i++)
        x_xor_y = x_xor_y ^ arr[i];
    
    for(int i=1;i<=n;i++)
        x_xor_y = x_xor_y ^ i;
    
    int var = x_xor_y;
    int count=0;
    while(var>1)
    {
        var >>= 1;
        count++;
    } 
    int threshold = pow(2,count);
 
    int left = 0, right = 0; // left for set bit 
    for(int i=0;i<n;i++)
    {
        if(arr[i] & threshold)
            left ^= arr[i];
        else
            right ^= arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(i & threshold)
            left ^= i;
        else
            right ^= i;
    }
    
    for(int i=0;i<n;i++)
    {
        if(right == arr[i])
        {
            swap(left,right);
            break;
        }
    }
    
    vector<int> v = {left,right};
    return v;
}