#include <iostream>
#include <vector>
using namespace std;
void upheapify(vector<int> &heap, int idx)
{
	if (idx == 0)
	{
		return;
	}
	int parent_idx = (idx - 1) / 2;
	if (heap[parent_idx] < heap[idx])
	{
		int temp = heap[parent_idx];
		heap[parent_idx] = heap[idx];
		heap[idx] = temp;
		upheapify(heap, parent_idx);
	}
	else
	{
		return;
	}
}
void build_heap(vector<int> &heap)
{
	for (int i = 0; i < heap.size(); i++)
	{
		upheapify(heap, i);
	}
}
void display_heap(vector<int> &heap)
{
	for (int i = 0; i < heap.size(); i++)
	{
		cout << heap[i] << ",";
	}
	cout << endl;
}
int main()
{
	vector<int> heap;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		heap.push_back(x);
	}
	build_heap(heap);
	display_heap(heap);
	return 0;
}
