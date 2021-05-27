class Solution {
public:
    unordered_map<char,int> um;  
    char ans;
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(char c:letters) um[c]++;
        int high = letters[letters.size()-1] - 'a';
        if((um.find(target) == um.end() && target-'a'>high) || letters[letters.size()-1]==target)  return letters[0];
        int i = (target - 'a');   
        while(i<26){
            if((i+'a') > target && um.find(i+'a') != um.end()){
                ans = i+'a';
                break;
            }
            i++;
        }
        return ans;
    }
};
