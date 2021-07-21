//BTNode
//Name - Sebastian Hadley
//Student - Number c3349742
//Course - SENG1120
//This file is used to define the nodes used within the Binary Search Tree.
#ifndef BTNODE
#define BTNODE

#include <cstdlib>
#include <ostream>

using namespace std;

template <typename T>
class BTNode
{
	public:

		//------Constructors------//
		//Default Constructor
		BTNode();
		//Specific Constructor
		BTNode(const T& initial_data = T(), BTNode* initParent = NULL, BTNode* initLeft = NULL, BTNode* initRight = NULL);
		// Destructor
		~BTNode();

		//------Modifier Methods------//
		//Sets data within the node.
		void setData(const T& new_data);
		//Sets the node that is the parent of the node.
		void setParent(BTNode<T>* new_parent);
		//Sets the node that is to the left of the node.
		void setLeft(BTNode<T>* new_left);
		//Sets the node that is the right of the node.
		void setRight(BTNode<T>* new_right);

		//------Accessor Methods------// 
		//Gets the data stored within the node.
		const T getData() const;
		T getData();
		//Gets the parent node of the current node.
		const BTNode<T>* getParent() const;
		BTNode<T>* getParent();
		//Gets the node to the left of the current node.
		const BTNode<T>* getLeft() const;
	    BTNode<T>* getLeft();
		//Gets the node to the right of the current node.
		const BTNode<T>* getRight() const;
		BTNode<T>* getRight();
		

	private:
		T data;
		BTNode<T>* parent;
		BTNode<T>* left;
		BTNode<T>* right;
};

//------Overloading------//
// 
//Outputs the data within a specific node.
template <typename T>
ostream& operator << (ostream& out, const BTNode<T>& BTNode);

#include "BTNode.hpp"

#endif