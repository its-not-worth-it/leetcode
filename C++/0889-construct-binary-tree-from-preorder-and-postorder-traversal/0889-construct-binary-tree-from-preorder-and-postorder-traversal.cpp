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
    int x=0, y=0;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode *root=new TreeNode(preorder[x]);
        x++;
        if(root->val != postorder[y]){
            root->left=constructFromPrePost(preorder, postorder);
        }
        if(root->val != postorder[y]){
            root->right=constructFromPrePost(preorder, postorder);
        }

        y++;
        return root;
    }
};