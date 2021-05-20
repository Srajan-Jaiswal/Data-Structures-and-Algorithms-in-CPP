class Solution {
public:
    /**
     * @param length: the length of the array
     * @param updates: update operations
     * @return: the modified array after all k operations were executed
     */
    vector<int> getModifiedArray(int len, vector<vector<int>> &upd) {
        vector<int> ans(len, 0);
        for(int i=0; i<upd.size(); i++) {
            int start = upd[i][0];
            int end = upd[i][1];
            int inc = upd[i][2];   
            if(start>=0 && start<len) {
                ans[start] += inc;
            }
            if(end+1>=0 && end+1<len) {
                ans[end+1] -= inc;
            }
        }
        for(int i=1; i<len; i++) {
            ans[i] = ans[i] + ans[i-1];
        }
        return ans;
    }
};
