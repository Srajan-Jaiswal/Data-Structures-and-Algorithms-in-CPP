class Solution {
public:
    bool  preorder(TreeNode* root, TreeNode* subRoot){
        if(root==nullptr && subRoot == nullptr) return true;
        if(subRoot==nullptr || root==nullptr) return false;
        if(root->val != subRoot->val){
         return false;    
        }
        bool left = preorder(root->left,subRoot->left);
        bool right= preorder(root->right,subRoot->right);
        return left && right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr) return true; // if both are null return true
        if(subRoot == nullptr) return true; // only subtree is null return true
        else if(root == nullptr)   // root is null return  false
        return false;
        return preorder(root,subRoot) ||isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
 
