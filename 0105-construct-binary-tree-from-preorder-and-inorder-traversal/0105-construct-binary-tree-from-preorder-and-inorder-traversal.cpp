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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd){
        if(preStart > preEnd || inStart > inEnd){
            return NULL;
        }
        
        int rootVal = preorder[preStart];
        int rootIndex = inStart;

        while(inorder[rootIndex] != rootVal){
            rootIndex++;
        }

        int leftSize = rootIndex - inStart;
        
        TreeNode* root = new TreeNode(rootVal);

        root -> left = build(preorder, inorder, preStart + 1, preStart + leftSize, inStart, rootIndex - 1);

        root -> right = build(preorder, inorder, preStart + leftSize + 1, preEnd, rootIndex + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};