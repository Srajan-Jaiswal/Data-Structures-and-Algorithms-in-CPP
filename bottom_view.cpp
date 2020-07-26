#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data=d;
        left=right=NULL;
    }
    node* build()
    {
        int d;
        cin>>d;
        if(d==-1)
        {
            return NULL;
        }
        node* root=new node(d);
        root->left=build();
        root->right=build();
        return root;
    }
    void preorder(node* root)
    {
        if(root==NULL)
        {
            return;
        }
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    void bottom_view(node* root,int cur, int hd,unordered_map<int,pair<int,int>> &m)
    {
         if(root==NULL)
         {
            return; 
         }
         if(m.find(hd)!=m.end())
         {
             m[hd]=make_pair(root->data,curr);
         }
         else
         {
             pair<int,int> p=m[hd];
             if(p.second<=cur)
             {
                 m[hd].second=cur;
                 m[hd].first=root->data;
             }
         }
         bottom_view(root->left,curr+1,hd-1,m);
         bottom_view(root->right,curr+1,hd+1,m);
    }
    
   void  bottom_view_util(node *root)
    {
        unordered_map<int,pair<int,int>> m;
        bottom_view_util(root,0,0,m);
        for(auto it: m)
        {
            pair<int,int> p=it->second;
            cout<<p.first<<" ";
        }
    }
    int main()
    {
        node* root=build();
        bottom_view_util(root);
        return 0;
    }
    
    
    
    
    
    
    
    
    
    
    