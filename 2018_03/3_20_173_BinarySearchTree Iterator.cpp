/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> myStack;

    bool pushAll(TreeNode *root) {
    	if(!root) return false;
    	myStack.push(root);
    	pushAll(root->left);  	
    	return true;
    }
public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
    	TreeNode *resNode = myStack.top();
        myStack.pop();

        if(resNode->right)
        {
        	pushAll(resNode->right);
        }
        return resNode->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */