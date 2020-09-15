#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
void upheapify(vector <int> &heap, int idx)
{
     if(idx==0)
     {
     	return;
     }

	int parent_idx=(idx-1)/2;
  if(heap[parent_idx]<heap[idx])
  	{
  		int temp=heap[parent_idx];
  		heap[parent_idx]=heap[idx];
  		heap[idx]=temp;
  		upheapify(heap,parent_idx);
  	}
  	else
    {
    return; 
    }
}
void deleting_node(vector <int> heap, int data)
{
   for(int i=0;i<heap.size();i++)
   {
   	if(heap[i]==data)
   	{
   		double inf=INFINITY;
   		int temp=heap[i];
   		heap[i]=inf;
   		upheapify(heap,i);
   	}
   }
}
void buildheap(vector <int> &heap, int key)
{
	for(int i=0;i<heap.size();i++)
	{
		upheapify(heap,i); 
	}
}
void print(vector<int> &heap)
{
	for(int i=0;i<heap.size();i++)
	{
      cout<<heap[i]<<",";
	}
	cout<<endl;
}
int main()
{
	vector<int> heap;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
      int x;
      cin>>x;
      heap.push_back(x);
	}
	buildheap(heap,key);
	print(heap);
	deleting_node(heap,data);
	print(heap);
	return 0;

}
