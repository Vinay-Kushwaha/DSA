//Problem: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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


TreeNode* Create(vector<int>& inorder, vector<int>& preorder, int start, int end, int* pos){
    if(start>end) return NULL;
    
    TreeNode *root = new TreeNode(preorder[*pos]);
    (*pos)++;
    
    int index=-1;
    auto it = find(inorder.begin()+start,inorder.begin()+end, root->val);
    index = it-inorder.begin();
    
    root->left = Create(inorder,preorder,start, index-1, pos);
    root->right = Create(inorder,preorder,index+1, end, pos);


    return root;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pos=0;
        TreeNode *root = Create(inorder, preorder, 0,inorder.size()-1,&pos);
        return root;
    }
};