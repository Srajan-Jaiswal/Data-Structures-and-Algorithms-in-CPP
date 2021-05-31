 class Values{
   public:  
    int right_slop = -1;
    int left_slop = -1;
    int max_len = 0;
   };
class Solution {
public:
   Values *ans = new Values();
   void Dfs_Zigzag(TreeNode* root){
        if(root == nullptr){
            return;
        }
        Values left = Dfs_Zigzag(root->left);
        Values right  = Dfs_Zigzag(root->right);
        ans = max(max(left.max_len,right_max_len),(left.left_slop,right.right_slop)+1);
        ans.left_slop = left.right_slop+1;
        ans.right_slop = right.left_slop+1;
        return;
    }
    int longestZigZag(TreeNode* root) {
        Dfs_Zigzag(root);
        Values fin_ans = ans;
        return fin_ans.max_len;
    }
};
