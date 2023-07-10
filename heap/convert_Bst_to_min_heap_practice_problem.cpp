/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/
//logic : is that store the inorder traversal of tree in vector then update the values of tree in preorder traversal then 
// you will see that the tree becomes the min heap and also the left subtree values are less then right subtree values




// void inorder(BinaryTreeNode *root,vector<int> &res)
// {
//     if(root!=NULL)
//     {
//         inorder(root->left,res);
//         res.push_back(root->data);
//         inorder(root->right,res);
//     }
// }
// void preorder(BinaryTreeNode *root,vector<int> res,int *i)
// {
//     if(root!=NULL)
//     {
//         root->data=res[++*i];
//         preorder(root->left,res,i);
//         preorder(root->right,res,i);
//     }
// }
// BinaryTreeNode* convertBST(BinaryTreeNode* root)
// {
// 	// Write your code here.
//     vector<int> res;
//     inorder(root,res);
//     int i=-1;
//     preorder(root,res,&i);
//     return root;
// }