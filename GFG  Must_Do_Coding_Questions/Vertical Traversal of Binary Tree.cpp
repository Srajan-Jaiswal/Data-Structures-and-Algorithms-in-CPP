class Solution
{
    public:
    map<int,vector<int>> m;
    void dfs(Node* root , int hd){
        if(root==nullptr) return;
        m[hd].push_back(root->data);
        dfs(root->left , hd-1);
        dfs(root->right, hd+1);
    }
    vector<int> verticalOrder(Node *root)
    {
        vector<int> ans;
        //int hd  = 0;
        dfs(root,0);
        for(auto it : m){
            for(int i=0;i<it.second.size();i++){
                ans.push_back(it.second[i]);
            }
        }
        return ans;
    }
};
