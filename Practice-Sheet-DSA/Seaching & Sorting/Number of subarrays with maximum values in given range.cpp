 int i=0,j=0,cnt=0,ans=0;
        bool flag = true;
        while(j<arr.size()){
            if(arr[j]>=left && arr[j]<=right){
                cnt=j-i+1;
                ans+=j-i+1;
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
