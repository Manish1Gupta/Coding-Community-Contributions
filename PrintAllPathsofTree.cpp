#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class TreeNode
{
	public:
	int data;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* newNode(int x)
{
	TreeNode* node = new TreeNode();
	node->data = x;
	node->left = nullptr;
	node->right = nullptr;
	return node;
}

bool isLeaf(TreeNode* root)
{
	if((root->left==nullptr) and (root->right==nullptr))
		return true;
	return false;
}


void PrintPaths(TreeNode* root, vector<int> &a)
{
	if(root==nullptr)
		return;

	a.push_back(root->data);
	
	if(isLeaf(root))
	{
		for(int path:a)
			cout<<path<<" ";
		cout<<endl;
	}

	PrintPaths(root->left,a);
	PrintPaths(root->right,a);

	a.pop_back();
}

void PrintAllPaths(TreeNode* root)
{
	vector<int> a;
	PrintPaths(root,a);
}

int main()
{
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->left = newNode(8);
    root->right->right->right = newNode(9);
 
    // print all root-to-leaf paths
    PrintAllPaths(root);
 
    return 0;
}
