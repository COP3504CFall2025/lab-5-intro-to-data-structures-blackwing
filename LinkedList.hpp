#pragma once
#include <iostream>

template<typename T>
struct Node {
	T data;
	Node* prev;
	Node* next;
};

template <typename T>
class LinkedList {

public:

	// Behaviors
	void printForward() const;
	void printReverse() const;

	// Accessors
	[[nodiscard]] unsigned int getCount() const;

	Node<T>* getHead();
	const Node<T>* getHead() const;
	Node<T>* getTail();
	const Node<T>* getTail() const;

	// Insertion
	void addHead(const T& data);
	void addTail(const T& data);

	// Removal
	bool removeHead();
	bool removeTail();
	void clear();

	// Operators
	LinkedList<T>& operator=(LinkedList<T>&& other) noexcept;
	LinkedList<T>& operator=(const LinkedList<T>& rhs);

	// Construction/Destruction
	LinkedList();
	LinkedList(const LinkedList<T>& list);
	LinkedList(LinkedList<T>&& other) noexcept;
	~LinkedList();

private:
	// Stores pointers to first and last nodes and count
	Node<T>* head;
	Node<T>* tail;
	unsigned int count;

};

template<typename T>
LinkedList<T>::LinkedList() {
	this->head = nullptr;
	this->tail = nullptr;
	this->count = 0;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list) {
	this->head = list.head;
	this->tail = list.tail;
	this->count = list.count;
}

template<typename T>
LinkedList<T>::LinkedList(LinkedList<T> &&other) noexcept {
	this->head = other.head;
	this->tail = other.tail;
	this->count = other.count;

	other.head = nullptr;
	other.tail = nullptr;
	other.count = 0;
}

template<typename T>
LinkedList<T>::~LinkedList() {
	delete this->head;
	this->head = nullptr;
	delete this->tail;
	this->tail = nullptr;
	this->count = 0;
}

template<typename T>
void LinkedList<T>::addHead(const T &data) {
	count++;
	Node<T>* node1 = new Node<T>();
	node1->data = data;
	if (head == nullptr) {
		head = node1;
		tail = node1;
	}
	else {
		node1->next = head;
		head = node1;
	}
}

template<typename T>
void LinkedList<T>::addTail(const T &data) {
	count++;
	Node<T>* node2 = new Node<T>();
	node2->data = data;
	if (head == nullptr) {
		head = node2;
		tail = node2;
	}
	else {
		tail->next = node2;
		node2->prev = tail;
		tail = node2;
		node2->next = nullptr;
	}
	//node1->next = tail;
}

template<typename T>
bool LinkedList<T>::removeHead() {
	if (head != nullptr) {
		count--;
		Node<T>* temp = head;
		head = head->next;
		delete temp;
		return true;
	}
	return false;
}

template<typename T>
bool LinkedList<T>::removeTail() {
	if (head != nullptr) {
		count--;
		Node<T>* temp = tail;
		tail = tail->prev;
		delete temp;
		return true;
	}
	return false;
}

template<typename T>
void LinkedList<T>::clear() {
	Node<T>* temp = head;
	// while (temp != nullptr) {
	// 	delete temp;
	// 	temp = temp->next;
	// }

	for (unsigned int i = 0; i < count; i++) {
		if (head->next != nullptr) {
			temp = head->next;
			delete head;
			head = temp;
		}
	}
}

template<typename T>
Node<T>* LinkedList<T>::getHead() {
	return head;
}

template<typename T>
const Node<T>* LinkedList<T>::getHead() const {
	return head;
}

template<typename T>
Node<T>* LinkedList<T>::getTail() {
	return tail;
}

template<typename T>
const Node<T>* LinkedList<T>::getTail() const {
	return tail;
}

template<typename T>
[[nodiscard]] unsigned int LinkedList<T>::getCount() const {
	return count;
}

template<typename T>
void LinkedList<T>::printForward() const {
	for (Node<T>* tempNode = head; tempNode != nullptr; tempNode = tempNode->next) {
		std::cout << tempNode->data << " " << std::endl;
	}
}

template<typename T>
void LinkedList<T>::printReverse() const {
	for (Node<T>* tempNode = tail; tempNode != nullptr; tempNode = tempNode->prev) {
		std::cout << tempNode->data << " " << std::endl;
	}
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> &&other) noexcept {
	if (this == &other) {
		return *this;
	}

	delete this->head;
	delete this->tail;

	this->head = other.head;
	this->tail = other.tail;
	this->count = other.count;

	other.head = nullptr;
	other.tail = nullptr;
	other.count = 0;

	return *this;
}

template<typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs) {
	if (this == &rhs) {
		return *this;
	}

	delete this->head;
	delete this->tail;

	this->head = rhs.head;
	this->tail = rhs.tail;
	this->count = rhs.count;
	return *this;
}

















