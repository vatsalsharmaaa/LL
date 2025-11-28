class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};

        vector<vector<int>> result;
        vector<int> level1;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty())
        {
            int n = q.size();
            level1.clear(); // clear before starting a level

            while(n--)
            {
                TreeNode* temp = q.front();
                q.pop();

                
                if(level % 2 == 0)
                    level1.push_back(temp->val);
                else
                    level1.insert(level1.begin(), temp->val);

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            result.push_back(level1);
            level++;
        }

        return result;
    }
};
