/**
/ DOUBLY LINKED LIST IMPLEMENTATION BY ANDREW MILOSLAVSKY
/ June 9th, 2015
**/

#ifndef _LIST_
#define _LIST_

template <class T>
class List
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node* previous;
		bool operator==(const Node&) const;
		bool operator!=(const Node&) const;
		bool operator>(const Node&) const;
		bool operator<(const Node&) const;
		Node(const T&);
		~Node();
	};
	Node* head;
	Node* tail;
public:
	bool IsEmpty() const;
	const T& GetHead() const;
	const T& GetTail() const;
	void Add(const T&);
	void Insert(const T&, int index);
	void Remove(const T&);
	void Print() const;
	void Clear();
	List();
	~List();
};

template <class T>
List<T>::List() : head(nullptr), tail(nullptr)
{}

template <class T>
List<T>::~List()
{}

template <class T>
List<T>::Node::Node(const T& data) : data(data), next(nullptr), previous(nullptr)
{}

template <class T>
List<T>::Node::~Node()
{}

template <class T>
bool List<T>::Node::operator==(const Node& other) const
{
	return (this->data == other.data);
}

template <class T>
bool List<T>::Node::operator!=(const Node& other) const
{
	return (this->data != other.data);
}

template <class T>
bool List<T>::Node::operator>(const Node& other) const
{
	return (this->data > other.data);
}

template <class T>
bool List<T>::Node::operator<(const Node& other) const
{
	return (this->data < other.data);
}

template <class T>
bool List<T>::IsEmpty() const
{
	return (head == nullptr);
}

template <class T>
const T& List<T>::GetHead() const
{
	if (head == nullptr)
		return 0;

	return head->data;
}

template <class T>
const T& List<T>::GetTail() const
{
	if (tail == nullptr)
		return 0;

	return tail->data;
}

template <class T>
void List<T>::Add(const T& data)
{
	Node* newnode = new Node(data);

	if (head == nullptr)
		head = newnode;
	else
	{
		tail->next = newnode;
		newnode->previous = tail;
	}

	tail = newnode;
}

template <class T>
void List<T>::Remove(const T& data)
{
	Node* tracker = head;

	while (tracker)
	{
		if (tracker->data == data)
		{
			if (tracker->previous)
				tracker->previous->next = tracker->next;
			if (tracker->next)
				tracker->next->previous = tracker->previous;

			delete tracker;
			break;
		}

		tracker = tracker->next;
	}
}

template <class T>
void List<T>::Print() const
{
	if (head)
	{
		Node* tracker = head;

		while (tracker)
		{
			std::cout << tracker->data << ' ';
			tracker = tracker->next;
		}
	}
}

template <class T>
void List<T>::Clear()
{
	Node* tracker = head;
	Node* temp = nullptr;

	while (tracker)
	{
		if (tracker->next)
			temp = tracker->next;
		else
			temp = nullptr;

		delete tracker;

		tracker = temp;
	}

	head = nullptr;
	tail = nullptr;
}

template <class T>
void List<T>::Insert(const T& data, int index)
{
	int count = 0;
	Node* tracker = head;
	Node* newnode = new Node(data);

	while (count != index && tracker->next)
	{
		tracker = tracker->next;
		count++;
	}

	tracker->previous->next = newnode;
	newnode->previous = tracker->previous;
	tracker->previous = newnode;
	newnode->next = tracker;
}

#endif