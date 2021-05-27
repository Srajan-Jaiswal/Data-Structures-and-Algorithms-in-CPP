class Solution {
public:
   Node* connect(Node* root)
     {
     if(root==NULL || (root->left==NULL && root->right==NULL)) return root;
     queue<Node*> q;
     q.push(root);
     q.push(NULL); 
      while(q.size()>1)
      {
          while(q.front()!=NULL)
          {
              Node* r=q.front();
              q.pop();
              r->next = q.front();
              if(r->left!=NULL) q.push(r->left);
              if(r->right!=NULL) q.push(r->right);
          }
          q.pop();
          q.push(NULL);
      }
      return root;
}
};
