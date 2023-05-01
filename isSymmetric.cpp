struct Pipeline {
    int rate;
    Pipeline* left;
    Pipeline* right;
};

// Time complexity: O(n)
// Space complexity: O(1)
bool isSymmetric(Pipeline* root) {
    return checkSymmetry(root->left, root->right);
}

bool checkSymmetry(Pipeline* left, Pipeline* right) {
    if(left == nullptr && right == nullptr) return true;
    if(!left || !right) return false;
    if(left->rate != right->rate) return false;

    return checkSymmetry(left->left, right->right) && checkSymmetry(left->right, right->left);
}