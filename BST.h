#ifndef _BST_
#define _BST_

#include <vector>
#include <iostream>
#include <queue>

template <class T>
class BST
{
private:
	struct Node
	{
		T data;
		Node* left;
		Node* right;
		bool operator==(const Node&) const;
		bool operator!=(const Node&) const;
		bool operator>(const Node&) const;
		bool operator<(const Node&) const;
		Node(T);
		~Node();
	};
	Node* root;
	void InsertR(const T&, Node* root);
	void PreOrder(const Node*) const;
	void PostOrder(const Node*) const;
	void InOrder(const Node*) const;
	void Clear(Node*);
public:
	void Insert(const T&); //Iterative Insert
	void InsertR(const T&); //Recursive Insert
	void Remove(const T&);
	bool IsEmpty() const;
	void Clear();
	void PreOrder() const; //Prints data in preorder format
	void PostOrder() const; //Prints data in postorder format
	void InOrder() const; //Prints data in inorder 
	void BreadthFirstPrint() const;
	BST();
	~BST();
};

template <class T>
BST<T>::Node::Node(T data) : data(data), left(nullptr), right(nullptr)
{}

template <class T>
BST<T>::Node::~Node()
{}

template <class T>
bool BST<T>::Node::operator<(const Node& other) const
{
	return (this->data < other.data)
}

template <class T>
bool BST<T>::Node::operator>(const Node& other) const
{
	return !(this < other);
}

template <class T>
bool BST<T>::Node::operator==(const Node& other) const
{
	return (this->data == other.data)
}

template <class T>
bool BST<T>::Node::operator!=(const Node& other) const
{
	return !(this->data == other.data)
}

template <class T>
BST<T>::BST()
{}

template <class T>
BST<T>::~BST()
{}

template <class T>
bool BST<T>::IsEmpty() const
{
	return (root == nullptr);
}

template <class T>
void BST<T>::Clear()
{
	//Post Order Here
	Clear(root);
	root = nullptr;
}

template <class T>
void BST<T>::Clear(Node* node)
{
	//Post Order
	if (node != nullptr)
	{
		Clear(node->left);
		Clear(node->right);
		delete node;
	}
}

template <class T>
void BST<T>::PreOrder() const
{
	PreOrder(root);
}

template <class T>
void BST<T>::PreOrder(const Node* node) const
{
	if (node != nullptr)
	{
		std::cout << node->data << ' ';
		PreOrder(node->left);
		PreOrder(node->right);
	}
}

template <class T>
void BST<T>::PostOrder() const
{
	PostOrder(root);
}

template <class T>
void BST<T>::PostOrder(const Node* node) const
{
	if (node != nullptr)
	{
		PostOrder(node->left);
		PostOrder(node->right);
		std::cout << node->data << ' ';
	}
}

template <class T>
void BST<T>::InOrder() const
{
	InOrder(root);
}

template <class T>
void BST<T>::InOrder(const Node* node) const
{
	if (node != nullptr)
	{
		InOrder(node->left);
		std::cout << node->data << ' ';
		InOrder(node->right);
	}
}

template <class T>
void BST<T>::Insert(const T& value)
{
	Node* temp = root;
	Node* new_node = new Node(value);
	Node* parent = nullptr;

	if (temp == nullptr)
		root = new_node;
	else
	{
		while (temp != nullptr)
		{
			parent = temp;

			if (temp < new_node)
				temp = temp->right;
			else
				temp = temp->left;
		}

		if (new_node < parent)
			parent->left = new_node;
		else
			parent->right = new_node;
	} 
}

template <class T>
void BST<T>::InsertR(const T& value)
{
	if (this->root == nullptr)
	{
		this->root = new Node(value);
		return;
	}

	InsertR(value, root);
}

template <class T>
void BST<T>::InsertR(const T& value, Node* root)
{
	if (value < root->data)
	{
		if (root->left != nullptr)
			InsertR(value, root->left);
	}
	else
	{
		if (root->right != nullptr)
			InsertR(value, root->right);
	}

	if (root->left == nullptr && value < root->data)
		root->left = new Node(value);
	else if (root->right == nullptr && value > root->data)
		root->right = new Node(value);
}

template <class T>
void BST<T>::BreadthFirstPrint() const
{
	std::queue<Node*> q;

	q.push(root);

	while (!q.empty())
	{
		Node* temp = q.front();
		q.pop();

		if (temp != nullptr)
		{
			std::cout << temp->data << " ";

			if (temp->left != nullptr)
				q.push(temp->left);
			if (temp->right != nullptr)
				q.push(temp->right);
		}
	}
}

template <class T>
void BST<T>::Remove(const T& value)
{
	
}
#endif // !_BST_
