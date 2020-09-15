#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void kth_small_ele(int *arr, int n,int k)
{
	priority_queue<int, vector<int>,greater<int>> pq;
    for(int  i=0;i<n;i++)
    {
    	pq.push(arr[i]);
    }
    for(int j=0;j<=k-1;j++)
    {
    int res_util= pq.top();
    pq.pop();
    }
    int res_util=pq.top();
    cout<<res_util<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int k;
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		kth_small_ele(arr,n,k);
	
	return 0;
}
}