#pragma once
#include "RBT.h"

template<class TreeItemType, class ItemValType>
class multimap {
private:
	BinaryTree<TreeItemType, ItemValType> *data;
	int size = 0;
public:
	//  Constructors and destructor
	multimap();
	multimap(const TreeItemType &item, const ItemValType &val);
	multimap(const multimap<TreeItemType, ItemValType> &m);
	//to do  pair
	~multimap() { delete data; }
	/********************************************************************/

	//   Methods
	void insert(const TreeItemType &newItem, const ItemValType &newVal); //Add item to map
	void insert(const std::pair<TreeItemType, ItemValType> &p);
	void delete_item(TreeItemType Item);
	bool find(TreeItemType item);
	void swap(multimap <TreeItemType, ItemValType> &m);
	bool empty();
	void print(); //print all elements
	long int size_();  //Quantity of elements
	multimap<TreeItemType, ItemValType>& operator=(const multimap<TreeItemType, ItemValType> &m);
	void clear();
	bool operator==(const multimap<TreeItemType, ItemValType> &m);
	bool operator!=(const multimap<TreeItemType, ItemValType> &m);

protected:
	int NodeCount(TreeNode<TreeItemType, ItemValType> *node);
	bool compare_trees(TreeNode<TreeItemType, ItemValType> *treePtr1, TreeNode<TreeItemType, ItemValType> *treePtr2);
};

template<class TreeItemType, class ItemValType>
multimap<TreeItemType, ItemValType>::multimap()
{
	data = new BinaryTree<TreeItemType, ItemValType>;
}

template<class TreeItemType, class ItemValType>
multimap<TreeItemType, ItemValType>::multimap(const TreeItemType &item, const ItemValType &val)
{
	data = new BinaryTree<TreeItemType, ItemValType>(item, val);
	size++;
}

template<class TreeItemType, class ItemValType>
multimap<TreeItemType, ItemValType>::multimap(const multimap<TreeItemType, ItemValType> &m)
{
	data = new BinaryTree<TreeItemType, ItemValType>(*(m.data));
	size = m.size;
}


template<class TreeItemType, class ItemValType>
void multimap<TreeItemType, ItemValType>::insert(const TreeItemType &newItem, const ItemValType &newVal)
{
	data->attach(newItem, newVal);
	size++;
}

template<class TreeItemType, class ItemValType>
void multimap<TreeItemType, ItemValType>::insert(const std::pair<TreeItemType, ItemValType> &p)
{
	insert(p.first, p.second);
}

template<class TreeItemType, class ItemValType>
void multimap<TreeItemType, ItemValType>::delete_item(TreeItemType Item)
{
	data->deleteItem(Item);
	size--;
}

template<class TreeItemType, class ItemValType>
bool multimap<TreeItemType, ItemValType>::find(TreeItemType item)
{
	return data->isExist(item);
}

template<class TreeItemType, class ItemValType>
void multimap<TreeItemType, ItemValType>::swap(multimap<TreeItemType, ItemValType> &m)
{
	TreeNode<TreeItemType, ItemValType> *tmp;
	tmp = data->root;
	data->root = m.data->root;
	m.data->root = tmp;

	int tmp2 = m.size;
	m.size = size;
	size = tmp2;

}


template<class TreeItemType, class ItemValType>
void multimap<TreeItemType, ItemValType>::print()
{
	(*data).inorderTraverse(print_helper);
}

template<class TreeItemType, class ItemValType>
void print_helper(TreeItemType item, ItemValType val)
{
	std::cout << "['" << item << "']->" << val << endl;
}

template<class TreeItemType, class ItemValType>
multimap<TreeItemType, ItemValType>& multimap<TreeItemType, ItemValType>::operator=(const multimap<TreeItemType, ItemValType> &m)
{
	if (this != &m)
	{
		data = new BinaryTree<TreeItemType, ItemValType>(*(m.data));
	}
	return *this;
}

template<class TreeItemType, class ItemValType>
bool multimap<TreeItemType, ItemValType>::empty()
{
	return data->isEmpty;
}

template<class TreeItemType, class ItemValType>
long int multimap<TreeItemType, ItemValType>::size_()
{
	return size;
}

template<class TreeItemType, class ItemValType>
int multimap<TreeItemType, ItemValType>::NodeCount(TreeNode<TreeItemType, ItemValType> *node)
{

	if (node->left->isEmpty && node->right->isEmpty)
		return 1;
	int leftCount, rightCount;
	if (!node->left->isEmpty)
		leftCount = NodeCount(node->left);
	else
		leftCount = 0;
	if (!node->right->isEmpty)
		rightCount = NodeCount(node->right);
	else
		rightCount = 0;

	return leftCount + rightCount + 1;
}

template<class TreeItemType, class ItemValType>
void multimap<TreeItemType, ItemValType>::clear()
{
	delete data;
	data = new BinaryTree<TreeItemType, ItemValType>;
}

template<class TreeItemType, class ItemValType>
bool multimap<TreeItemType, ItemValType>::operator==(const multimap<TreeItemType, ItemValType> &m)
{
	return compare_trees(this->data->root, (m.data)->root);
}

template<class TreeItemType, class ItemValType>
bool  multimap<TreeItemType, ItemValType>::compare_trees(TreeNode<TreeItemType, ItemValType> *treePtr1, TreeNode<TreeItemType, ItemValType> *treePtr2)
{
	if ((treePtr1->isEmpty && !treePtr2->isEmpty) || (!treePtr1->isEmpty && treePtr2->isEmpty)) return false;

	if (treePtr1->isEmpty && treePtr2->isEmpty) return true;

	if (treePtr1->item != treePtr2->item || treePtr1->val != treePtr2->val) return false;

	return compare_trees(treePtr1->left, treePtr2->left) && compare_trees(treePtr1->right, treePtr2->right);
}

template<class TreeItemType, class ItemValType>
bool multimap<TreeItemType, ItemValType>::operator!=(const multimap<TreeItemType, ItemValType> &m)
{
	return !(*this == m);
}