#pragma once

#include <cstddef>		// Определение константы NULL
#include <exception>
#include <string>
#include <queue>		// queue

class TreeException : public std::exception
{
public:
	TreeException(const std::string & message = "") : std::exception(message.c_str()) { }
};
/********************************************************************************************************************************/
// Узел дерева
// файл TreeNode.h

#pragma once
#include <cstddef> // oпределение константы NULL

template <class TreeItemType, class ItemValType>
class TreeNode
{
	enum { BLACK = 0, RED = 1 };
private:
	TreeItemType item;
	ItemValType val;
	TreeNode<TreeItemType, ItemValType> * left, *right, *parent;
	bool color, isEmpty;

	TreeNode() : left(NULL), right(NULL), parent(NULL), color(BLACK), isEmpty(1) {};

	TreeNode(const TreeItemType& nodeItem, const ItemValType& nodeVal, TreeNode<TreeItemType, ItemValType> * leftPtr = NULL, TreeNode<TreeItemType, ItemValType> * rightPtr = NULL, TreeNode<TreeItemType, ItemValType> * parentPtr = NULL) :
		item(nodeItem), val(nodeVal), isEmpty(1), color(BLACK), left(leftPtr), right(rightPtr), parent(parentPtr) {};
	template <class TreeItemType, class ItemValType> friend class BinaryTree;
	template <class TreeItemType, class ItemValType> friend class multimap;
};
/********************************************************************************************************************************/


template <class TreeItemType, class ItemValType>
class BinaryTree
{
public:
	// Конструкторы и деструктор:
	BinaryTree();
	BinaryTree(const TreeItemType& rootltem, const ItemValType &rootVal);
	BinaryTree(const TreeItemType& rootltem, BinaryTree<TreeItemType, ItemValType>& leftTree, BinaryTree<TreeItemType, ItemValType>& rightTree);
	BinaryTree(const BinaryTree<TreeItemType, ItemValType>& tree);
	~BinaryTree();

	// Операции над деревом:
	TreeItemType getRootData() const;
	bool isEmpty() const;
	BinaryTree<TreeItemType, ItemValType> getLeftSubtree() const;
	BinaryTree<TreeItemType, ItemValType> getRightSubtree() const;
	void preorderTraverse(void(*visit)(TreeItemType &anitem));
	void inorderTraverse(void(*visit)(TreeItemType &anitem, ItemValType& val));
	void postorderTraverse(void(*visit)(TreeItemType &anitem));
	BinaryTree<TreeItemType, ItemValType>& operator=(const BinaryTree<TreeItemType, ItemValType>& rhs);

	unsigned int getDepth() const;
	unsigned int getDepthOfMin() const;
	unsigned int getDepthOfMax() const;
	void printLevels() const;
	void print() const;
	template <class TreeItemType, class ItemValType> friend std::ostream& operator<<(std::ostream& out, const BinaryTree<TreeItemType, ItemValType> &tree);
	void attach(const TreeItemType &newItem, const ItemValType &newVal);
	bool isExist(TreeItemType &anitem) const;
	void deleteItem(TreeItemType &anitem);

