#include <iostream>
#include <queue>
using namespace std;
void print_run_int(double *arr, int n)
{
  priority_queue<double> max_heap;
  priority_queue<double, vector<double>, greater<double>> min_heap;

  double med = arr[0];
  max_heap.push(arr[0]);

  cout << med << endl;

  for (int i = 0; i < n; i++)
  {
    double x = arr[i];
    if (min_heap.size() > max_heap.size())
    {
      if (x < med)
      {
        min_heap.top();
        min_heap.pop();
        max_heap.push(min_heap.top());
        min_heap.push(x);
      }
      else
      {
        max_heap.push(x);
      }
      med = (max_heap.top() + min_heap.top()) / 2.0;
    }
    else if (min_heap.size() == max_heap.size())
    {
      if (x < med)
      {
        min_heap.push(x);
        med = (double)min_heap.top(); // typecasting
      }
      else
      {
        max_heap.push(x);
        med = (double)max_heap.top();
      }
    }
    else
    {
      if (x > med)
      {
        max_heap.top();
        max_heap.pop();
        min_heap.push(min_heap.top());
        max_heap.push(x);
      }
      else
      {
        min_heap.push(x);
      }
      med = (max_heap.top() + min_heap.top()) / 2.0;
    }
    cout << med << endl;
  }
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    double arr[n];
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    print_run_int(arr, n);
  }
  return 0;
}