class Solution {
public:
    int minAddToMakeValid(string S) {
        int ans=0,cnt=0;
        for(int i=0;i<S.length();i++){
            if(cnt < 0){
                ans += abs(cnt);
                cnt=0;
            }
            if(S[i]=='(' && cnt>=0) cnt++;
            if(S[i]==')') cnt--;
        }
        if(cnt>0) ans+=cnt;
        if(cnt<0) ans += abs(cnt);
        return ans;
    }
};
