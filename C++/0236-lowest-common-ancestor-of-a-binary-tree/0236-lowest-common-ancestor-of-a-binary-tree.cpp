/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans=nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        help(root, p, q);
        return ans;
    }
    int help(TreeNode* root, TreeNode* p, TreeNode* q){
        if(ans) return 0;
        if(!root) return 0;

        int a=0;
        if(root->val==p->val or root->val==q->val) a++;

        a=a+help(root->left, p, q)+help(root->right, p, q);
        // cout<<root->val<<" "<<a<<endl;
        if(a==2) {
            ans=root; 
            a=0;
        }
        
        return a;

    }
};