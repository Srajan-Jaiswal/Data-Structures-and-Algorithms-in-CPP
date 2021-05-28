class Solution {
public:
    unordered_map<char,int> um; 
    int firstUniqChar(string s) {
        for(char c : s) um[c]++;
        for(int i=0;i<s.length();i++){
            if(um[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};