	template<class TreeItemType, class ItemValType>   friend class multimap;

protected:
	void setRootData(const TreeItemType& newltem);
	void attachLeft(const TreeItemType& newltem);
	void attachRight(const TreeItemType& newltem);
	void attachLeftSubtree(BinaryTree<TreeItemType, ItemValType>& leftTree);
	void attachRightSubtree(BinaryTree<TreeItemType, ItemValType>& rightTree);
	void detachLeftSubtree(BinaryTree<TreeItemType, ItemValType>& leftTree);
	void detachRightSubtree(BinaryTree<TreeItemType, ItemValType>& rightTree);
	BinaryTree(TreeNode<TreeItemType, ItemValType> *nodePtr);
	void copyTree(TreeNode<TreeItemType, ItemValType> *treePtr, TreeNode<TreeItemType, ItemValType> *& newTreePtr) const;
	void destroyTree(TreeNode<TreeItemType, ItemValType> *& treePtr);
	TreeNode<TreeItemType, ItemValType>* rootPtr() const;
	void setRootPtr(TreeNode<TreeItemType, ItemValType> *newRoot);
	void getChildPtrs(TreeNode<TreeItemType, ItemValType> *nodePtr, TreeNode<TreeItemType, ItemValType> *& leftChildPtr, TreeNode<TreeItemType, ItemValType> *& rightChildPtr) const;
	void setChildPtrs(TreeNode<TreeItemType, ItemValType> *nodePtr, TreeNode<TreeItemType, ItemValType> *leftChildPtr, TreeNode<TreeItemType, ItemValType> *rightChildPtr);
	void preorder(TreeNode<TreeItemType, ItemValType> *treePtr, void(*visit)(TreeItemType &anitem));
	void inorder(TreeNode<TreeItemType, ItemValType> *treePtr, void(*visit)(TreeItemType &anitem, ItemValType &val));
	void postorder(TreeNode<TreeItemType, ItemValType> *treePtr, void(*visit)(TreeItemType &anitem));

	void attach_helper(const TreeItemType &newItem, const ItemValType& newVal, TreeNode<TreeItemType, ItemValType> *&nodePtr);
	unsigned int getDepth_helper(TreeNode<TreeItemType, ItemValType> *nodePtr) const;
	unsigned int getDepthOfMin_helper(TreeNode<TreeItemType, ItemValType> *nodePtr) const;
	unsigned int getDepthOfMax_helper(TreeNode<TreeItemType, ItemValType> *nodePtr) const;
	void printLevels_helper(unsigned int level, std::queue<TreeNode<TreeItemType, ItemValType>*> &levelHubs) const;
	void print_helper(TreeNode<TreeItemType, ItemValType> *nodePtr, unsigned int level) const;
	bool isExist_helper(TreeNode<TreeItemType, ItemValType> *nodePtr, TreeItemType &anitem) const;
	TreeNode<TreeItemType, ItemValType>* deleteItem_helper(TreeNode<TreeItemType, ItemValType> *&nodePtr);

	TreeNode<TreeItemType, ItemValType>* grandparent(TreeNode<TreeItemType, ItemValType> *node);
	TreeNode<TreeItemType, ItemValType>* uncle(TreeNode<TreeItemType, ItemValType> *node);

	void rotate_left(TreeNode<TreeItemType, ItemValType> *node);
	void rotate_right(TreeNode<TreeItemType, ItemValType> *node);
	TreeNode<TreeItemType, ItemValType>* sibling(TreeNode<TreeItemType, ItemValType>* node);

	void delete_case1(TreeNode<TreeItemType, ItemValType> *node);
	void delete_case2(TreeNode<TreeItemType, ItemValType> *node);
	void delete_case3(TreeNode<TreeItemType, ItemValType> *node);
	void delete_case4(TreeNode<TreeItemType, ItemValType> *node);
	void delete_case5(TreeNode<TreeItemType, ItemValType> *node);
	void delete_case6(TreeNode<TreeItemType, ItemValType> *node);

	void remove(TreeNode<TreeItemType, ItemValType> *node);


	void insert_case1(TreeNode<TreeItemType, ItemValType> *node);
	void insert_case2(TreeNode<TreeItemType, ItemValType> *node);
	void insert_case3(TreeNode<TreeItemType, ItemValType> *node);
	void insert_case4(TreeNode<TreeItemType, ItemValType> *node);
	void insert_case5(TreeNode<TreeItemType, ItemValType> *node);

	void replace(TreeNode<TreeItemType, ItemValType> *node, TreeNode<TreeItemType, ItemValType>* child);

private:
	TreeNode<TreeItemType, ItemValType> *root;
};

/// !!! REALIZATION (MUST BE IN .CPP) !!!

#include <algorithm>	// std::max
#include <iostream>		// std::cout, std::cin
#include <iomanip>		// std::setw, std::setf, std::right

template <class TreeItemType, class ItemValType>
TreeNode<TreeItemType, ItemValType>* BinaryTree<TreeItemType, ItemValType>::grandparent(TreeNode<TreeItemType, ItemValType> *node)
{
	if ((node != NULL) && (node->parent != NULL))
		return node->parent->parent;
	else
		return NULL;
}

