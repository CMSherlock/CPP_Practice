#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

template<typename T>
class LinkedList {

private:
	struct Node {
		Node* next;
		Node* prev;
		T data;
	};
	Node* head = nullptr;
	Node* tail = nullptr;
	vector<Node*> *list = nullptr;

#pragma region private search functions

	Node* SearchByData(T target) {							// search by data in node
		Node* ptr = head;
		while (ptr != nullptr) {
			if (ptr->data == target) {
				return ptr;
			}
			ptr = ptr->next;
		}
		return ptr;
	}

	typename vector<Node*>::iterator SearchByNode(Node* node) {			//search a specific node && return an iterator
		auto it = find(this->list->begin(), this->list->end(), node);
		return it;
	}
	
#pragma endregion

	Node* GetNewNode(T data) {

		Node* node = new Node;

		node->data = data;
		node->next = nullptr;
		node->prev = nullptr;

		return node;
	}

public:
	LinkedList() {
		this->list = new vector<Node*>();
	}
	
	~LinkedList(){
		delete this->list;
	}

#pragma region insert func

	void insert(T data) {				//insert the new node to the end of the list

		Node* node = GetNewNode(data);
		this->list->push_back(node);
		
		if (head == nullptr) {		
			this->head = node;
			this->tail = node;
		}
		else {
			node->prev = this->tail;
			this->tail->next = node;
			this->tail = node;
		}
	}

	void insert(Node* cur , T data) {       //Insert after the cur node
		
		if (cur == tail) {
			this->insert(data);
			return;
		}

		Node* newNode = GetNewNode(data);

		this->list->push_back(newNode);
		cur->next->prev = newNode;
		newNode->next = cur->next;
		newNode->prev = cur;
		cur->next = newNode;

	}

	void insert(T curData, T data) {						//search the first node constains the input data && insert the new one after that
			
		 Node* cur = SearchByData(curData);
		 insert(cur , data);

	}

#pragma endregion

#pragma region remove func

	bool remove( T data ) {								//remove the first node contains the input data

		if (this->list->empty()) {
			return false;
		}

		Node* node = SearchByData(data);
		return remove(node);

	}

	bool remove(Node* node) {							//remove a specific node

		if (this->list->empty()) {
			return false;
		}

		auto it = SearchByNode(node);
		if (it == this->list->end()) {
			return false;
		}
		
		if (node == head) {
			this->head = node->next;
			this->list->erase(it);
		}
		else if (node == tail) {
			this->tail = node->prev;
			node->prev->next = nullptr;
			this->list->erase(it);
		}
		else {
			node->next->prev = node->prev;
			node->prev->next = node->next;
			this->list->erase(it);
		}

		delete node;
		node = nullptr;
		return true;
		
	}

#pragma endregion

#pragma region search func

	bool search(T target) {							// search by data in node

		if (SearchByData(target) != nullptr) {
			return true;
		}
		else {
			return false;
		}

	}

	bool search( Node* node ) {							// search by Node
		
		auto it = SearchByNode(node);
		if (it == this->list->end()) {
			return false;
		}
		else {
			return true;
		}

	}

#pragma endregion

	void PrintAllData() {

		cout << "Datas in List:" << endl;
		for (Node* node = head; node != nullptr;node = node->next ) {

			cout << node->data << endl;

		}

	}
};