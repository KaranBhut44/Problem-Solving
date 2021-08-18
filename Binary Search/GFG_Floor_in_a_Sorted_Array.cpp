int bin_search(long long int *arr,int s,int e,long long int target)
{
    if(s>e)
        return e;
    int mid = (s+e)/2;
    if(arr[mid]<target)
        return bin_search(arr,mid+1,e,target);
    else if(arr[mid]>target)
        return bin_search(arr,s,mid-1,target);
    return mid;
}
int findFloor(long long int arr[], int N, long long int K) {
    return bin_search(arr,0,N-1,K);
    //Your code here
}
