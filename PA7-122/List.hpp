#pragma once
#include "Node.hpp"
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

//List class with insert and destroy thats all that really matters
template<class T>
class List
{
public:
	List();
	~List();
	Node<T>& operator= (const List<T>& rhs);

	//setters
	void setmpHead(Node<T>* const newPtr);

	//getters
	Node<T>* getmpHead() const;

	//member functions
	bool insert(T* const newData);
	void destroyListHelper(Node<T>* const pMem);

private:
	Node<T>* mpHead;
};

template<class T>
List<T>::List() {
	this->mpHead = nullptr;
}

template<class T>
List<T>::~List() {
	destroyListHelper(this->mpHead);
}

template<class T>
void List<T>::destroyListHelper(Node<T>* const pMem)
{
	if (pMem != nullptr)
	{
		destroyListHelper(pMem->getpNext());
		delete pMem;    // delete from the back of list to the front!
	}
}

template<class T>
Node<T>& List<T>::operator= (const List<T>& rhs) {
	
	Node<T>* pMem = rhs.getmpHead(); 

	while (pMem != nullptr) {
		T Data = pMem->getData();
		Node<T>* pNew = new Node<T>(Data);
		if (pNew != nullptr) {
			if (this->getmpHead() = nullptr) {
				this->mpHead = pNew;
			}

			else {
				Node<T>* pCur = this->getmpHead();
				while (pCur->getpNext() != nullptr) {
					pCur = pCur->getpNext();
				}
				pCur->setNext(pNew);
			}
		}

		pMem = pMem->getpNext();
	}
	
	return *this;
}

template<class T>
void List<T>::setmpHead(Node<T>* const newPtr) {
	this->mpHead = newPtr;
}

template<class T>
Node<T>* List<T>::getmpHead() const {
	return this->mpHead;
}

template<class T>
bool List<T>::insert(T* const newData) {
	Node<T>* pMem = new Node<T>(newData);
	bool success = false;

	if (pMem != nullptr) {
		if (this->mpHead == nullptr) {
			this->mpHead = pMem;
		}
		else {
			pMem->setNext(mpHead);
			this->mpHead = pMem;
		}
		success = true;
	}
	return success;
}
