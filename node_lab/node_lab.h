#pragma once
#include <iostream>
#include <random>
#include <stdexcept>

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
	SingleLinkedList(const SingleLinkedList<T>& other) : _size(other._size), _head(other._head) {};

	int get_size() {
		return _size;
	}

	SingleLinkedList<T> operator=(const SingleLinkedList<T> other) {
		if (_size != other._size) {
			throw runtime_error("[SingleLinkedList<T>::operator=] Different size.");
		}
		SingleLinkedList<T> copy(other);
		swap(copy);
		return *this;
	}

	void swap(SingleLinkedList<T>& other) noexcept {
		std:: swap(_size, other._size);
		std::swap(_head, other._head);
	}

	void push_tail(T value) {
		Node<T>* element = new Node<T>(value);
		if (!_head) {
			_head = element;
			_head->_next = _head;
		}
		else {
			Node<T>* current = _head;
			while (current->_next) {
				current->_next;
			}
			current->_next = element;
			element->_next = _head;
		}
	}
	
	void pop_tail() {
		if (_head) {
			Node<T>* current = _head;
			Node<T>* prev = nullptr;
			while (current->_next) {
				prev = current;
				current->_next;
			}
			if (prev) {
				prev->_next = _head;
			}
			else {
				_head = nullptr;
			}
			delete current;
		}
	}

	void print() {
		if (!_head) {
			std::cout << "List is empty." << endl;
		}
		Node<T>* current = _head;
		if (current->_next == _head) {
			cout << "List:" << current->_data << endl;
		}
		while (current->_next != _head) {
			cout << current->_data << endl;
			current = current->_next;
		}
		
		~SingleLinkedList() {

		}
	}
};