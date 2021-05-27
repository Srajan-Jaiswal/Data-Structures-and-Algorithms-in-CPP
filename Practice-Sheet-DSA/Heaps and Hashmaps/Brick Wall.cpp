class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        for(auto &w : wall){
            for(int i=1;i<w.size();i++){
                w[i] += w[i-1];
            }
        }
        unordered_map<int,int> um;
        int max_line = 0;
        for(auto line : wall){
            for(int i=0;i<line.size()-1;i++){
                um[line[i]]++;
                max_line = max(max_line,um[line[i]]);
            }
        }
        return wall.size()-max_line;
    }
};
