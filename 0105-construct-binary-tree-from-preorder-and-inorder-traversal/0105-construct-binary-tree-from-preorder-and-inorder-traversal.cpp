class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;

        // Store the index of each value in inorder
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        int preIndex = 0;

        function<TreeNode*(int, int)> solve = [&](int left, int right) -> TreeNode* {
            if (left > right)
                return nullptr;

            // First element in preorder is the root
            int rootValue = preorder[preIndex++];
            TreeNode* root = new TreeNode(rootValue);

            // Find root position in inorder
            int mid = mp[rootValue];

            // Everything left of root is in the left subtree
            root->left = solve(left, mid - 1);

            // Everything right of root is in the right subtree
            root->right = solve(mid + 1, right);

            return root;
        };

        return solve(0, inorder.size() - 1);
    }
};
