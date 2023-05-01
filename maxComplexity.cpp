#include <queue>
#include <vector>

struct Component {
    int code; 
    Component* left;
    Component* right;
};

// Breadth first search approach
// Time complexity: O(n)
// Space complexity: O(n)
int maxDepth(Component *root) {
    if(!root)
        return 0;
    
    int res = 0;
    std::queue<Component*> q;
    q.push(root);

    while(!q.empty()) {
        ++res;
        for(int i = 0, n = q.size(); i < n; ++ i) {
            Component* p = q.front();
            q.pop();
            
            if(p->left)
                q.push(p->left);
            if(p->right)
                q.push(p->right);
        }
    }
    return res;
}

// Depth first search approach
// Time complexity: O(n)
// Space complexity: O(1)
int maxComplexity(Component* root) {
    if(!root) return 0;

    int l = 1+maxComplexity(root->left);
    int r = 1+maxComplexity(root->right);

    return std::max(l,r);
}