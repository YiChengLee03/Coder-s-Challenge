#include <queue>

struct Pipeline {
    int rate;
    Pipeline *left;
    Pipeline *right;
};

// Iterative approach
// Time complexity: O(n)
// Space complexity: O(n)
bool isSymmetric(Pipeline *root) {
    Pipeline *left, *right;
    if (!root)
        return true;

    std::queue<Pipeline*> q1, q2;
    q1.push(root->left);
    q2.push(root->right);
    while (!q1.empty() && !q2.empty())
    {
        left = q1.front();
        q1.pop();
        right = q2.front();
        q2.pop();
        if (!left && !right)
            continue;
        if (!left || !right)
            return false;
        if (left->rate != right->rate)
            return false;
        q1.push(left->left);
        q1.push(left->right);
        q2.push(right->right);
        q2.push(right->left);
    }
    return true;
}

// Recursive approach
// Time complexity: O(n)
// Space complexity: O(1)
bool isSymmetric(Pipeline *root) {
    return checkSymmetry(root->left, root->right);
}

bool checkSymmetry(Pipeline *left, Pipeline *right) {
    if (left == nullptr && right == nullptr)
        return true;
    if (!left || !right)
        return false;
    if (left->rate != right->rate)
        return false;

    return checkSymmetry(left->left, right->right) && checkSymmetry(left->right, right->left);
}
