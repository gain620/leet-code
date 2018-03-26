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
	// recursive method, straight forward but trivial
	vector<int> vRes;
    vector<int> inorderTraversal(TreeNode* root) {
    	
    	
    	if(root==nullptr) return vRes;

    	inorderTraversal(root->left);

    	vRes.push_back(root->val);

    	inorderTraversal(root->right);


    	return vRes;	
    }


    // using stack
    vector<int> inorderTraversal(TreeNode* root) {
   	    vector<int> vRes;
    	stack<TreeNode*> tempStack;
    	TreeNode* currNode = root;

    	while(currNode != nullptr || !tempStack.empty())
    	{
    		while(currNode != nullptr)
    		{
    			tempStack.push(currNode);
    			currNode = currNode->left;
    		}

    		currNode = tempStack.top();
            tempStack.pop();
    		vRes.push_back(currNode->val);
    		currNode = currNode->right;
    	}

    	return vRes;
    }

    // Morris Traversal
    // Threaded binary tree 
    vector<int> inorderTraversal(TreeNode* root) {
   	    vector<int> vRes;
   	    TreeNode *curr = root, *pre = nullptr;
   	    while(curr!=nullptr)
   	    {
   	    	if(!curr->left)
   	    	{
   	    		vRes.push_back(curr->val);
   	    		curr = curr->right;
   	    	}
   	    	else
   	    	{
   	    		pre = curr->left;
   	    		while(pre!=nullptr)
   	    		{
   	    			if(!pre->right) break;
   	    			pre = pre->right;
   	    		}

   	    		pre->right = curr;
   	    		TreeNode *temp = curr;
   	    		curr = curr->left;
   	    		temp->left = nullptr; // ?

   	    	}
   	    }

    	return vRes;
    }

};