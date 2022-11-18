#pragma once

template<class K>
struct BSTreeNode
{
	K _key;
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;

	BSTreeNode(const K& key)
		:_left(nullptr)
		, _right(nullptr)
		, _key(key)
	{}

};


template<class K>
class BSTree
{
	typedef BSTreeNode<K>  Node;
public:

	//插入节点
	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;

				cur = cur->_left;
			}

			else if (cur->_key < key)
			{
				parent = cur;

				cur = cur->_right;
			}

			else
			{
				return false;
			}
		}

		if (parent->_key > key)
		{
			parent->_left = key;
		}
		else
		{
			parent->_right = key;

		}

		return true;
	}


	//调用private里的中序
	void Inorder()
	{
		_Inorder(_root);
	}



	bool Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}

		return false;
	}
	

private:

	//中序遍历
	void _Inorder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		else
		{
			_Inorder(root->_left);
			cout << root->_key << " ";
			_Inorder(root->_right);

		}
	}
	Node* _root = nullptr;

};


void TestBSTree1()
{
	BSTree<int> t;
	int a[] = { 8,3,1,10,6,4,7,14,13 };
	for (auto e : a)
	{
		t.Insert(e);
	}

	t.Inorder();
}

