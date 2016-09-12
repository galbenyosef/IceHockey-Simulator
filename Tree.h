#ifndef Tree_H_
#define Tree_H_

#include "BstNode.h"

template<class T> class Tree
{
private:
	BstNode<T>* tree_root;
	int tree_size; 
	Tree(const Tree<T>& t);
	Tree<T>& operator=(const Tree<T>& t);
public:
	Tree():tree_root(0),tree_size(0){}
	~Tree(){Clear();}
	int size()const{return tree_size;}
	void Insert(T*);
	void Clear(); 
	void Remove(T&);
	void PrintInOrder(const BstNode<T>& node)const;
	void Print()const;
	T* Search(const T& toFind)const;
	BstNode<T>* root()const{return tree_root;}
	BstNode<T>* Delete(BstNode<T>& node, T& item);
	BstNode<T>* min(const BstNode<T>&)const;
	BstNode<T>* max(const BstNode<T>&)const;
	BstNode<T>* DeleteMin(BstNode<T>&);
};

template<class T>
void Tree<T>::Insert(T* new_element)
{
	BstNode<T> *newNode = new BstNode<T>(new_element);
	if(tree_root)
	{
		tree_root->Insert(newNode);
	}
	else
		tree_root = newNode;
}

template<class T>
T* Tree<T>::Search(const T& toFind) const
{
	BstNode<T>* found = tree_root->Find(toFind);
	if (found)
		return found->getData();
	return 0;
}


// deletes the entire tree
template<class T>
void Tree<T>::Clear()
{
	delete tree_root;
	tree_size = 0;
}


template <class T>
ostream& operator<<(ostream& out, const Tree<T>& t)
{
	if(t.size() == 0)
		out<<"Tree is empty"<<endl;
	else
	{
		if(t.size() == 1)
			out<<"There is 1 element" <<endl;
		else
			out<<"There are "<<t.size()<<" elements" <<endl;
	}
	return out;
}

template<class T>
void Tree<T>::Remove(T& item)
// Calls the recursive function Delete to delete item from tree.
{
	tree_root = Delete(tree_root, item);
}

template<class T>
BstNode<T>* Tree<T>::min(const BstNode<T>& node) const
{
	// To find the min, go left as far as possible.
	if (node.getLeft() == NULL)
		return node;
	else 
		return min(node.getLeft());
}

template<class T>
BstNode<T>* Tree<T>::max(const BstNode<T>& node) const
{
	// To find the min, go left as far as possible.
	if (node.getRight() == NULL)
		return node;
	else 
		return max(node.getRight());
}

template<class T>
BstNode<T>* Tree<T>::DeleteMin(BstNode<T>& node)
{
	 if (node.getLeft() == NULL) 
		 return node.getRight();
	 node.setLeft( DeleteMin( node.getLeft() ) );
	 return node;
}

template<class T>
BstNode<T>* Tree<T>::Delete(BstNode<T>& node, T& item)
{
	//tree is empty
	if (node == NULL) return NULL;
	//item is smaller, move left
	if (item < *node.getData()) 
		node.setLeft(Delete(node.getLeft(), item)); 
	//item is bigger, move right
	else if (item > *node.getData()) 
		node.setRight(Delete(node.getRight(), item));
	//item found
	else
	{
		// node has 1 children
		if (node.getRight() == NULL) return node.getLeft();
		if (node.getLeft() == NULL) return node.getRight();
       
		// node has 2 children
		BstNode<T> tmp = node;
		node = min(tmp.getRight());
		// copy data from tmp to node
		node.setData( *tmp.getData() );

		// now delete node from node's right subtree and return
		node.setRight( deleteMin(tmp->getRight()));
		node.setLeft( tmp->getLeft()) ;
	}
	return node;
}

template<class T>
void Tree<T>::PrintInOrder(const BstNode<T>& node) const
{
  if ( node == NULL )
  {
    return;
  }
  PrintInOrder(node.getLeft());
  cout << node;
  PrintInOrder(node.getRight());
}

template<class T>
void Tree<T>::Print() const
{
	PrintInOrder(tree_root);
}

#endif