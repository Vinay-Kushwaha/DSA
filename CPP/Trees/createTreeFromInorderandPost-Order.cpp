//Problem: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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

// int pos=postorder.size()-1

TreeNode* Create(vector<int>& inorder, vector<int>& postorder, int start, int end, int* pos){
    if(start>end) return NULL;
    
    TreeNode *root = new TreeNode(postorder[*pos]);
    (*pos)--;
    
    int index=-1;
    auto it = find(inorder.begin()+start,inorder.begin()+end, root->val);
    index = it-inorder.begin();
    
    //cout<<index<<" "<<root->val<<endl;
    
    root->right = Create(inorder,postorder,index+1, end, pos);
    root->left = Create(inorder,postorder,start, index-1, pos);

    return root;
}

class Solution {
public:
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pos=postorder.size()-1;
        TreeNode *root = Create(inorder, postorder, 0,inorder.size()-1,&pos);
        return root;
    }
};