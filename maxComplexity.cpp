#include <vector>

struct Component {
    int code; 
    Component* left;
    Component* right;
};

// Time complexity: O(n)
// Space complexity: O(1)
int maxComplexity(Component* root) {
    if(!root) return 0;
    return std::max(1+maxComplexity(root->left), 1+maxComplexity(root->right));
}