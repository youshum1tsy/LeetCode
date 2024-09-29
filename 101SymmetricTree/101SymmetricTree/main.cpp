#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        std::stack<TreeNode*> left;
        std::stack<TreeNode*> right;
        TreeNode* currentLeft = root->left;
        TreeNode* currentRight = root->right;

        while (currentLeft != nullptr || currentRight != nullptr || !left.empty() || !right.empty()) {
            while (currentLeft != nullptr || currentRight != nullptr) {
                if (currentLeft != nullptr) {
                    left.push(currentLeft);
                    currentLeft = currentLeft->left;
                }
                if (currentRight != nullptr) {
                    right.push(currentRight);
                    currentRight = currentRight->right;
                }

                if ((currentLeft == nullptr) != (currentRight == nullptr)) {
                    return false;
                }
            }

            if (left.empty() != right.empty()) {
                return false;
            }

            if (!left.empty() && !right.empty()) {
                currentLeft = left.top();
                currentRight = right.top();
                left.pop();
                right.pop();

                if (currentLeft->val != currentRight->val) {
                    return false;
                }

                currentLeft = currentLeft->right;
                currentRight = currentRight->left;
            }
            else if (left.empty() != right.empty()) {
                return false;
            }
        }

        return true;
    }
};

TreeNode* createTestTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(NULL);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(NULL);
    root->right->left = new TreeNode(3);
    return root;
}

void printResult(const std::vector<int>& result) {
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {

    Solution solution;
    TreeNode* root = createTestTree();
    solution.isSymmetric(root);

    delete root->right->left;
    delete root->right;
    delete root;

}