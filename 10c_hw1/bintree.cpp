#include <iostream>
#include <string>
#include "bintree.h"


/* The default constructor sets the root pointer to NULL to avoid error.
*/
BinarySearchTree::BinarySearchTree() : root(nullptr) {}

/* Insert creates a new TreeNode and its pointer, and enters the given data.
	parameters: @string data
*/
void BinarySearchTree::insert(std::string data)
{
	TreeNode* new_node = new TreeNode;
	new_node->data = data;
	new_node->left = nullptr;
	new_node->right = nullptr;
	if (root == nullptr)
		root = new_node;
	else
		root->insert_node(new_node);
}


/* The default constructor here sets data to a placeholder string " ", left to a NULL ptr and right to a NULL ptr.
*/
TreeNode::TreeNode() : data(" "), left(nullptr), right(nullptr) {}

/* Insert_node takes in a pointer to a node, and determines where it should be put in the tree based on its value.
	parameters: @TreeNode* new_node 
*/
void TreeNode::insert_node(TreeNode* new_node)
{
	if (new_node->data < data)
	{
		if (left == nullptr)
			left = new_node;
		else
			left->insert_node(new_node);
	}
	else if (new_node->data > data)
	{
		if (right == nullptr)
			right = new_node;
		else
			right->insert_node(new_node);
	}
}
/* kill_tree is a function designed to manually destruct the entire binary search tree, one node at a time.
	parameters: @TreeNode* n
*/
void BinarySearchTree::kill_tree(TreeNode* n)
{
	if (n != nullptr)				//at least one node
	{
		if (n->left != nullptr)		//node to left
			kill_tree(n->left);		//recursively go thru left side of tree
		if (n->right != nullptr)	//node to right
			kill_tree(n->right);	//recursively go thru right side of tree
	}
	delete n;
}

/*	This is the destructor, which just uses kill_tree starting at the root node.
*/
BinarySearchTree::~BinarySearchTree()
{
	kill_tree(root);			//delete whole tree starting w/ root
//	std::cout << "Destructor\n";
}

/* The copy function is used to "deep" copy all of the values and pointers of the nodes of one binary search tree to another.
	parameters: @ const TreeNode* source
	return: TreeNode*
	*/
TreeNode* BinarySearchTree::copy(const TreeNode* source)
{
	if (source == nullptr)			//no node to copy, terminating function
	{
		return nullptr;
	}

	TreeNode* new_node = new TreeNode;
	new_node->data = source->data;					// copies data
	
	new_node->left = copy(new_node->left);			// copies ptr to left recursively for tree, until last node aka nullptr
	new_node->right = copy(new_node->right);		// copies ptr to right recursively for tree, until last node aka nullptr

	return new_node;
}

/* This is the copy constructor, which creates a binary search tree using another binary search tree as its input.
	paramters: @ const BinarySearchTree& t1
*/
BinarySearchTree::BinarySearchTree(const BinarySearchTree& t1)
{
	root = copy(t1.root);				// the tree constructed by this will be a copy of t1
}
 
/*	The assignment operator sets the binary search tree to be the same as the inputted tree t2.
	parameters: @ const BinarySearchTree& t2
	return: BinarySearchTree (*this)	aka the implicit tree
	*/
BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& t2)
{
	if (&t2 != this)			//t2 is different from current tree
	{
		kill_tree(root);			//delete current tree, avoid memory leak

		root = copy(t2.root);	//make this == t2
	}
	return *this;				//copied new tree
}