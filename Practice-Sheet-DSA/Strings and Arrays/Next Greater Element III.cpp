class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> temp;
        int m = n;
        while(m){
            temp.push_back(m%10);
            m/=10;
        }
        reverse(temp.begin(),temp.end());
        if(next_permutation(temp.begin(),temp.end())){
            long l = 0;
            for(int i=0;i<temp.size();i++)
                l = l*10+temp[i];
            if(l<=INT_MAX)
                return l;
        }
        return -1;
    }
};
