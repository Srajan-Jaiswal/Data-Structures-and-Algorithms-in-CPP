#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   string str1,str2;
    cin>>str1>>str2;
    int cnt=0,ans;
    int j=1;
    if(str1.length()-str2.length()>1)
    {
        cout<<0<<endl;
    }
    else{
    for(int i=1;i<=str1.length();i++)
    {
        if(str1[j]==str2[i])
        {
            j++;
            continue;
        }
        else{
            cnt++;
            j=j+2;
            ans=i+1;
        }
        
    }
        if(cnt==1)
        {
            cout<<ans<<endl;
        }
        else{
            cout<<0<<endl;
        }
        
    }
    
    
    return 0;
}
