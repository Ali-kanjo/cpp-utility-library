#pragma once
#include<iostream>
using namespace std;
template<class T>
class clsDynamicArray
{
protected:
	int _Size ;
	T* _TempArray;
	T* _OriginalArray;
public:
	clsDynamicArray(int Size = 0) {
		if (Size < 0) {
			Size = 0;
		}

		_OriginalArray = new T[Size];
		_Size = Size;
	}
	~clsDynamicArray() {
		delete[]_OriginalArray;
	}
	void SetItem(int Index, T Value) {
		if (Index < 0 || Index >= _Size) {
			return;
		}
		_OriginalArray[Index] = Value;
	}
	int Size() {
		return _Size;
	}
	bool IsEmpty() {
		return (_Size == 0) ? true : false;
	}
	void PrintList() {
		for (int i = 0; i <= _Size - 1; i++) {
			cout << _OriginalArray[i] << " ";
		}
		cout << endl;
	}
	void ReSize(int ReSizedArraySize){
		if (ReSizedArraySize < 0)
			return;
		 _TempArray = new T[ReSizedArraySize];
		int CommonSize = (_Size > ReSizedArraySize) ? ReSizedArraySize : _Size;
		for (int i = 0; i <= CommonSize - 1; i++) {
			_TempArray[i] = _OriginalArray[i];
		}
		delete[]_OriginalArray;
		_OriginalArray = _TempArray;
		_Size = ReSizedArraySize;
	}
	T GetItem(int Index) {
		if (Index < 0 || Index >= _Size)
			return NULL;

		return _OriginalArray[Index];
	}
	void Reverse() {
		_TempArray = new T[_Size];
		for (int i = 0; i <= _Size - 1; i++) {
			_TempArray[i] = _OriginalArray[_Size - 1 - i];
		}
		delete[] _OriginalArray;
		_OriginalArray = _TempArray;
	}
	void Clear() {
		_Size = 0;
		_TempArray = new T[0];
		delete[]_OriginalArray;
		//_OriginalArray = nullptr;
		_OriginalArray = _TempArray;
	}
	void DeleteItemAt(int Index) {
		if (Index < 0 || Index >= _Size)
			return;
		_Size--;

		_TempArray = new T[_Size];
		int Counter = 0;

		for (int i = 0; i < Index; i++) {
			_TempArray[i] = _OriginalArray[i];
		}
		for (int i = Index + 1; i <= _Size ; i++) {
			_TempArray[i - 1] = _OriginalArray[i];
		}

		delete[]_OriginalArray;
		_OriginalArray = _TempArray;

	}
	void DeleteFirstItem() {
		DeleteItemAt(0);
	}
	void DeleteLastItem() {
		DeleteItemAt(_Size - 1);
	}
	int Find(T Value) {

		for (int i = 0; i <= _Size - 1; i++) {

			if (_OriginalArray[i] == Value)
				return i;

		}
		return -1;
	}
	bool DeleteItem(T Value) {
		int Index = Find(Value);
		if (Index != -1) {
			DeleteItemAt(Index);
			return true;
		}
		return false;
	}
	bool InsertAt(int Index, T Value) {
		if (Index < 0 || Index > _Size)
			return false;

		_Size++;
		_TempArray = new T[_Size];
		for (int i = 0; i < Index; i++) {
			_TempArray[i] = _OriginalArray[i];
		}
		_TempArray[Index] = Value;

		for (int i = Index; i < _Size - 1; i++) {
			_TempArray[i + 1] = _OriginalArray[i];
		}
		delete[]_OriginalArray;
		_OriginalArray = _TempArray;
		return true;
	}
	void InsertAtBeginning(T Value) {
		InsertAt(0,Value);
	}
	void InsertAtEnd(T Value) {
		InsertAt(_Size, Value);
	}
	bool InsertBefore(int Index, T Value) {
		if (Index >= _Size)
			return false;

		return InsertAt(Index, Value);
	};
	bool InsertAfter(int Index, T Value) {
		if (Index < 0)
			return false;

		return InsertAt(Index + 1, Value);
	}
};

