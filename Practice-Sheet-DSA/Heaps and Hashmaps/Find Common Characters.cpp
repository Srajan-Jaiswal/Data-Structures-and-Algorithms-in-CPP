class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
         vector<int> B(26, INT_MAX);
    
    for(auto i:A)
    {   
        vector<int> C(26,0);
        for(auto j:i){
            C[j-'a']++;
            
        }
        for(auto i=0;i<26;i++) B[i]=min(B[i],C[i]);
    }
    
    vector<string> res;
    for(auto i=0;i<26;i++)
    {
        for(int j=0;j<B[i];j++)
        {
            string s;
            s.push_back('a'+i);
            res.push_back(s);
        }
    }
    
    return res;
    }
};
