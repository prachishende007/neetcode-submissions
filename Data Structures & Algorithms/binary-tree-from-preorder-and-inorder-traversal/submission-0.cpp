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
    unordered_map<int, int> inMap;
    int preIndex = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i<inorder.size(); i++){
            inMap[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size()-1, inorder);
    }

    TreeNode* build(vector<int> &preorder, int inStart, int inEnd, vector<int> &inorder){
        if(inStart > inEnd){
            return nullptr;
        }

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        int pos = inMap[rootVal];

        root->left = build(preorder, inStart, pos - 1, inorder);
        root->right = build(preorder, pos+1, inEnd, inorder);

        return root;
    }
};
