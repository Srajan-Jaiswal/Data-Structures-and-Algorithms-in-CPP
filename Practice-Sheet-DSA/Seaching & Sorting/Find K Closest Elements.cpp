class Solution {
public:
    vector<int> ans;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        if(idx==0){
            for(int i=0;i<k;i++){
                ans.push_back(arr[i]); 
            } 
            return ans;
        }
        cout<<idx<<endl;
        if(k%2==1){
            if(idx+(k-1)/2  <= arr.size()-1){
            for(int i=(idx-(k-1)/2);i<=(idx+(k-1)/2) ; i++){
                ans.push_back(arr[i]);
            }
            }
            else{
                int diff = idx+(k-1)/2 - (arr.size()-1);
                for(int i=(idx-(k-1)/2-diff);i<=arr.size()-1; i++){
                ans.push_back(arr[i]);
            }
            }
        }
        
        else{
            if(idx+(k)/2  <= arr.size()-1){
            for(int i=(idx-(k)/2);i<(idx+(k)/2) ; i++){
                ans.push_back(arr[i]);
            }
            }
            else{
                int diff = (idx+(k)/2)-1 - (arr.size()-1);
                cout<<diff<<endl;
                for(int i=(idx-(k)/2-diff);i<=arr.size()-1; i++){
                ans.push_back(arr[i]);
            } 
        }
        }
        return ans;
    }
};
