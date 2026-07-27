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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        return help(preorder, 0, n-1, inorder, 0, n-1, m);
    }
    TreeNode* help(vector<int> &preorder, int stpre, int endpre, vector<int> &inorder, int stin, int endin, unordered_map<int,int> &m){
        if(stpre > endpre or stin > endin) return nullptr;
        
        TreeNode *root=new TreeNode(preorder[stpre]);

        int inroot=m[preorder[stpre]];
        int rem=inroot-stin;
        root->left=help(preorder, stpre+1, stpre+rem, inorder, stin, inroot-1, m);
        root->right=help(preorder, stpre+rem+1, endpre, inorder, inroot+1, endin, m);

        return root;
    }
};