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
    int dfs(TreeNode* root, int currNum){
        if(root == NULL){
            return 0;
        }

        currNum = currNum * 10 + root -> val;

        if(root -> left == NULL && root -> right == NULL){
            return currNum;
        } 

        return dfs(root -> left, currNum) + dfs(root -> right, currNum);
    }

    int sumNumbers(TreeNode* root) {
        int currNum = 0;
        return dfs(root, currNum);
    }
};