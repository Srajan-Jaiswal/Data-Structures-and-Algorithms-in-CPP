vector<int> countDistinct (int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    
    for(int i = 0; i < k; i++)
    {
        mp[arr[i]]++;
    }
    
    vector<int> res;
    res.push_back(mp.size());
    
    for(int i = k; i < n; i++)
    {
        mp[arr[i - k]]--;
        
        if(mp[arr[i - k]] == 0)
        {
            mp.erase(arr[i - k]);
        }
        
        mp[arr[i]]++;
        
        res.push_back(mp.size());
    }
    
    return res;
}
