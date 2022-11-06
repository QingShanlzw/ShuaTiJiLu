/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型vector<vector<>>
     */
     vector<vector<int>>res;
     queue<TreeNode*>q;
     vector<int>temp;
    vector<vector<int> > levelOrder(TreeNode* root) {
        // write code here
        if(!root)return res;
        q.push(root);
        while(!q.empty()){
            int len  = q.size();
            while(len--){
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};




