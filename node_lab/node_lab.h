#pragma once
#include <iostream>
#include <random>
#include <stdexcept>
#include <ctime>

using namespace std;

template<typename T>
struct Node {
	T _data;
	Node* _next;
	Node() : _data(0), _next(nullptr) {};
	Node(T value) {
		_data = value;
		_next = nullptr;
	}
};

template<typename T>
class SingleLinkedList {
	int _size;
	Node<T>* _head;
public:
	SingleLinkedList() : _size(0), _head(nullptr) {};
	SingleLinkedList(const SingleLinkedList<T>& other) {
		_head = nullptr;
		_size = 0;
		if (other._head) {
			Node<T>* current = other._head;
			do {
				push_tail(current->_data);
				current = current->_next;
			} while (current != other._head);
		}
	}

	SingleLinkedList(int size,const T min_value,const T max_value) : _head(nullptr) {
		if (size < 0) {
			throw out_of_range("Size can't be < 0.");
		}
		
		for (int i = 0; i < size; ++i) {
			T value = (T)(1 + (double)(rand()) / RAND_MAX * (max_value - min_value + 1));
			push_tail(value);
		}
	}

	~SingleLinkedList() {
		while (_head) {
			pop_head();
		}
	}

	int get_size() const {
		return _size;
	}

	SingleLinkedList<T> operator=(const SingleLinkedList<T> other) {
		if (other._head) {
			Node<T>* othercurrent = other._head;
			do {
				push_tail(othercurrent->_cofficient);
				othercurrent = othercurrent->_next;
			} while (othercurrent != other._head);
		}
		return *this;
	}

	void push_tail(T value) {
		Node<T>* element = new Node<T>(value);
		if (_head == nullptr) {
			_head = element;
			_head->_next = _head;
		}
		else {
			Node<T>* current = _head;
			while (current->_next != _head) {
				current = current->_next;
			}
			current->_next = element;
			element->_next = _head;
		}
		_size++;
	}

	void push_tail(SingleLinkedList<T> other) {
		if (other._head == nullptr) {
			return;
		}
		else {
			Node<T>* current = other._head;
			do {
				push_tail(current->_data);
				current = current->_next;
			} while (current != other._head);
		}
	}

	void push_head(T value) {
		Node<T>* element = new Node<T>(value);
		if (_head == nullptr) {
			_head = element;
			_head->_next = _head;
			_size++;
			return;
		}
		Node<T>* current = _head;
		while (current->_next != _head) {
			current = current->_next;
		}
		element->_next = _head;
		current->_next = element;
		_head = element;
		_size++;
	}

	void push_head(SingleLinkedList<T>& other) {
		Node<T>* othercurrent = other._head;
		if (othercurrent) {
			do {
				push_head(othercurrent->_data);
				othercurrent = othercurrent->_next;
			} while (othercurrent != other._head);
		}
	}

	void pop_head() {
		if (_size == 0) {
			cout << "List is empty." << endl;
			return;
		}
		if (_head && _head->_next == _head) {
			delete _head;
			_head = nullptr;
		}
		else {
			Node<T>* temp = _head;
			Node<T>* current = _head;
			while (current->_next != _head) {
				current = current->_next;
			}
			_head = _head->_next;
			current->_next = _head;
			delete temp;
		}
		_size--;
	}

	void pop_tail() {
		if (_size == 0) {
			cout << "List is empty." << endl;
			return;
		}
		Node<T>* current = _head;
		Node<T>* penultimate = nullptr;
		while (current->_next != _head) {
			penultimate = current;
			current = current->_next;
		}
		if (penultimate) {
			penultimate->_next = _head;
		}
		else {
			_head = nullptr;
		}
		delete current;
		_size--;

	}

	void delete_node(const Node<T>& node) {
		if (get_size() == 0) {
			return;
		}
		if (_head != nullptr) {
			Node<T>* current = _head;
			while (current->_next != _head) {
				if (node._data == current->_next->_data) {
					Node<T>* temp = current->_next;
					current->_next = current->_next->_next;
					delete temp;
					_size--;
				}
				else current = current->_next;
			}
		}
		if (_head && _head->_data == node._data) {
			pop_head();
		}
	}

	T operator[](const int index) const {
		if (index < 0 || index >= get_size()) {
			throw runtime_error("[operator[]]: Index out of range.");
		}
		if (get_size() == 0) {
			throw runtime_error("[operator[]]: List is empty.");
		}
		int counter = 0;
		Node<T>* current = _head;
		while (current) {
			if (counter == index) {
				return current->_data;
			}
			current = current->_next;
			counter++;
		}
	}


	T& operator[](const int index) {
		if (index < 0 || index >= get_size()) {
			throw runtime_error("[operator[]]: Index out of range.");
		}
		if (get_size() == 0) {
			throw runtime_error("[operator[]]: List is empty.");
		}
		int counter = 0;
		Node<T>* current = _head;
		while (current) {
			if (counter == index) {
				return current->_data;
			}
			current = current->_next;
			counter++;
		}
	}

	void print() {
		if (_head == nullptr) {
			std::cout << "List is empty." << endl;
			return;
		}
		Node<T>* current = _head;
		if (current->_next == _head) {
			cout << current->_data << endl;
			return;
		}
		while (current->_next != _head) {
			cout << current->_data << ", ";
			current = current->_next;
		}
		cout << current->_data << endl;
	}
};