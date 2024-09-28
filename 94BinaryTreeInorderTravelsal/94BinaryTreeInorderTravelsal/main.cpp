#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> parents;
        std::vector<int> result;
        TreeNode* current = root;

        while (current != nullptr || !parents.empty()) {
            while (current != nullptr) {
                parents.push(current);
                current = current->left;
            }

            current = parents.top();
            parents.pop();
            result.push_back(current->val);

            current = current->right;
        }

        return result;
    }
};

TreeNode* createTestTree() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
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
    std::vector<int> result = solution.inorderTraversal(root);

    std::cout << "Inorder Traversal: ";
    printResult(result);

    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}

