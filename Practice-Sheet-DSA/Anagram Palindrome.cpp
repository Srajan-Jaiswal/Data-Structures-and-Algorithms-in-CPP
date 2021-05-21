int isPossible(string S)
{
    unordered_map<char, int> mp;
    int len = S.size();
    int cnt = 0;
    for (int i = 0; i < len; i++){
        mp[S[i]]++;
    }
    for (auto i : mp){ 
        if(i.second%2!=0){
            cnt++; 
            }
    }
    if(cnt > 1)return 0;
    else return 1;
}
