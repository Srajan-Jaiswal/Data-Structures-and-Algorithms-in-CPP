#include <cmath>
#include <cstdio>
#include <vector>
#include<set>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    set<int> s;
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
    }
    cout<<s.size()<<endl;
    return 0;
}
