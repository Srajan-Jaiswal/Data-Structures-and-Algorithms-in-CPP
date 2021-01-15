#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n;
	    int a[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    int k;
	    cin>>k;
	    queue<int>q;
	    for(i=0;i<k;i++)
	    {
	        if(a[i]<0)
	        {
	            q.push(i);
	        }
	    }
	    for(i=k;i<n;i++)
	    {
	        if(q.empty())
	        {
	            printf("0 ");
	        }
	        else
	        {
	           cout<<a[q.front()<<" ";
	        }
	        while(!q.empty()&&q.front()<i-k+1)
	        {
	            q.pop();
	        }
	        if(a[i]<0)
	        {
	            q.push(i);
	        }
	    }
	    if(q.empty())
	    {
	        cout<<0<<" ";
	    }
	    else
	    {
	        printfa[q.front()<<" ";
	    }
	}
	return 0;
}
