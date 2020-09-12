#include<iostream>
#include<list>
using namespace std;
int main()
{
	int v;
	cin>>v;
	list<pair<int,int>> *l;  // dynamic list
    l= new list<pair<int,int>>[v];  // is nothing but only the simple syntax of dynamic allocation of the memory in linked-list 
   
    int e;
    cin>>e;
    // loop run across edges
    for(int i=0;i<e;i++)
    {
    	int x,y,wt;
    	cin>>x>>y>>wt;
    	// simply pushing the x node and the linked list elements are y,wt
    	l[x].push_back(make_pair(y,wt));
    	l[y].push_back(make_pair(x,wt));
    }
    // print the output
    for(int i=0;i<v;i++)
    {    // for printing the pair
    	cout<<"Linked list"<<i<<"-->";
    	for(auto xp:l[i])
      {
      	cout<<"("<<xp.first<<","<<xp.second<<")";
      }
      cout<<endl;
    }
return 0;
}
