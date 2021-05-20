class Solution {
public:
    vector<int> arr[100001];
    int BFS(int src,int tar,vector<bool> &vis){
        map<int,int> dist;
         for(int i=0;i<100001;i++){
    	    dist[i]= INT_MIN;
        }
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        parent[src]= src;
        int cnt=0;
        while(!q.empty()){
            //int s = q.size();
            int fr = q.front();
            q.pop();
            //cout<<fr<<endl;
            //if(fr==tar) return cnt;
            for(auto it : arr[fr]){
                if(dist[it] == INT_MIN){
	 		        q.push(it);
	 		        dist[it]=dist[fr]+1;
                    parent[it]=fr; 
	 	        }
            } 
        
        }
        if(dist[tar]!=INT_MIN) return dist[tar];
        else return -1;
    }
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        for(vector<int> &r : routes){
            for(int i=0;i<r.size()-1;i++){
              for(int j=i+1;j<r.size();j++) 
                if(r.size()>1 && r[i]!=r[j]){
                    arr[r[i]].push_back(r[j]);   
                }
            }
            for(int i=r.size()-1;i>0;i--){
                for(int j=r.size()-2;j>=0;j--){ 
                    if(r.size()>1&& r[i]!=r[j]){
                        arr[r[i]].push_back(r[j]);
                    }
                }
            }
        }
        vector<bool> vis(100001,0);
         return BFS(source,target,vis);
        /*for(int i=0;i<100001;i++){
            vector<int> temp = arr[i];
            cout<<i<<"->>"<<" ";
            for(int i=0;i<temp.size();i++){
                cout<<temp[i]<<" ";
            }
            cout<<endl;
        }*/
        //return 1;
    }
};
