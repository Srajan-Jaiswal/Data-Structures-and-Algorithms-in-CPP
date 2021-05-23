class Solution {
public:
    unordered_map<char,int> freq1,freq2;
    int balancedString(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++) freq1[s[i]]++;
        int cnt = s.length()/4;
        for(auto it : freq1){ 
              if(it.second>cnt) freq2[it.first] = abs(it.second-cnt);
        }
        int size = freq2.size();
        int i=0,j=0,res =0;
        int fin_ans = INT_MAX;
        freq1.clear();
        while(j<s.length()){
            if(freq2.find(s[j]) != freq2.end()){
                if(freq2[s[j]]==0){
                    res++;
                }
                else {
                    freq2[s[j]]--;
                }
            }
            j++;
            while(i<j && res == size){
                fin_ans = min(fin_ans,j-i);
                if(freq2.find(s[i]) != freq2.end()){
                    freq2[s[i]]++;
                    if(freq2[s[i]] > 0) res--;
                }
                i++; 
            }
        }
        return fin_ans;
    }
};
