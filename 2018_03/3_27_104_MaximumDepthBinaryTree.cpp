/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class DFSSolution {
public:
    int maxDepth(TreeNode* root) {
    	if(!root)
    		return 0;

    	return max(maxDepth(root->left),maxDepth(root->right)) + 1;
        
    }
};

class BFSSolution {
public:
    int maxDepth(TreeNode* root) {
    	if(!root)
    		return 0;

    	int depth = 0;
    	queue<TreeNode*> myQueue;
    	myQueue.push(root);

    	while(!myQueue.empty())
    	{
    		int queueSize = myQueue.size();
    		TreeNode* tmpNode = myQueue.front();
    		myQueue.pop();


    		for (int i = 0; i <queueSize; ++i)
    		{

    			if (tmpNode->left)
    			{
    				myQueue.push(tmpNode->left);
    			}

    			if (tmpNode->right)
    			{
    				myQueue.push(tmpNode->right);
    			}
    		}

    		depth++;

    	}
       
       return depth; 
    }
};