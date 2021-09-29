#pragma once

template <class T>
struct Node {
	Node<T>* next;
	T value;
	Node(const T& item) : next(nullptr), value(item) {}
};

template <class T>
struct ListIterator {
	Node<T>* ptr;

	ListIterator(Node<T>* new_ptr) : ptr(new_ptr) {}

	T& operator*() const {
		return ptr->value;
	}

	bool operator!=(const ListIterator& it) {
		return (ptr != it.ptr);
	}

	ListIterator& operator++() {
		ptr = ptr->next;
		return *this;
	}
};

template <class T>
struct List {
	Node<T>* first;

	List() : first(nullptr) {}

	List(const List<T>& lst) : first(nullptr) {
		Node<T>* current = lst.first;
		while (current != nullptr) {
			add(current->value);
			current = current->next;
		}
	}

	~List() {
		if (first != nullptr) {
			Node<T>* last = first, * current = first->next;
			while (current != nullptr) {
				delete last;
				last = current;
				current = current->next;
			}
			delete last;
		}
	}

	ListIterator<T> begin() const {
		return ListIterator<T>(first);
	}

	ListIterator<T> end() const {
		return ListIterator<T>(nullptr);
	}

	void add(const T& item) {
		if (first == nullptr) {
			first = new Node<T>(item);
		}
		else {
			Node<T>* current = first;
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = new Node<T>(item);
		}
	}
};
