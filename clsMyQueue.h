#pragma once
#include<iostream>
#include"clsDblLinkedList.h"
using namespace std;
template <class T> 
class clsMyQueue 
{
protected:
	 clsDblLinkedList<T> _MyQueueLinkedList;
public:
	void push(T Value) {
		_MyQueueLinkedList.InsertAtEnd(Value);
	}
	void pop() {
		_MyQueueLinkedList.DeleteFirstNode();
	}
	int Size() {
		return _MyQueueLinkedList.Size();
	}
	T front() {
		return _MyQueueLinkedList.GetItem(0);
	}
	T back() {
		return _MyQueueLinkedList.GetItem(Size() - 1);
	}
	void Print() {
		_MyQueueLinkedList.PrintList();
	}
	bool IsEmpty() {
		return _MyQueueLinkedList.IsEmpty();
	}
	T GetItem(T Value) {
		return _MyQueueLinkedList.GetItem(Value);
	}
	void Reverse() {
		_MyQueueLinkedList.Reverse();
	}
	void InsertAfter(int Index, T Value) {
		_MyQueueLinkedList.InsertAfter(Index, Value);
	}
	void InsertAtFront(T Value) {
		_MyQueueLinkedList.InsertAtBeginning(Value);
	}
	void InsertAtBack(T Value) {
		_MyQueueLinkedList.InsertAtEnd(Value);
	}
	void Clear() {
		_MyQueueLinkedList.Clear();
	}
	void UpdateItem(int Index, T Value) {
		_MyQueueLinkedList.UpdateItem(Index, Value);
	}

};

