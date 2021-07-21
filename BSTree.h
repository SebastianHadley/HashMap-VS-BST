//BSTree
//Name - Sebastian Hadley
//Student - Number c3349742
//Course - SENG1120
//This file is used to build the Binary search tree for storing parts.
#ifndef BSTREE	
#define BSTREE
#include <iostream>
#include <cstdlib>
#include "BTNode.h"

using namespace std;

template <typename T>
class BSTree
{
public:
	//------Constructor and Destructor------//
	//Constructor
	BSTree();			
	//Destructor
	~BSTree();			
	
	//------Modifier Functions------//
	//Calls the recursive add to store the parts if the root isnt NULL.
	void add(const T& data);						
	//Calls the recursive remove to remove the specified node.
	void remove(const T& data);
	//Uses Recursion to remove all nodes in the Hash Table.
	void removeNodes(BTNode<T>* node);		

		
	//------Accessor Methods------//
	//Returns how many nodes are in the tree.
	int getSize() const;															
	//Calculates how many types of parts are being stored.			
	int calculateParts();											
	//Calculates how many parts are being stored in total.
	int calculateInventory();								
	//Stores the output for printing.
	ostream& print(ostream& out);

private:
	BTNode<T>* root_node;
	int size;

	//------Private Recursion------//

	//Recursively parses through tree and adds a node when a root node is empty.
	BTNode<T>* add(const T& data, BTNode<T>* node);			
	//Recursively parses through the function to find the node to remove.
	BTNode<T>* remove(const T& data, BTNode<T>* node);		
	//Recursively parses through the list to find the node with the largest data.
	BTNode<T>* findMax(BTNode<T>* const node) const;				
	//Recursively parses through the list to find the node with the smallest data.
	BTNode<T>* findMin(BTNode<T>* const node) const;				
	//recursively prints everynode within the tree.
	ostream& print(ostream& out, const BTNode<T>* node);						
	//Uses recursion to determine how many types of parts are being stored.
	int calculateParts(BTNode<T>* temp);										
	//Uses recursion to determine how many parts are being stored in total.
	int calculateInventory(BTNode<T>* temp);	
};

//Overloads output to return Binary Search trees using print function.
template <typename value_type>
ostream& operator << (ostream& out, BSTree<value_type>& tree);


#include "BSTree.hpp"
#endif

