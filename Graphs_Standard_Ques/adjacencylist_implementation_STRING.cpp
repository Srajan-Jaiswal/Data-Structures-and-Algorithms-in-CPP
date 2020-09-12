#include<iostream>
#include<list>
#include<map>
using namespace std;
 template<typename T>
class Graph
{
	// if the graph is weighted we take a pair of (dest,wt) in a list
   //  for other data types such as string we cant use the array of linked list   
    map<T,list<T>> adjList;
  //map<T,list<pair<T,T>>>;
   public:
   	Graph()
   	{

   	}
   	void Addedge(T U, T V, bool bidrc)
   	{
      adjList[U].push_back(V); // inserting the element into the  list of map u value
      if(bidrc)
      {
      adjList[V].push_back(U);
      }
      
   	}
   void print()
   {
   	for(auto it:adjList)
   	{
     cout<<it.first<<"-->>";
   	
   	for(auto ll_t:it.second)
   	{
   		cout<<ll_t<<",";
   	}
   	cout<<endl;
    }
   }
};
int main()
{
	 Graph <string> g;
	 g.Addedge("Putin","Trump",false);
	 g.Addedge("Putin","Modi",false);
	 g.Addedge("Putin","Pope",false);
	 g.Addedge("Modi","Trump",true);
	 g.Addedge("Modi","Yogi",true);
	 g.Addedge("Yogi","Prabhu",false);
	 g.Addedge("Prabhu","Modi",false);
	 g.print();
	 return 0;
}



 // output::
/*Modi-->>Trump,Yogi,
Prabhu-->>Modi,
Putin-->>Trump,Modi,Pope,
Trump-->>Modi,
Yogi-->>Modi,Prabhu,/*