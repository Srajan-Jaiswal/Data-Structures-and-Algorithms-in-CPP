#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2)
{ 
  return p1.second<p2.second;
} 
int main()
{
  int t,n,s_t,e_t;
  vector<pair<int ,int> > vec; 
  cin>>t;
  while(t--)
  {
  	cin>>n;
  	for(int i=0;i<n;i++)
  	{
  		cin>>s_t>>e_t;
      vec.push_back(make_pair(s_t,e_t));
  	}

  	sort(vec.begin(),vec.end(), compare);
    int count=1;
    int fin=vec[0].second;
    for(int i=1;i<n;i++)
    {
    	if(vec[i].first >= fin)
    	{
    		fin=vec[i].second;
    		count++;
    	}
    }
    cout<<count<<endl;
    vec.clear();
  }
}