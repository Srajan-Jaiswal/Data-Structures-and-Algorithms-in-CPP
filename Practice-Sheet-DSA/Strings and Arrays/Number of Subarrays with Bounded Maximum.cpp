//Runtime: 32 ms, faster than 73.31% of C++ online submissions for Number of Subarrays with Bounded Maximum.
//Memory Usage: 32.4 MB, less than 42.37% of C++ online submissions for Number of Subarrays with Bounded Maximum.
class Solution {
public:
   
    int numSubarrayBoundedMax(vector<int>& arr, int left, int right) {
        int i=0,j=0,cnt=0,ans=0;
        while(j<arr.size()){
           // maxi = max(maxi,arr[j]);
            if(arr[j]>=left && arr[j]<=right){
                cnt=j-i+1;
                ans+=j-i+1;
                //cout<<cnt<<endl;
            }
            else{
                if(arr[j]<left){
                    ans+=cnt;
                }
                else{
                    i=j+1;
                    cnt=0;
                }
            }
            j++;
        }
        return ans;
    }
};
