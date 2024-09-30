#include <iostream>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int max_depth = 0;
        std::stack<std::pair<TreeNode*, int>> st;
        st.push({ root, 1 });

        while (!st.empty()) {
            auto node_depth_pair = st.top();
            TreeNode* node = node_depth_pair.first;
            int depth = node_depth_pair.second;
            st.pop();

            max_depth = std::max(max_depth, depth);

            if (node->right) st.push({ node->right, depth + 1 });
            if (node->left) st.push({ node->left, depth + 1 });
        }

        return max_depth;
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    int depth = solution.maxDepth(root);
    std::cout << "Max depth: " << depth << std::endl;

    delete root->left;
    delete root->right;
    delete root;

    return 0;
}