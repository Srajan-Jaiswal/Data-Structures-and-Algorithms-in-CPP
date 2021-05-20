class Solution {
public:
 bool isLongPressedName(string name, string typed) {
        if(name.length() > typed.length()) return false;
        int start = 0,end = 0;
        while(start<name.size() && end<typed.size()){
            if(name[start] == typed[end]){
                start++;
                end++;
            }
            else if(start-1>=0 && name[start-1] == typed[end]) end++;
            else return false;
        }
        while(end<typed.size()){
            if(name[name.size()-1] != typed[end]) return false;
            end++;
        }
        if(start == name.size()) return true;
    }
};

