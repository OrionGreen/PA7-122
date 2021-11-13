#pragma once
#include "Stack.hpp"
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

//templated stack class that is mostly just cheating with a vector 
template<class S>
class Stack
{
public:
	Stack();
	~Stack();
	Stack& operator= (const Stack& rhs);
	void push(S const &newDate);
	void pop();
	S peek();
	bool isEmpty();
	void destroyStack();

private:
	vector<S> dateStack;
};

template<class S>
Stack<S>::Stack() {
}

template<class S>
Stack<S>::~Stack() {
	this->dateStack.clear();
}

template<class S>
Stack<S>& Stack<S>::operator= (const Stack& rhs) {
	for (int i = 0; i < rhs.dateStack.size(); i++) {
		this->dateStack.push_back(rhs.dateStack[i]);
	}
	return *this;
}

template<class S>
void Stack<S>::destroyStack() {
	this->dateStack.clear();
}

template<class S>
void Stack<S>::push(S const& newDate) {
	this->dateStack.push_back(newDate);
}

template<class S>
void Stack<S>::pop() {
	this->dateStack.pop_back();
}

template<class S>
S Stack<S>::peek() {
	return this->dateStack.back();
}

template<class S>
bool Stack<S>::isEmpty() {
	return this->dateStack.empty();
}