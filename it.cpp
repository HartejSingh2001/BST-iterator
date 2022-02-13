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
class BSTIterator {
public:
    stack<TreeNode*>s;
   
    BSTIterator(TreeNode* root) {
       fun(root);
         
    }// BST iterator function end
    
    int next() {
       TreeNode*temp= s.top();
        s.pop();
        fun(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
       if(!s.empty())
       {
           return true;
       }
        return false;
    }
private:
    void fun(TreeNode*root)
    {
        TreeNode*temp=root;
        for(temp=root;temp!=NULL;temp=temp->left)
        {
             s.push(temp);
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
