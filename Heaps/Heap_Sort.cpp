#include<iostream>
using namespace std;
void upheapify(int *arr,int idx)
{
   if(idx==0)
   {
   	return;
   }
   int parent_idx=(i-1)/2;
   if(arr[parent_idx]<arr[idx])
   {
   	int temp=arr[parent_idx];
   	arr[parent_idx]=arr[idx];
   	arr[idx]=temp;
    upheapify(arr, parent_idx);
   }
}
void downheapify(int *arr,int idx)
{
  int left_idx=(i*2)+1;
  int right_idx=(i*2)+2;
  int largest_idx=idx;
  if(left_idx<arr.size() && arr[left_idx]>arr[largest_idx])
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
void build_heap(int *arr, int n)
{
 for(int i=0;i<n;i++)
 {
 	upheapify(heap,i)
 }
}
void print_heap(int *arr)
{
	for(int i=0;i<n;i++)
 {
 	cout<<arr[i]<<",";
 }
 cout<<endl;
}
void heapsort(int *arr,int n)
{
	build_heap(arr,n);
	print_heap(arr);
	for(int i=n;i>=2;i--)
	{
		swap(arr[i],arr[n]);
	}
	downheapify(arr,i);
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
	return 0;
}
