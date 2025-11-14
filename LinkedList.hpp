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
	Node<T>* temp1 = list.head;
	count = 0;
	while (temp1 != nullptr) {
		addTail(temp1->data);
		temp1 = temp1->next;
	}
	// this->head = list.head;
	// this->head->data = list.head->data;
	// this->head->next = list.head->next;
	// this->head->prev = list.head->prev;
	// this->tail = list.tail;
	// this->tail->data = list.tail->data;
	// this->tail->next = list.tail->next;
	// this->tail->prev = list.tail->prev;
	// this->count = list.count;
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
	this->clear();
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
		head->prev = node1;
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
		if (count == 1) {
			delete head;
			head = nullptr;
			tail = nullptr;
			count--;
			return true;
		}
		else {
			Node<T>* temp = head;
			head = head->next;
			head->prev = nullptr;
			delete temp;
			count--;
			return true;
		}
	}
	return false;
}

template<typename T>
bool LinkedList<T>::removeTail() {
	if (head != nullptr) {
		if (count == 1) {
			delete head;
			tail = nullptr;
			head = nullptr;
			count--;
			return true;
		}
		else {
			Node<T>* temp1 = tail;
			tail = tail->prev;
			tail->next = nullptr;
			delete temp1;
			count--;
			return true;
		}
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
			count--;
		}
	}
	if (head != nullptr) {
		delete head;
		head = nullptr;
		tail = nullptr;
		count = 0;
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


	this->clear();

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



	this->clear();
	Node<T>* temp1 = rhs.head;
	count = 0;
	while (temp1 != nullptr) {
		addTail(temp1->data);
		temp1 = temp1->next;
	}
	return *this;
}

















