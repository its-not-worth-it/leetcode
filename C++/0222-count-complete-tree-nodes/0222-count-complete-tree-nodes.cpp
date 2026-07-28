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

    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int l=count(root->left), r=count(root->right);
        if(l==r) return (1<<l) + countNodes(root->right);
        return (1<<r) + countNodes(root->left);
    }
    int count(TreeNode *root){
        int ans=0;
        while(root){
            ans++;
            root=root->left;
        }
        return ans;
    }
};