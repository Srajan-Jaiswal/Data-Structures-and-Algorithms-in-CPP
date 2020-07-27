#include<bits/stdc++.h>
using namespace std;

vector<int> print_subarr_0_sum(int *arr,int n)
{
	unordered_map<int,vector<int>> um;
	vector<pair<int,int>> ans;
    int pr=0;
    for(int i=0;i<n;i++)
    {
    	pr+=arr[i];
       if(pr==0)
       {
       	ans.push_back(make_pair(0,i));
       }
       if(um.find(pr)!=um.end())
       {
        vector<int> vc = map[pr];
        for(auto it=vc.begin(); it!=vc.end();it++)
        {
        	ans.push_back(make_pair((*it+1),i));
        }
       }
       map[pr].push_back(i);
    }
    return ans;
}

void print_subarr(vector<pair<int,int>> &ans)
{
	for(auto it=ans.begin(); it!= ans.end(); it++)
	{

		cout<<it->first<<"to"<<it->second<<endl;
	}
}
void find_max_subarr(vector<pair<int,int>> &ans)
{
for(auto it=ans.begin(); it!= ans.end(); it++)
	{
     vector<int> max;
     int temp=0;
     temp=(it->second - it->first);
     max.push_back(temp)
		temp=0;
	}
  sort(max.begin(),max.end());
   int fin_ans= max.end();
   cout<<fin_ans<<endl;
}
int main()
{
	int n;
	cin>>n;
	int *arr= new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr;
	}


}