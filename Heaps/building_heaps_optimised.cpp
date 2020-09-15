#include<iostream>
#include<vector>
using namespace std;
void downheapify(vector<int> &heap, int idx)
{
 int left_idx=2*idx+1;
 int right_idx=2*idx+2;
 int largest_idx=idx;
 if(left_idx<heap.size() && heap[left_idx]>heap[largest_idx])
 {
 	largest_idx=left_idx;
 }
 if(right_idx<heap.size() && heap[right_idx]>heap[largest_idx])
{
	largest_idx=right_idx;
}
if(largest_idx==idx)
{ 
  return;
}
swap(heap[idx],heap[largest_idx]);
downheapify(heap,largest_idx);
}
void build_heap(vector<int> &heap)
{
  for(int i=heap.size()-1;i>=0;i--)
  {
  	downheapify(heap,i);
  }	
}
void display_heap(vector<int> &heap)
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
	build_heap(heap);
	display_heap(heap);
}
