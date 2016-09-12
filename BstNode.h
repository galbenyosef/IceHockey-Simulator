#ifndef BstNode_H_
#define BstNode_H_

template<class T>
class BstNode
{
private:
	BstNode<T> *left, *right;
	T* data;
	//int item_id;
	BstNode(const BstNode<T>&);
	BstNode<T>& operator=(const BstNode<T>&);
public:
	BstNode():left(0),right(0),/*item_id(0)*/,data(new T){};
	BstNode(T* pd):left(0),right(0){data = pd;};
	~BstNode(){delete left; delete right; delete data;}
	BstNode<T>* getLeft()const{return left;};
	BstNode<T>* getRight()const{return right;};
	T* getData()const{return data;};
	//int getID()const{return item_id;};
	//void setID(int id){item_id=id;};
	void setLeft(BstNode<T>* l){left=l;};
	void setRight(BstNode<T>* r){right=r;};
	void setData(T& d){*data = d;};
	void Insert(BstNode<T>*);
	BstNode<T>* Find(const T&);
};


template <class T>
BstNode<T>* BstNode<T>::Find(const T& d)
{
	if(d == *data)
		return this;
	else if(d > *data)
	{
		if(right)
			return right->Find(d);
		return NULL;
	}
	else
	{
		if (left)
			return left->Find(d);
		return NULL;
	}
}

template <class T>
void BstNode<T>::Insert(BstNode<T>* newNode)
{
	if( *( newNode->getData() ) == *data)
	{
		*data = *( newNode->getData() );
		delete newNode;
		return;
	}

	if( *( newNode->getData() ) > *data)
	{
		if(right)
		{
			right->Insert(newNode);
			return;
		}
		else
		{
			right = newNode;
		}
	}
	else 
	{
		if(left)
		{
			left->Insert(newNode);
			return;
		}
		else
		{
			left = newNode;
		}
	}
}

template <class T>
ostream& operator<<(ostream& out, const BstNode<T>* n)
{
	out << *(n->getData());
	return out;
}

#endif