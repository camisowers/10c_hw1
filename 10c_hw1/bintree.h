/*
		Cameron Sowers
		UID: 404766299

		Collaborators: Gauruv Gulati, Lamia Abbas

		"I pledge that I have neither given nor received unauthorized assistance on this assignment."
*/


#pragma once
#include <iostream>
#include <string>

class TreeNode
{
public: 
	TreeNode();		//default constructor
	void insert_node(TreeNode* new_node);

private:
	std::string data;
	TreeNode* left;
	TreeNode* right;
	friend class BinarySearchTree;
};

class BinarySearchTree
{
public:
	BinarySearchTree();		//default constructor
	void insert(std::string data);

	//***The Bige Three***//

	//Destructor
	~BinarySearchTree();

	//Copy Constructor
	BinarySearchTree(const BinarySearchTree& t1);

	//Assignment Operator
	BinarySearchTree& operator=(const BinarySearchTree& t2);

private: 
	void kill_tree(TreeNode* n);
	TreeNode* copy(const TreeNode* source);
	TreeNode* root;
};