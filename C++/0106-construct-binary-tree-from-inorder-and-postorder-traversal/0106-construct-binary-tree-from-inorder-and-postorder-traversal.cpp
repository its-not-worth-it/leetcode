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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size(); 

        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }

        return help(postorder, 0, n-1, inorder, 0, n-1, m);
    }

    TreeNode* help(vector<int> &postorder, int stpost, int endpost, vector<int> &inorder, int stin, int endin, unordered_map<int,int> &m){
        if(stpost > endpost or stin > endin) return nullptr;

        // cout<<stpost<<" "<<endpost<<endl;
        TreeNode *root= new TreeNode(postorder[endpost]);
        int inroot=m[postorder[endpost]];
        int rem=inroot-stin;

        root->left= help(postorder, stpost, stpost+rem-1, inorder, stin, inroot-1, m);
        root->right= help(postorder, stpost+rem, endpost-1, inorder, inroot+1, endin, m);

        return root;
    }
};