class Solution
{
    private:
    void rec(Node* a, Node* b, long long& sum) {
        if(!a || !b)
            return;
            
        sum += a->data*b->data;
        
        rec(a->left, b->right, sum);
        rec(a->right, b->left, sum);
    }
    
    public:
    long long imgMultiply(Node *root)
    {
        if(!root)
            return 0;
            
        long long sum = root->data*root->data;
        
        if(root->left)
            rec(root->left, root->right, sum);
        
        sum = sum % (long long)(1e9+7);
        return sum;
    }
};
