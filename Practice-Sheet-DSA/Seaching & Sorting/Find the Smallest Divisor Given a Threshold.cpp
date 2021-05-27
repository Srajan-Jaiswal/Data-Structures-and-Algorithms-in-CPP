class Solution {
public:
    bool check(vector<int> &nums,int m,int threshold){
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += ceil((double)nums[i]/m);
            if(sum > threshold) return  false;
        }
        return  true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
    sort(nums.begin(),nums.end());   
    int low = 1;
    int high = nums[nums.size()-1];
    int ans;    
    while(low <= high){
        int mid = (low + high)/2;
        if(check(nums,mid,threshold)){
             ans = mid;
             high = mid-1;
        }
        else{
            low = mid+1;
        }
      }
      return  ans;     
   }
};
     
           
           
          
