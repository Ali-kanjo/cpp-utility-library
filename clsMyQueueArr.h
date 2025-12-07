#pragma once
#include"clsDynamicArray.h"
template<class T>
class clsMyQueueArr
{
protected:
	 clsDynamicArray<T> _MyArray;
public:
	void push(T Value) {
		_MyArray.InsertAtBeginning(Value);
	}
	void pop() {
		_MyArray.DeleteLastItem();
	}
	void Print() {
		_MyArray.PrintList();
	}
	int Size() {
		return _MyArray.Size();
	}
	T Front() {
		return _MyArray.GetItem(_MyArray.Size() - 1);
	}
	T Back() {
		return _MyArray.GetItem(0);
	}
	T GetItem(int Index) {
		return _MyArray.GetItem(Index);
	}
	void Reverse() {
		_MyArray.Reverse();
	}
	void UpdateItem(int Index, T Value) {
		_MyArray.SetItem(Index, Value);
		
	};
	bool InsertAfter(int Index, T Value) {
		return _MyArray.InsertAfter(Index, Value);
	}
	bool InsertBefore(int Index, T Value) {
		return _MyArray.InsertBefore(Index, Value);
	}
	void InsertAtFront(T Value) {
		_MyArray.InsertAtBeginning(Value);
	}
	void InsertAtBack(T Value) {
		_MyArray.InsertAtEnd(Value);
	}
	bool IsEmpty() {
		return _MyArray.IsEmpty();
	}
	void Clear() {
		return _MyArray.Clear();
	}
};

