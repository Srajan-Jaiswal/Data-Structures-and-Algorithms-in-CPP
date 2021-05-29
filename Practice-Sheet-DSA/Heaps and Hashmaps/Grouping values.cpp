class Solution
{
    public:
    int isPossible(int N, int arr[], int K){
        unordered_map<int, int> mp;
        for(int i = 0; i < N; i++) mp[arr[i]]++;
        for(auto it : mp)
        {
            if(it.second  > 2*K)  return 0;
        }
        return 1;
    }
};
