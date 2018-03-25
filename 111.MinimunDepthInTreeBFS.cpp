/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
private:
	queue<TreeNode*> myQueue;

public:
    int minDepth(TreeNode* root) {
    	if(!root) return 0;
        int depth = 1;

    	myQueue.push(root);

        while(!myQueue.empty())
        {
            int size = myQueue.size();

        	for(int i = 0; i<size; i++)
        	{
        		TreeNode* tmpNode = myQueue.front();
        		myQueue.pop();

        		if(!tmpNode->left && !tmpNode->right)
		    	{
		    		return depth;
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

        	depth++;
        }

        return depth;
    }
};