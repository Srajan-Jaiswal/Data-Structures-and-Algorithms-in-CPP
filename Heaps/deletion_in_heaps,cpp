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
void downheapify(vector<int> &heap, int idx)
{
  int left_idx = 2 * idx + 1;
  int right_idx = 2 * idx + 2;
  if (left_idx >= heap.size() && right_idx >= heap.size())
  {
    return;
  }
  int largest_idx = idx;                                            // storing index 0 int largest idx
  if (left_idx < heap.size() && heap[left_idx] > heap[largest_idx]) // checking for the left idx of heap[0] isn't grrater
  {
    largest_idx = left_idx;
  }
  if (right_idx < heap.size() && heap[right_idx] > heap[largest_idx]) // checking for the right idx of heap[0] isn't greater
  {
    largest_idx = right_idx;
  }
  if (largest_idx == idx)
  {
    return;
  }
  swap(heap[idx], heap[largest_idx]);
  downheapify(heap, largest_idx);
}
void delete_peek(vector<int> &heap, int key)
{
  int temp = heap[0];
  heap[0] = heap[heap.size() - 1];
  heap[heap.size() - 1] = temp;
  heap.pop_back();
  downheapify(heap, 0);
}
void insert(vector<int> &heap, int key)
{
  heap.push_back();
  upheapify(vector, heap.size() - 1);
}
void display(vector<int> &heap)
{
  for (int i = 0; i < heap.size() - 1; i++)
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
