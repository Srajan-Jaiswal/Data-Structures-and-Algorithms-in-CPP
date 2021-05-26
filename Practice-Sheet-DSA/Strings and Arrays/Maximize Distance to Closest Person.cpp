class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int len=0,high,low,fin_low;
        int max_len = 0;
        bool flag = true;
        for(int i=0;i<seats.size()-1;i++){
            if(seats[i] == 0 && seats[i+1]==0){
               if(flag){
                  low = i;  
                  flag=false; 
                }
                len++;
                //flag=true;
                if(len >= max_len){
                    fin_low=low;
                    high = i+1;
                    max_len = len;
                }
            }
            else{
                flag=true;     
                len=0;
            }
        }
        max_len++;
        cout<<max_len<<endl;
        cout<<fin_low<<endl;
        cout<<high<<endl;
        if( (high==seats.size()-1 || fin_low == 0)) return max_len;
        if(max_len%2==1) return max_len/2+1;
        else return max_len/2;
    }
};
