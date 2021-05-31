    long long sum = 0;
void printInorder(Node* rootL, Node* rootR)
   {
        if (rootL->left == NULL && rootR->right == NULL)return;
        printInorder(rootL->left, rootR->right);
        if(rootL->left!=nullptr || rootR->right!=nullptr){
        sum+=(rootL->left->data)*(rootR->right->data);
        }
        printInorder(rootL->right, rootR->left);
        return ;
   }
    long long imgMultiply(Node *root)
    {
       if(root==nullptr) return 0;
       printInorder(root,root);
       return sum+(root->data)*(root->data);
    }
};
