class Solution {
public:
    vector<int> NGE(vector<int> &nums2 , vector<int> &help){
        stack<int> stk;
        int n = nums2.size();
        stk.push(nums2[n-1]);
        help[n-1] = -1;
        for(int i=n-2;i>=0;i--){
            if(nums2[i]<stk.top()){
                 help[nums2[i]]=stk.top();
                stk.push(nums2[i]);      
            }
            else{
                while(!stk.empty() &&  stk.top()<=nums2[i]){
                    stk.pop();
                } 
                if(!stk.empty()) help[nums2[i]]=stk.top();
                else  help[nums2[i]]=-1;
                stk.push(nums2[i]);
            }
        }
        return help;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()==1) return nums2;
        vector<int> help(10001,-1);
        NGE(nums2,help);
        vector<int> ans(nums1.size(),0);
        for(int i=0;i<nums1.size();i++){
          ans[i] = help[nums1[i]];  
        }
        return ans;
    }
};
