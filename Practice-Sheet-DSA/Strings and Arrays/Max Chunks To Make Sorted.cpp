// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Max Chunks To Make Sorted.
// Memory Usage: 7.1 MB, less than 69.44% of C++ online submissions for Max Chunks To Make Sorted
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {    
        int ans = INT_MIN,cnt=0;
        for(int i=0;i<arr.size();i++){
            if(ans < arr[i]) ans = arr[i];
            if(ans == i) cnt++;
        }
        return cnt;
    }
};
