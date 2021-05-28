class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        stringstream ss(A);
        string s;
        unordered_map <string,int> mp; 
        while(ss>>s)
            mp[s]++;
        
        stringstream sd(B);
        vector <string> res;
        while(sd>>s)
            mp[s]++;
        for(auto it:mp)
            if(it.second==1)
                res.push_back(it.first);
        return res;
    }
};
