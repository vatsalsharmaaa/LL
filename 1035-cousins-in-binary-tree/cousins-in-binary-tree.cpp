class Solution {
public:
   bool checkparent(TreeNode* root, int a, int b){
    if(root==nullptr)return false;
    if(root->left && root->right){
    if(root->left->val ==a && root->right->val==b) return true ;
    if(root->left->val ==b && root->right->val==a) return true ;
    
    }
    return checkparent (root->left,a,b) || checkparent (root->right ,a,b);
   }

    bool isCousins(TreeNode* root, int x, int y) {
      
      queue<TreeNode * >q;
      q.push(root);
      int l1=-1;
      int l2=-1;
      int level=0;
      while(!q.empty()){
        int n=q.size();
        while(n--){
            TreeNode * temp=q.front();
            q.pop();
            if(temp->val==x)
            l1=level;
            if(temp->val==y)
            l2=level;
            if(temp->left!=NULL)
            q.push(temp->left);
             if(temp->right!=NULL)
            q.push(temp->right);
        }
        level++;
        if(l1!=l2)
        return false;
        if(l1!=-1&&l2!=-1) break;
      }
        return !checkparent(root,  x, y);
    }
   
};