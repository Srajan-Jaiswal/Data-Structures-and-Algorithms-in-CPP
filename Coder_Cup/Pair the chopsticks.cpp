#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<unordered_map>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

        int n;
      cin>>n;
       int arr[n];
    unordered_map<int,int> m;
    int cnt=0;
     for(int i=0;i<n;i++)
     {
         cin>>arr[i];
     }
    for(int i=0;i<n;i++)
     {
         m[arr[i]]++;
     }
    for(auto it: m)
    {
       if(it.second>=2)
       {
           if(it.second==2)
           {
           cnt++;
           }
           else{
               cnt+=it.second/2;
           }
       }
    } 
    cout<<cnt<<endl;
    return 0;
}
