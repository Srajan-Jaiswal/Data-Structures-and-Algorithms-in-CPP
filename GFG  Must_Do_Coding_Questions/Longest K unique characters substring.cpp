#include <iostream>
#include<unordered_map>
using namespace std;
unordered_map<char,int> m;
int kunique(string str, int k)
{
   int ans = 0;
   int i=0,j=0;
   while(i<str.length())
   {
     m[str[i]]++;
     int len = m.size();
     if(len<k)
     {
         i++;
     }
     else if(len == k){
      ans = max(ans,i-j+1);
     i++;
     }
     else if(len>k)
     {
             m[str[j]]--;
             if(m[str[j]]==0)
             {
                m.erase(str[j]); 
                ans = max(ans,i-j);
             }
            
         j++;
     }
       
   }
   return ans;
}
int main() {
    int  t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int k;
        cin>>k;
        cout<<kunique(s,k)<<endl;
    }
	return 0;
}
