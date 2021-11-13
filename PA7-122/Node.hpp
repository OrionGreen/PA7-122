#pragma once
#include "Stack.hpp"
#include "Data.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::vector;
using std::string;

//Node class with only getters and setters
template<class T>
class Node
{
public:
	Node(T* newData);
	~Node();
	Node<T>& operator= (const Node<T>& rhs);

	//setters
	void setData(T const newData);
	void setNext(Node<T>* const newNode);

	//getters
	T* getData() const;
	Node* getpNext() const;

private:
	T* mData;
	Node* mpNext;

};

template<class T>
Node<T>::Node(T* newData) {
	this->mData = newData;
	this->mpNext = nullptr;
}

template<class T>
Node<T>::~Node() {
	delete mData;
}

template<class T>
Node<T>& Node<T>::operator= (const Node<T>& rhs) {
	this->mData = rhs.getData();
	this->mpNext = rhs.mpNext();

	return *this;
}

//setters
template<class T>
void Node<T>::setData(T const newData) {
	this->mData = newData;
}

template<class T>
void Node<T>::setNext(Node<T>* const newNode) {
	this->mpNext = newNode;
}

//getters
template<class T>
T* Node<T>::getData() const{
	return this->mData;
}

template<class T>
Node<T>* Node<T>::getpNext() const {
	return this->mpNext;
}