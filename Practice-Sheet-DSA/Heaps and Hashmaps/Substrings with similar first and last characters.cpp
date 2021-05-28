class Solution{
public:	
    
    int fact(int num){
        if(num==1 || num==2){
            return num;
        }
        num += fact(num-1);
        return num;
    }
	int countSubstringWithEqualEnds(string s)
	{ 
	    unordered_map<char,int> um;
	    for(auto c : s){
	        um[c]++;
	    }
	    int sum = 0;
	    for(auto it : um){
	        if(it.second>=2) sum+=1;
	        sum += fact(it.second);
	    } 
	  return sum;
	}
};
