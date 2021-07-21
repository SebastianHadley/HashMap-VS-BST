//BSTree
//Name - Sebastian Hadley
//Student - Number c3349742
//Course - SENG1120
//This file is used to build the Binary search tree for storing parts.


//------Constructor and Destructor------//

//Constructor
template <typename T>
BSTree<T>::BSTree()
{
	root_node = NULL;
	size = 0;
}

//Destructor
template <typename T>
BSTree<T>::~BSTree()
{
	removeNodes(root_node);
}


//------Modifier Functions------//
// 
//Calls the recursive add to store the parts if the root isnt NULL.
template <typename T>
void BSTree<T>::add(const T& data)
{
	if (root_node == NULL)
	{
		root_node = new BTNode<T>(data);
		size++;
		return;
	}
	else
	{
		add(data, root_node);
	}
}

//Calls the recursive function to remove specified node.
template <typename T>
void BSTree<T>::remove(const T& data) 
{
	BTNode<T>* root = root_node;
	root = remove(data, root);
	//return true;
}

//Uses Recursion to remove all nodes in the Hash Table.
template <typename T>
void BSTree<T>::removeNodes(BTNode<T>* node)
{
	if (node == NULL)
	{
		return;
	}

	// delete left and right subtrees
	removeNodes(node->getLeft());
	removeNodes(node->getRight());

	// delete the original node
	delete node;
	size--;
}


//------Accessor Methods------//

//Returns how many nodes are in the tree.
template <typename T>
int BSTree<T>::getSize() const 
{
	return size;
}

//Stores output for printing.
template <typename T>
ostream& BSTree<T>::print(ostream& out)
{
	BTNode<T>* root = root_node;
	return print(out, root);
}

//Calculates how many types of parts are being stored.
template <typename T>
int BSTree<T>::calculateParts()
{
	int answer = 0;
	answer = calculateParts(root_node);
	return answer;
}

//Calculates how many parts are being stored in total.
template <typename T>
int BSTree<T>::calculateInventory()
{	
	int answer = 0;
	answer = calculateInventory(root_node);
	return answer;
}


//------Private Recursion------//

//Recursively parses through tree and adds a node when a root node is empty.
template <typename T>
BTNode<T>* BSTree<T>::add(const T& data, BTNode<T>* node)
{

	if (data < node->getData())
	{
		// Check current node 
		if (node->getLeft())
		{
			// set left node
			node->setLeft(add(data, node->getLeft()));
		}
		else
		{
			node->setLeft(new BTNode<T>(data, node));
			size++;
		}
	}

	if (data > node->getData())
	{
		if (node->getRight())
		{
			node->setRight(add(data, node->getRight()));
		}
		else
		{
			node->setRight(new BTNode<T>(data, node));
			size++;
		}
	}

	// BOOYAH!!!!!
	return node;
}

//Recursively parses through the function to find the node to remove.
template <typename T>
BTNode<T>* BSTree<T>::remove(const T& data, BTNode<T>* node)
{
	BTNode<T>* temp;
	if (node == NULL)
	{
		return NULL;
	}

	if (data < node->getData())
	{
		node->setLeft(remove(data, node->getLeft()));

		if (node->getLeft())
		{
			node->getLeft()->setParent(node);
		}
	}
	else if (data > node->getData())
	{
		node->setRight(remove(data, node->getRight()));

		if (node->getRight())
		{
			node->getRight()->setParent(node);
		}
	}
	else
	{
		// for 2 child
		if (node->getLeft() && node->getRight())
		{
			temp = findMin(node->getRight());
			node->setData(temp->getData());
			node->setRight(remove(node->getData(), node->getRight()));
		}
		else // not 2 children
		{
			temp = node;
			// check left
			if (node->getLeft() == NULL)
			{
				node = node->getRight();
			}
			else if (node->getRight() == NULL)
			{
				node = node->getLeft();
			}
			delete temp;
			size--;
		}
	}

	// Check node 
	if (!node) {
		return node;
	}

	return node;
}

//Recursively parses through the list to find the node with the largest data.
template <typename T>
BTNode<T>* BSTree<T>::findMax(BTNode<T>* const node) const 
{
	if (node == NULL) 
	{
		return NULL;
	}
	
	if (node->getRight() == NULL) 
	{
		return node;
	}
		
	return findMax(node->getRight());
	
}

//Recursively parses through the list to find the node with the smallest data.
template <typename T>
BTNode<T>* BSTree<T>::findMin(BTNode<T>* const node) const 
{
	if (node == NULL) 
	{
		return NULL;
	}
	
	if (node->getLeft() == NULL) {

		return node;
	}
	
	return findMin(node->getLeft());
}

//Recursively prints everynode within the tree.
template <typename T>
ostream& BSTree<T>::print(ostream& out, const BTNode<T>* node)
{
	// PREORDER
	//	left
	//		parent
	//	right
	if (node != NULL)
	{
		// left
		print(out, node->getLeft());
		// parent
		out << node->getData() << " ";
		// right
		print(out, node->getRight());
	}
	return out;
}

//Uses recursion to determine how many types of parts are being stored.
template <typename T>
int BSTree<T>::calculateParts(BTNode<T>* temp)
{
	int answer = 0;
	if (temp != NULL) {
		answer += calculateParts(temp->getLeft());
		answer += 1;
		answer += calculateParts(temp->getRight());
	}
	return answer;
}

//Uses recursion to determine how many parts are being stored in total.
template <typename T>
int BSTree<T>::calculateInventory(BTNode<T>* temp)
{
	int answer = 0;
	if (temp != NULL) {
		answer += calculateInventory(temp->getLeft());
		answer += temp->getData().get_quantity();
		answer += calculateInventory(temp->getRight());
	}
	return answer;
}


//------Overloading------//
//Overloads output to return Binary Search trees using print function.
template <typename T>
ostream& operator << (ostream& out, BSTree<T>& tree) 
{
	return tree.print(out);
}
