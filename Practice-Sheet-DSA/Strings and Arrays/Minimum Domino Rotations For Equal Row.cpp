class Solution {
public:
    int ans = INT_MAX;
    int minDominoRotations_util(vector<int>& tops, vector<int>& bottoms) {
        vector<int> temp;
        for(int i=1;i<=6;i++){
            temp.clear();
            for(int j=0;j<tops.size();j++){
                if(tops[j] != i){
                    temp.push_back(j);
                }
            }
            bool flag = true;
            for(auto k : temp){
                if(bottoms[k] != i){
                    flag = false;
                    break;
                }
            }
            if(!flag) continue;
            else{
               int a = temp.size();
               ans = min(ans,a);
            }
        }
        if(ans==INT_MAX) return -1;
        else return ans;
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    int a = minDominoRotations_util(tops,bottoms);
    int b = minDominoRotations_util(bottoms,tops);
    return min(a,b);   
    }
};
