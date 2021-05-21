class Solution {
public:
    vector<int> adjlst[2001];
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
          vector<int> indeg(numCourses,0); 
          for(int i=0;i<pre.size();i++){
              vector<int> vec = pre[i];
              indeg[vec[0]]++;
              //cout<<vec[1]<<vec[0]<<endl;
              adjlst[vec[1]].push_back(vec[0]);
          }
          queue<int> q;
          vector<bool> vis(numCourses,false);
          vector<int> ans;
          for(int i=0;i<indeg.size();i++){
              if(indeg[i] == 0){
                  q.push(i);
                  vis[i]=true;
              }
          }
          while(!q.empty()){
              int curr = q.front();
              ans.push_back(curr);
              q.pop();
              for(auto it : adjlst[curr]){
                  indeg[it]--;
                  if(indeg[it] == 0){
                      q.push(it);
                      vis[it]=true;
                  }
              }
          }
          for(int i=0;i<numCourses;i++){
              if(!vis[i]){
                  ans.clear();
                  return ans;
              }
          }
        return ans;
    }
};
