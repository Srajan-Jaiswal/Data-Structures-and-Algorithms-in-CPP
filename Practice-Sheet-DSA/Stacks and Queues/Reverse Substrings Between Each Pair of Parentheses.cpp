class Solution {
public:
    stack<char> stk;
    string reverseParentheses(string s) {
        string curr = "";
        string ans = "";
        for(int i=0;i<s.length();i++){
           if(!stk.empty() && s[i]==')'){
               while(stk.top() != '('){ 
               curr += stk.top();       // co
                   stk.pop();
                }
                stk.pop();
               for(auto c : curr){
                   stk.push(c);
               }
               curr="";
           }  
           else{
               stk.push(s[i]);
           }     
         }
         while(!stk.empty()){
             ans += stk.top();
             stk.pop();
         }
         reverse(ans.begin(),ans.end());
         return ans;
        }
};
