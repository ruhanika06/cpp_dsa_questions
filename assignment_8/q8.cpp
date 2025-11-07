#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = right = NULL;
    }
};

// Function to generate all BSTs within a given range
vector<TreeNode*> generateTreesHelper(int start, int end) {
    vector<TreeNode*> result;

    // Base case
    if (start > end) {
        result.push_back(NULL);
        return result;
    }

    // Pick each number as root
    for (int i = start; i <= end; i++) {
        // Generate all possible left and right subtrees
        vector<TreeNode*> leftSubtrees = generateTreesHelper(start, i - 1);
        vector<TreeNode*> rightSubtrees = generateTreesHelper(i + 1, end);

        // Combine each left with each right
        for (auto left : leftSubtrees) {
            for (auto right : rightSubtrees) {
                TreeNode* root = new TreeNode(i);
                root->left = left;
                root->right = right;
                result.push_back(root);
            }
        }
    }
    return result;
}

vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    return generateTreesHelper(1, n);
}

// Utility function to print Preorder of a tree
void preorder(TreeNode* root) {
    if (root == NULL) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n = 3;
    vector<TreeNode*> trees = generateTrees(n);

    cout << "Total Unique BSTs: " << trees.size() << endl << endl;
    
    for (int i = 0; i < trees.size(); i++) {
        cout << "Tree " << i+1 << ": ";
        preorder(trees[i]);
        cout << endl;
    }

    return 0;
}
