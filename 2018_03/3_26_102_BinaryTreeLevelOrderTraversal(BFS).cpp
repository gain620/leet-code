/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> resVec;

        if (!root)
        {
        	return resVec;
        }

        queue<TreeNode*> bfsQueue;

        bfsQueue.push(root);

        while(!bfsQueue.empty())
        {	
        	//TreeNode* tmpNode = bfsQueue.front();
        	int queueSize = bfsQueue.size();
        	//bfsQueue.pop();

        	vector<int> tmpVec;

        	// every tree nodes on the same level will be added!
        	for (int i = 0; i < queueSize; ++i)
        	{
        		TreeNode* tmpNode = bfsQueue.front();
        		bfsQueue.pop();
        		tmpVec.push_back(tmpNode->val);

        		if (tmpNode->left)
        		{
        			bfsQueue.push(tmpNode->left);
        		}

        		if (tmpNode->right)
        		{
        			bfsQueue.push(tmpNode->right);
        		}

        	}

        	resVec.push_back(tmpVec);

        }

        return resVec;
    }
};