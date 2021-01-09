#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s);
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        cout<<reverseWords(s)<<endl;
    }
}// } Driver Code Ends


string reverseWords(string S) 
{ 
    if(S.length()==1)
    {
        return S;
    }
    vector<string> ans;
    string temp = ""; 
    for(int i=0;i<S.length();i++)
    {
         if(S[i] != '.'){
            temp += S[i]; 
         }
         
        if(S[i]=='.' || i==S.length()-1)
        {
            ans.push_back(temp);
            temp.clear();
        }
    
    }
    string rev="";
    for(int i=ans.size()-1;i>=0;i--){
        string a = ans[i];
        rev += a;
        if(i!=0){
        rev +='.';
        }
    }
    return rev;
} 
