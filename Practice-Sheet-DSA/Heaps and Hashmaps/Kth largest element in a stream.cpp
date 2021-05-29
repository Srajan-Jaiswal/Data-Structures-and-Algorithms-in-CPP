class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        vector<int> ans;
        priority_queue<int,vector<int>,greater<int>> min_heap; 
        for(int i=0;i<n;i++){
            if(min_heap.size() < k){
                min_heap.push(arr[i]);
            }    
            else{
                if(arr[i] > min_heap.top()){
                    int t = min_heap.top();
                    min_heap.pop();
                    ans.push_back(t); 
                    min_heap.push(arr[i]);
                }
                else{
                    ans.push_back(min_heap.top()); 
                }
            }
            if(min_heap.size()<k) ans.push_back(-1);
        }
        ans.push_back(min_heap.top());
        return ans;
    }
};
