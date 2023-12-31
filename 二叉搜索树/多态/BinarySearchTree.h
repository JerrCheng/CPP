#pragma once
#include<iostream>
using namespace std;

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
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(key);
		if (parent->_key < key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}

		return true;
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

	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				// 开始删除
				// 1、左为空
				// 2、右为空
				// 3、左右都不为空
				if (cur->_left == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (cur == parent->_left)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}

					delete cur;
					cur = nullptr;
				}
				else if (cur->_right == nullptr)
				{
					if (_root == cur)
					{
						_root = cur->_left;
					}
					else
					{
						if (cur == parent->_left)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}

					delete cur;
					cur = nullptr;
				}
				else
				{
					// 找到右子树最小节点进行替换
					Node* minParent = cur;
					Node* min = cur->_right;
					while (min->_left)
					{
						minParent = min;
						min = min->_left;
					}

					swap(cur->_key, min->_key);
					if (minParent->_left == min)
						minParent->_left = min->_right;
					else
						minParent->_right = min->_right;

					delete min;
				}

				return true;
			}
		}

		return false;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	/////////////////////////////////////////////////////////////////////////////
	bool FindR(const K& key)
	{
		return _FindR(_root, key);
	}

	bool InsertR(const K& key)
	{
		return _InsertR(_root, key);
	}

	bool EraseR(const K& key)
	{
		return _EraseR(_root, key);
	}

	~BSTree()
	{
		_Destory(_root);
	}

	/*BSTree()
	{}*/

	// C++的用法：强制编译器生成默认的构造
	BSTree() = default;

	BSTree(const BSTree<K>&t)
	{
		_root = _Copy(t._root);
	}

	// t2 = t1
	BSTree<K>& operator=(BSTree<K> t)
	{
		swap(_root, t._root);
		return *this;
	}

private:
	Node* _Copy(Node * root)
	{
		if (root == nullptr)
		{
			return nullptr;
		}

		Node* copyRoot = new Node(root->_key);
		copyRoot->_left = _Copy(root->_left);
		copyRoot->_right = _Copy(root->_right);
		return copyRoot;
	}

	void _Destory(Node * &root)
	{
		if (root == nullptr)
		{
			return;
		}

		_Destory(root->_left);
		_Destory(root->_right);
		delete root;
		root = nullptr;
	}


	bool _EraseR(Node * &root, const K & key)
	{
		if (root == nullptr)
			return false;

		if (root->_key < key)
			return _EraseR(root->_right, key);
		else if (root->_key > key)
			return _EraseR(root->_left, key);
		else
		{
			Node* del = root;
			if (root->_left == nullptr)
			{
				root = root->_right;
			}
			else if (root->_right == nullptr)
			{
				root = root->_left;
			}
			else
			{
				// 找右树的最左节点替换删除
				Node* min = root->_right;
				while (min->_left)
				{
					min = min->_left;
				}
				swap(root->_key, min->_key);
				//return EraseR(key);  错的
				return _EraseR(root->_right, key);
			}

			delete del;
			return true;
		}
	}

	bool _InsertR(Node * &root, const K & key)
	{
		if (root == nullptr)
		{
			root = new Node(key);
			return true;
		}

		if (root->_key < key)
			return _InsertR(root->_right, key);
		else if (root->_key > key)
			return _InsertR(root->_left, key);
		else
			return false;
	}

	bool _FindR(Node * root, const K & key)
	{
		if (root == nullptr)
			return false;

		if (root->_key < key)
			return _FindR(root->_right, key);
		else if (root->_key > key)
			return _FindR(root->_left, key);
		else
			return true;
	}

	void _InOrder(Node * root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

	Node* _root = nullptr;
};


void TestBSTree1()
{
	BSTree<int> t;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13, 4, 3, 4 };
	for (auto e : a)
	{
		t.Insert(e);
	}


	t.Erase(3);
	t.InOrder();

	t.Erase(8);
	t.InOrder();
	for (auto e : a)
	{
		t.Erase(e);
		t.InOrder();
	}
}

