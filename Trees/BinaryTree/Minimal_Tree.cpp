TreeNode* makeTree(vector<int> &A, int start, int end)
{
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(A[mid]);
    root->left = makeTree(arr, start, mid-1);
    root->right = makeTree(arr, mid+1, end);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A)
{
    return makeTree(A, 0, A.size()-1);
}

// Construct maximum tree
TreeNode* makeTree(vector<int> &A, int start, int end)
{
    if (start > end) return NULL;
    int maxIndex = max_element(A.begin()+start, A.begin()+end+1) - A.begin();
    TreeNode* root = new TreeNode(A[maxIndex]);
    root->left = makeTree(A, start, maxIndex-1);
    root->right = makeTree(A, maxIndex+1, end);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A)
{
    return makeTree(A, 0, A.size()-1);
}
​
