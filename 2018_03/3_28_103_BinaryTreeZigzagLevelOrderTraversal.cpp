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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vRes;

        if(!root) return vRes;

        queue<TreeNode*> myQueue;
        myQueue.push(root);

        bool leftRight = true;

        while(!myQueue.empty())
        { 	
        	int queueSize = myQueue.size();

        	vector<int> tmpVec(queueSize);

        	for (int i = 0; i < queueSize; ++i)
        	{
        		TreeNode* tmpNode = myQueue.front();
        		myQueue.pop();


        		if(leftRight)
        		{
        			tmpVec[i] = tmpNode->val;
        		}
        		else
        		{
        			tmpVec[queueSize - 1 - i] = tmpNode->val;
        		}


        		if (tmpNode->left)
        		{
        			myQueue.push(tmpNode->left);
        		}
        		
        		if (tmpNode->right)
        		{
        			myQueue.push(tmpNode->right);
        		}
        	}

        	// toggle left & right direction
        	leftRight = !leftRight;
        	vRes.push_back(tmpVec);

        }


        return vRes;
    }
};