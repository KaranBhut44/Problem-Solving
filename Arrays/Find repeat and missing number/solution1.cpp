vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long diff =0;
    int n = A.size();
    int count =1;
    for(int i=0;i<n;i++)
    {
        diff += A[i] - count;
        count++;
    }
    long long square =0;
    count =1;
    for(int i=0;i<n;i++)
    {
        square += (long long)A[i]*A[i] - (long long)count*count;
        count++;
    }
    long long sum = square/diff;
    int duplicate = (sum + diff)/2;
    int missing = sum - duplicate;
    vector<int> v = {duplicate,missing};
    return v; 
}