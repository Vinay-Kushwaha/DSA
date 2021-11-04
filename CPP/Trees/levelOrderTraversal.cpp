//Problem: https://leetcode.com/problems/binary-tree-level-order-traversal/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* A) {
        
        vector<vector<int>> ans;
        if(!A) return ans;
        ans.clear();
        queue<TreeNode*>q;
        q.push(A);
        int level=0;
        while(!q.empty()){
            vector<int>v;
            int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode* root = q.front();
            q.pop();
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
            v.push_back(root->val);
        }
            ans.push_back(v);
            level++;
            v.clear();
        }
    return ans;
        
    }
};