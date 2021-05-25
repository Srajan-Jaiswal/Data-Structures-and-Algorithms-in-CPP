// Runtime: 12 ms, faster than 99.95% of C++ online submissions for Pairs of Songs With Total Durations Divisible by 60.
// Memory Usage: 23.2 MB, less than 53.52% of C++ online submissions for Pairs of Songs With Total Durations Divisible by 60.
class Solution {
public:
   int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        vector<int> um(60,0);
        for(int t : time){
            t = t%60;
            int diff = 60 - t;
            if(diff == 60) diff = 0;
            ans += um[diff];
            um[t]++;
        }
        return ans;
    }
};
