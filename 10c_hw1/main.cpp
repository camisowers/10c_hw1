#include <iostream>
#include "bintree.h"

int main()
{
	//check default constructor
	BinarySearchTree bst1;

	//create a BST with datA
	bst1.insert("Hi");
	bst1.insert("Hello");
	bst1.insert("Hey");
	bst1.insert("Hola");

	//check copy constrcutor
	BinarySearchTree bst2(bst1);

	//check assignment operator
	bst1 = bst2;

	std::cout << std::endl;

	return 0;
}