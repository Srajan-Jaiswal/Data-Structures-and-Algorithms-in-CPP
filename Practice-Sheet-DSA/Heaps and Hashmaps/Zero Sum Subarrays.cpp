 ll findSubarray(vector<ll> arr, ll n ) {
        unordered_map<ll,ll> um;
        ll min_ele = INT_MAX;
        for(auto it : arr) min_ele = min(min_ele,it); 
        ll pos_min_ele = abs(min_ele);
        for(ll i : arr){
            i = i + pos_min_ele;
        }
        um[0]=1;
        ll sum=0,cnt=0;
        for(ll i=0;i<arr.size();i++){
            sum += arr[i];
            cout<<sum<<endl;
            if(um.find(sum) != um.end()){
                cnt += um[sum];
            }
            um[sum]++;
        }
        
        return cnt;
        
    }
};
