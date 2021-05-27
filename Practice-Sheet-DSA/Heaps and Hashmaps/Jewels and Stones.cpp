class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<int,int> um;
        int cnt=0;
        for(auto j : jewels) um[j-'0']++;
        for(auto s : stones){
            if(um[s-'0']>0) cnt++;
         }
         return cnt;
    }
};
