class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return false;

        // If leaf node
        if(root->left == nullptr && root->right == nullptr)
            return targetSum == root->val;

        // Subtract current node value
        targetSum -= root->val;

        return hasPathSum(root->left, targetSum) ||
               hasPathSum(root->right, targetSum);
    }
};
