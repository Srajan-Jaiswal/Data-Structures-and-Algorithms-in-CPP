class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    {   
        int res = 0;
        int i=0,j=0,sum=0;
        while(j<N){
            sum+=A[j];
            j++;
            if(sum==K){
                //cout<<j<<endl;
                res = max(res,j-i);
                while(i<j && sum>=K){
                    sum -= A[i];
                    i++;
                    //cout<<sum<<endl;
                }
            }
        }
        return res;
    } 