template <class TreeItemType, class ItemValType>
TreeNode<TreeItemType, ItemValType>* BinaryTree<TreeItemType, ItemValType>::uncle(TreeNode<TreeItemType, ItemValType> *node)
{
	TreeNode<TreeItemType, ItemValType> *g = grandparent(node);
	if (g == NULL)
		return NULL;
	if (node->parent == g->left)
		return g->right;
	else
		return g->left;
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::rotate_left(TreeNode<TreeItemType, ItemValType> *node)
{
	TreeNode<TreeItemType, ItemValType> *pivot = node->right;
	pivot->parent = node->parent;
	if (node->parent != NULL) {
		if (node->parent->left == node)
			node->parent->left = pivot;
		else
			node->parent->right = pivot;
	}
	else root = pivot;

	node->right = pivot->left;
	if (pivot->left != NULL)
		pivot->left->parent = node;

	node->parent = pivot;
	pivot->left = node;
}


template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::replace(TreeNode<TreeItemType, ItemValType>* node, TreeNode<TreeItemType, ItemValType>* child)
{
	if (node->parent->left == node)
	{
		node->parent->left = child;
	}
	else
	{
		node->parent->right = child;
	}
	child->parent = node->parent;
	node = child;
}



template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::rotate_right(TreeNode<TreeItemType, ItemValType> *node)
{
	TreeNode<TreeItemType, ItemValType> *pivot = node->left;
	pivot->parent = node->parent;
	if (node->parent != NULL) {
		if (node->parent->left == node)
			node->parent->left = pivot;
		else
			node->parent->right = pivot;
	}
	else root = pivot;

	node->left = pivot->right;
	if (pivot->right != NULL)
		pivot->right->parent = node;

	node->parent = pivot;
	pivot->right = node;
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::insert_case5(TreeNode<TreeItemType, ItemValType> *node)
{
	TreeNode<TreeItemType, ItemValType> *g = grandparent(node);
	node->parent->color = TreeNode<TreeItemType, ItemValType>::BLACK;
	g->color = TreeNode<TreeItemType, ItemValType>::RED;
	if ((node == node->parent->left) && (node->parent == g->left))
	{
		rotate_right(g);
	}
	else
	{
		rotate_left(g);
	}
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::insert_case4(TreeNode<TreeItemType, ItemValType> *node)
{
	TreeNode<TreeItemType, ItemValType> *g = grandparent(node);
	if ((node == node->parent->right) && (node->parent == g->left))
	{
		rotate_left(node->parent);
		node = node->left;
	}
	else
		if ((node == node->parent->left) && (node->parent == g->right))
		{
			rotate_right(node->parent);
			node = node->right;
		}
	insert_case5(node);
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::insert_case3(TreeNode<TreeItemType, ItemValType> *node)
{
	TreeNode<TreeItemType, ItemValType> *u = uncle(node);
	if ((u != NULL) && (u->color == TreeNode<TreeItemType, ItemValType>::RED) && (node->parent->color == TreeNode<TreeItemType, ItemValType>::RED))
	{
		node->parent->color = TreeNode<TreeItemType, ItemValType>::BLACK;
		u->color = TreeNode<TreeItemType, ItemValType>::BLACK;
		TreeNode<TreeItemType, ItemValType> *g = grandparent(node);
		g->color = TreeNode<TreeItemType, ItemValType>::RED;
		insert_case1(g);
	}
	else
	{
		insert_case4(node);
	}
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::insert_case2(TreeNode<TreeItemType, ItemValType> *node)
{
	if (node->parent->color == TreeNode<TreeItemType, ItemValType>::BLACK)
		return;
	else
		insert_case3(node);
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::insert_case1(TreeNode<TreeItemType, ItemValType> *node)
{
	if (node->parent == NULL)
		node->color = TreeNode<TreeItemType, ItemValType>::BLACK;
	else
		insert_case2(node);
}

template <class TreeItemType, class ItemValType>
TreeNode<TreeItemType, ItemValType>*	BinaryTree<TreeItemType, ItemValType>::sibling(TreeNode<TreeItemType, ItemValType> *n)
{
	if (n == n->parent->left)
		return n->parent->right;
	else
		return n->parent->left;
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::remove(TreeNode<TreeItemType, ItemValType>* node)
{
	//TreeNode<TreeItemType, ItemValType> *child = is_empty(node->rightChildPtr) ? node->leftChildPtr : node->rightChildPtr; 

	TreeNode<TreeItemType, ItemValType> *child = (node->right->isEmpty) ? node->left : node->right;

	replace(node, child);
	if (node->color == TreeNode <TreeItemType, ItemValType>::BLACK)
	{
		if (child->color == TreeNode <TreeItemType, ItemValType>::RED)
		{
			child->color = TreeNode <TreeItemType, ItemValType>::BLACK;
		}
		else
		{
			delete_case1(child);
		}
	}
	delete node;
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::delete_case1(TreeNode<TreeItemType, ItemValType>* n)
{
	if (n->parent != NULL)
		delete_case2(n);
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::delete_case2(TreeNode<TreeItemType, ItemValType>* n)
{
	TreeNode<TreeItemType, ItemValType> *s = sibling(n);

	if (s->color == TreeNode<TreeItemType, ItemValType>::RED)
	{
		n->parent->color = TreeNode<TreeItemType, ItemValType>::RED;
		s->color = 0;
		if (n == n->parent->left)
			rotate_left(n->parent);
		else
			rotate_right(n->parent);
	}
	delete_case3(n);
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::delete_case3(TreeNode<TreeItemType, ItemValType>* n)
{
	TreeNode<TreeItemType, ItemValType> *s = sibling(n);

	if ((n->parent->color == TreeNode<TreeItemType, ItemValType>::BLACK) &&
		(s->color == TreeNode<TreeItemType, ItemValType>::BLACK) &&
		(s->left->color == TreeNode<TreeItemType, ItemValType>::BLACK) &&
		(s->right->color == TreeNode<TreeItemType, ItemValType>::BLACK))
	{
		s->color = TreeNode<TreeItemType, ItemValType>::RED;
		delete_case1(n->parent);
	}
	else
		delete_case4(n);
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::delete_case4(TreeNode<TreeItemType, ItemValType>* n)
{
	TreeNode<TreeItemType, ItemValType> *s = sibling(n);

	if ((n->parent->color == TreeNode<TreeItemType, ItemValType>::RED) &&
		(s->color == TreeNode<TreeItemType, ItemValType>::BLACK) &&
		(s->left->color == TreeNode<TreeItemType, ItemValType>::BLACK) &&
		(s->right->color == TreeNode<TreeItemType, ItemValType>::BLACK))
	{
		s->color = TreeNode<TreeItemType, ItemValType>::RED;
		n->parent->color = TreeNode<TreeItemType, ItemValType>::BLACK;
	}
	else
		delete_case5(n);
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::delete_case5(TreeNode<TreeItemType, ItemValType>* n)
{
	TreeNode<TreeItemType, ItemValType> *s = sibling(n);

	if (s->color == TreeNode<TreeItemType, ItemValType>::BLACK)
	{
		if ((n == n->parent->left) &&
			(s->right->color == TreeNode<TreeItemType, ItemValType>::BLACK) &&
			(s->left->color == TreeNode<TreeItemType, ItemValType>::RED))
		{
			s->color = TreeNode<TreeItemType, ItemValType>::RED;
			s->left->color = TreeNode<TreeItemType, ItemValType>::BLACK;
			rotate_right(s);
		}
		else
			if ((n == n->parent->right) &&
				(s->left->color == TreeNode<TreeItemType, ItemValType>::BLACK) &&
				(s->right->color == TreeNode<TreeItemType, ItemValType>::RED))
			{
				s->color = TreeNode<TreeItemType, ItemValType>::RED;
				s->right->color = TreeNode<TreeItemType, ItemValType>::BLACK;
				rotate_left(s);
			}
	}
	delete_case6(n);
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::delete_case6(TreeNode<TreeItemType, ItemValType>* n)
{
	TreeNode<TreeItemType, ItemValType> *s = sibling(n);

	s->color = n->parent->color;
	n->parent->color = TreeNode<TreeItemType, ItemValType>::BLACK;

	if (n == n->parent->left)
	{
		s->right->color = TreeNode<TreeItemType, ItemValType>::BLACK;
		rotate_left(n->parent);
	}
	else
	{
		s->left->color = TreeNode<TreeItemType, ItemValType>::BLACK;
		rotate_right(n->parent);
	}
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::deleteItem(TreeItemType &anitem)
{
	if (root->item == anitem)
	{
		if (root->left->isEmpty && root->right->isEmpty) //If the root is hasn't any children
		{
			delete root->left;
			delete root->right;
			root = new TreeNode<TreeItemType, ItemValType>;
			return;
		}

		if (root->left->isEmpty && !root->right->isEmpty)
		{
			root->item = root->right->item;
			root->right = new TreeNode<TreeItemType, ItemValType>;
			return;
		}

		if (!root->left->isEmpty && root->right->isEmpty)
		{
			root->item = root->left->item;
			root->left = new TreeNode<TreeItemType, ItemValType>;
			return;
		}

	}


	TreeNode<TreeItemType, ItemValType> *tmpPtr = root, *nodePtr = NULL;
	while (!tmpPtr->isEmpty && tmpPtr->item != anitem) // находим элемент
	{
		nodePtr = tmpPtr;
		if (anitem > tmpPtr->item)
			tmpPtr = tmpPtr->right;
		else
			tmpPtr = tmpPtr->left;
	}
	if (tmpPtr->isEmpty)
		throw TreeException("TreeException: элемент не найден");
	else // если он есть, то удаляем
	{
		if (!tmpPtr->left->isEmpty && !tmpPtr->right->isEmpty)
		{
			TreeNode<TreeItemType, ItemValType>* Max_in_left = tmpPtr->left;
			while (!Max_in_left->right->isEmpty)
				Max_in_left = Max_in_left->right;
			tmpPtr->item = Max_in_left->item;
			nodePtr = Max_in_left->parent;
			tmpPtr = Max_in_left;
		}
		remove(tmpPtr);
	}
}

template <class TreeItemType, class ItemValType>
bool BinaryTree<TreeItemType, ItemValType>::isExist(TreeItemType &anitem) const
{
	return isExist_helper(root, anitem);
}

template <class TreeItemType, class ItemValType>
bool BinaryTree<TreeItemType, ItemValType>::isExist_helper(TreeNode<TreeItemType, ItemValType> *nodePtr, TreeItemType &anitem) const
{
	if (nodePtr != NULL)
	{
		if (nodePtr->item == anitem)
			return 1;
		else if (anitem > nodePtr->item)
			return isExist_helper(nodePtr->right, anitem);
		else
			return isExist_helper(nodePtr->left, anitem);
	}
	else
		return 0;
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::print() const
{
	print_helper(root, getDepth());
}

template <class TreeItemType, class ItemValType>
std::ostream& operator<<(std::ostream& out, const BinaryTree<TreeItemType, ItemValType> &tree)
{
	tree.print_helper(tree.root, tree.getDepth());
	return out;
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::print_helper(TreeNode<TreeItemType, ItemValType> *nodePtr, unsigned int level) const
{
	if (nodePtr)
	{
		print_helper(nodePtr->right, level - (unsigned int)1);
		std::cout << std::setw(level << (unsigned int)3) << std::setfill('-') << std::right << nodePtr->item << "(" << nodePtr->color << ")" << std::endl;
		print_helper(nodePtr->left, level - (unsigned int)1);
	}
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::printLevels() const
{
	std::queue<TreeNode<TreeItemType, ItemValType>*> levelHubs;
	levelHubs.push(root);
	printLevels_helper((unsigned int)0, levelHubs);
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::printLevels_helper(unsigned int level, std::queue<TreeNode<TreeItemType, ItemValType>*> &levelHubs) const
{
	std::cout << "LEVEL " << level << ':' << std::endl;
	std::queue<TreeNode<TreeItemType, ItemValType>*> nextLevelHubs;
	while (!levelHubs.empty())
	{
		std::cout << levelHubs.front()->item << std::endl;
		if (levelHubs.front()->left != NULL)
			nextLevelHubs.push(levelHubs.front()->left);
		if (levelHubs.front()->right != NULL)
			nextLevelHubs.push(levelHubs.front()->right);
		levelHubs.pop();
	}
	if (nextLevelHubs.empty())
		return;
	else
		printLevels_helper(level + (unsigned int)1, nextLevelHubs);
}

template <class TreeItemType, class ItemValType>
unsigned int BinaryTree<TreeItemType, ItemValType>::getDepth() const
{
	if (root == NULL)
		throw TreeException("TreeException: дерево не построено");
	else
	{
		return getDepth_helper(root);
	}
}

template <class TreeItemType, class ItemValType>
unsigned int BinaryTree<TreeItemType, ItemValType>::getDepth_helper(TreeNode<TreeItemType, ItemValType> *nodePtr) const
{
	if (nodePtr == NULL)
		return 0;
	else
	{
		return (unsigned int)1 + std::max(getDepth_helper(nodePtr->left), getDepth_helper(nodePtr->right));
	}
}

template <class TreeItemType, class ItemValType>
unsigned int BinaryTree<TreeItemType, ItemValType>::getDepthOfMin() const
{
	if (root == NULL)
		throw TreeException("TreeException: дерево не построено");
	else
		return getDepthOfMin_helper(root);
}

template <class TreeItemType, class ItemValType>
unsigned int BinaryTree<TreeItemType, ItemValType>::getDepthOfMin_helper(TreeNode<TreeItemType, ItemValType> *nodePtr) const
{
	if (nodePtr == NULL)
		return (unsigned int)0;
	else
		return (unsigned int)1 + getDepthOfMin_helper(nodePtr->left);
}

template <class TreeItemType, class ItemValType>
unsigned int BinaryTree<TreeItemType, ItemValType>::getDepthOfMax() const
{
	if (root == NULL)
		throw TreeException("TreeException: дерево не построено");
	else
		return getDepthOfMax_helper(root);
}

template <class TreeItemType, class ItemValType>
unsigned int BinaryTree<TreeItemType, ItemValType>::getDepthOfMax_helper(TreeNode<TreeItemType, ItemValType> *nodePtr) const
{
	if (root == NULL)
		return (unsigned int)0;
	else
		return (unsigned int)1 + getDepthOfMax_helper(nodePtr->right);
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::attach(const TreeItemType &newItem, const ItemValType& val)
{
	attach_helper(newItem, val, root);
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::attach_helper(const TreeItemType &newItem, const ItemValType& newVal, TreeNode<TreeItemType, ItemValType> *&nodePtr)
{
	if (nodePtr->isEmpty)
	{
		nodePtr->item = newItem;
		nodePtr->val = newVal;
		nodePtr->isEmpty = 0;
		nodePtr->color = TreeNode<TreeItemType, ItemValType>::RED;
		nodePtr->left = new TreeNode<TreeItemType, ItemValType>;
		nodePtr->right = new TreeNode<TreeItemType, ItemValType>;
		if (nodePtr->left == NULL || nodePtr->right == NULL)
			throw TreeException("TreeException: невозможно выделить память");
		nodePtr->left->parent = nodePtr;
		nodePtr->right->parent = nodePtr;
		insert_case1(nodePtr);
	}
	else
	{
		if (newItem > nodePtr->item)
			attach_helper(newItem, newVal, nodePtr->right);
		else
			attach_helper(newItem, newVal, nodePtr->left);
	}
}

template <class TreeItemType, class ItemValType>
BinaryTree<TreeItemType, ItemValType>::BinaryTree()
{
	root = new TreeNode<TreeItemType, ItemValType>;
}

template <class TreeItemType, class ItemValType>
BinaryTree<TreeItemType, ItemValType>::BinaryTree(const TreeItemType& rootitem, const ItemValType& rootval)
{
	root = new TreeNode<TreeItemType, ItemValType>(rootitem, rootval);
}

template <class TreeItemType, class ItemValType>
BinaryTree<TreeItemType, ItemValType>::BinaryTree(const TreeItemType& rootitem, BinaryTree<TreeItemType, ItemValType>& leftTree, BinaryTree<TreeItemType, ItemValType>& rightTree)
{
	root = new TreeNode<TreeItemType, ItemValType>(rootitem, NULL, NULL);
	attachLeftSubtree(leftTree);
	attachRightSubtree(rightTree);
}

template <class TreeItemType, class ItemValType>
BinaryTree<TreeItemType, ItemValType>::BinaryTree(const BinaryTree<TreeItemType, ItemValType>& tree)
{
	copyTree(tree.root, root);
}

template <class TreeItemType, class ItemValType>
BinaryTree<TreeItemType, ItemValType>::~BinaryTree()
{
	destroyTree(root);
}

template <class TreeItemType, class ItemValType>
BinaryTree<TreeItemType, ItemValType>::BinaryTree(TreeNode<TreeItemType, ItemValType> *nodePtr) : root(nodePtr) {}

template <class TreeItemType, class ItemValType>
bool BinaryTree<TreeItemType, ItemValType>::isEmpty() const
{
	return (root == NULL);
}

template <class TreeItemType, class ItemValType>
TreeItemType BinaryTree<TreeItemType, ItemValType>::getRootData() const
{
	if (isEmpty())
		throw TreeException("TreeException: дерево пусто");
	return root->item;
} // Конец функции getRootData

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::setRootData(const TreeItemType& newitem)
{
	if (!isEmpty())
		root->item = newitem;
	else
	{
		root = new TreeNode<TreeItemType, ItemValType>(newitem, NULL, NULL);
		if (root == NULL)
			throw TreeException(
				"TreeException: невозможно выделить память");
	}
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::attachLeft(const TreeItemType& newitem)
{
	if (isEmpty())
		throw TreeException("TreeException: дерево пусто");
	else if (root->left != NULL)
		throw TreeException("TreeException: переписать левое поддерево невозможно");
	else
	{
		root->left = new TreeNode<TreeItemType, ItemValType>(newitem, NULL, NULL);
		if (root->left == NULL)
			throw TreeException("TreeException: невозможно выделить память ");
	}
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::attachRight(const TreeItemType& newitem)
{
	if (isEmpty())
		throw TreeException("TreeException: дерево пусто");
	else if (root->right != NULL)
		throw TreeException("TreeException: невозможно переписать правое поддерево ");
	else
	{
		root->right = new TreeNode<TreeItemType, ItemValType>(newitem, NULL, NULL);
		if (root->right == NULL)
			throw TreeException("TreeException: невозможно выделить память");
	}
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::attachLeftSubtree(BinaryTree& leftTree)
{
	if (isEmpty())
		throw TreeException("TreeException: дерево пусто");
	else if (root->left != NULL)
		throw TreeException("TreeException: невозможно переписать левое поддерево");
	else
	{
		root->left = leftTree.root;
		leftTree.root = NULL;
	}
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::attachRightSubtree(BinaryTree& rightTree)
{
	if (isEmpty())
		throw TreeException("TreeException: дерево пусто");
	else if (root->right != NULL)
		throw TreeException("TreeException: невозможно переписать правое поддерево");
	else
	{
		root->right = rightTree.root;
		rightTree.root = NULL;

	}
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::detachLeftSubtree(BinaryTree& leftTree)
{
	if (isEmpty())
		throw TreeException("TreeException: дерево пусто");
	else if (root->left == NULL)
		throw TreeException("TreeException: левого поддерева не существует");
	else
	{
		leftTree = BinaryTree<TreeItemType, ItemValType>(root->left);
		root->left = NULL;
	}
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::detachRightSubtree(BinaryTree& rightTree)
{
	if (isEmpty())
		throw TreeException("TreeException: дерево пусто");
	else if (root->right == NULL)
		throw TreeException("TreeException: правого поддерева не существует");
	else
	{
		rightTree = BinaryTree<TreeItemType, ItemValType>(root->right);
		root->right = NULL;
	}
}

template <class TreeItemType, class ItemValType>
BinaryTree<TreeItemType, ItemValType> BinaryTree<TreeItemType, ItemValType>::getLeftSubtree() const
{
	TreeNode<TreeItemType, ItemValType> *subTreePtr;
	if (isEmpty())
		return BinaryTree();
	else
	{
		copyTree(root->left, subTreePtr);
		return BinaryTree<TreeItemType, ItemValType>(subTreePtr);
	}
}

template <class TreeItemType, class ItemValType>
BinaryTree<TreeItemType, ItemValType> BinaryTree<TreeItemType, ItemValType>::getRightSubtree() const
{
	TreeNode<TreeItemType, ItemValType> *subTreePtr;
	if (isEmpty())
		return BinaryTree();
	else
	{
		copyTree(root->right, subTreePtr);
		return BinaryTree<TreeItemType, ItemValType>(subTreePtr);
	}
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::preorderTraverse(void(*visit)(TreeItemType &anitem))
{
	preorder(root, visit);
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::inorderTraverse(void(*visit)(TreeItemType &anitem, ItemValType& val))
{
	inorder(root, visit);
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::postorderTraverse(void(*visit)(TreeItemType &anitem))
{
	postorder(root, visit);
}

template <class TreeItemType, class ItemValType>
BinaryTree<TreeItemType, ItemValType>& BinaryTree<TreeItemType, ItemValType>::operator=(const BinaryTree& rhs)
{
	if (this != &rhs)
	{
		destroyTree(root);
		copyTree(rhs.root, root);
	}
	return *this;
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::copyTree(TreeNode<TreeItemType, ItemValType> *treePtr, TreeNode<TreeItemType, ItemValType> *& newTreePtr) const
{
	if (treePtr != NULL)
	{
		newTreePtr = new TreeNode<TreeItemType, ItemValType>(treePtr->item, NULL, NULL);
		if (newTreePtr == NULL)
			throw TreeException("TreeException: невозможно выделить память");

		newTreePtr->color = treePtr->color;
		newTreePtr->isEmpty = treePtr->isEmpty;
		newTreePtr->val = treePtr->val;

		copyTree(treePtr->left, newTreePtr->left);
		copyTree(treePtr->right, newTreePtr->right);
	}
	else
		newTreePtr = NULL;
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::destroyTree(TreeNode<TreeItemType, ItemValType> *& treePtr)
{
	if (treePtr != NULL)
	{
		destroyTree(treePtr->left);
		destroyTree(treePtr->right);
		delete treePtr;
		treePtr = NULL;
	}
}

template <class TreeItemType, class ItemValType>
TreeNode<TreeItemType, ItemValType> *BinaryTree<TreeItemType, ItemValType>::rootPtr() const
{
	return root;
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::setRootPtr(TreeNode<TreeItemType, ItemValType> *newRoot)
{
	root = newRoot;
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::preorder(TreeNode<TreeItemType, ItemValType> *treePtr, void(*visit)(TreeItemType &anitem))
{
	if (treePtr != NULL)
	{
		visit(treePtr->item);
		preorder(treePtr->left, visit);
		preorder(treePtr->right, visit);
	}
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::inorder(TreeNode<TreeItemType, ItemValType> *treePtr, void(*visit)(TreeItemType &anitem, ItemValType &val))
{
	if (!treePtr->isEmpty != NULL)
	{
		inorder(treePtr->left, visit);
		visit(treePtr->item, treePtr->val);
		inorder(treePtr->right, visit);
	}
}

template <class TreeItemType, class ItemValType>
void BinaryTree<TreeItemType, ItemValType>::postorder(TreeNode<TreeItemType, ItemValType> *treePtr, void(*visit)(TreeItemType &anitem))
{
	if (treePtr != NULL)
	{
		postorder(treePtr->left, visit);
		postorder(treePtr->right, visit);
		visit(treePtr->item);
	}
}