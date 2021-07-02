class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(),a.end());
    long long  mini = LLONG_MAX;
    for(int i=0;i<n;i++){
        if(i+m-1 < n){
        mini = min(mini,(a[i+m-1]-a[i]));
        }
    }
    return mini;    
    }
};
