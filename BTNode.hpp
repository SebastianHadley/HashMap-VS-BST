//BTNode
//Name - Sebastian Hadley
//Student - Number c3349742
//Course - SENG1120
//This file is used to define the nodes used within the Binary Search Tree.

#include "BTNode.h"
#include <cstdlib>
#include <iostream>

//------Constructors and Destructor------//

//Default Constructor
template <typename T>
BTNode<T>::BTNode()
{
	parent = NULL;
	left = NULL;
	right = NULL;
	data = NULL;
}

//Specific Constructor
template <typename T>
BTNode<T>::BTNode(const T& initial_data, BTNode* initParent, BTNode* initLeft, BTNode* initRight) 
{	
	parent = initParent;
	left = initLeft;
	right = initRight;
	data = initial_data;

}

//Destructor
template <typename T>
BTNode<T>::~BTNode()
{
	parent = NULL;
	left = NULL;
	right = NULL;
}


//------Modifier Methods------//
 
//Sets data within the node.
template <typename T>
void BTNode<T>::setData(const T& new_data)
{
	data = new_data;
}

//Sets the node that is the parent of the node.
template <typename T>
void BTNode<T>::setParent(BTNode<T>* new_parent)
{
	parent = new_parent;
}

//Sets the node that is to the left of the node.
template <typename T>
void BTNode<T>::setLeft(BTNode<T>* new_left)
{
	left = new_left;
}

//Sets the node that is the right of the node.
template <typename T>
void BTNode<T>::setRight(BTNode<T>* new_right)
{
	right = new_right;
}


//------Acccessor Methods------//

//Gets the data stored within the node.
template <typename T>
const T BTNode<T>::getData() const
{
	return data;
}

template <typename T>
T BTNode<T>::getData()
{
	return data;
}

//Gets the parent node of the current node.
template <typename T>
const BTNode<T>* BTNode<T>::getParent() const
{
	return parent;
}

template <typename T>
 BTNode<T>* BTNode<T>::getParent()
{
	return parent;
}

//Gets the node to the left of the current node.
template <typename T>
const BTNode<T>* BTNode<T>::getLeft() const
{
	return left;
}

template <typename T>
BTNode<T>* BTNode<T>::getLeft() 
{
	return left;
}

//Gets the node to the right of the current node.
template <typename T>
const BTNode<T>* BTNode<T>::getRight() const
{
	return right;
}
template <typename T>
BTNode<T>* BTNode<T>::getRight() 
{
	return right;
}


//------Overloading------//

//Overloads output to output nodes.
template <typename T>
ostream& operator<<(ostream& out, const BTNode<T>& BTNode) 
{
	return BTNode.getData();
}
