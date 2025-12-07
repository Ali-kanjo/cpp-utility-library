#pragma once

#include<iostream>
using namespace std;
template <class T> 
class clsDblLinkedList {
	int _Size = 0;
public:
	 class Node {
	 public:
		T Value;
		Node* Next;
		Node* Previous;
	};

	 Node* Head = NULL;
	void InsertAtBeginning(T Value) {

		Node* NewNode = new Node;
		NewNode->Value = Value;
		NewNode->Previous = NULL;
		NewNode->Next = Head;

		if (Head != NULL) {
			Head->Previous = NewNode;
		}

		Head = NewNode;
		_Size++;
		return;
	}
	Node* Find(T Value) {
		Node* Current = Head;
		while (Current != NULL) {
			if (Current->Value == Value) {
				return Current;
			}
			Current = Current->Next;
		}
		return NULL;
	
	}
	void InsertAtEnd(T Value) {
		Node* Current = Head;

		Node* NewNode = new Node;
		NewNode->Value = Value;
		NewNode->Next = NULL;

		if (Head == NULL) {
			NewNode->Previous = NULL;
			Head = NewNode;
		}
		else {
			while (Current->Next != NULL) {
				Current = Current->Next;
			}
			Current->Next = NewNode;
			NewNode->Previous = Current;
		}
		_Size++;
		return;
	}
	void DeleteNode(Node* NodeToDelete) {
		if (Head == NULL || NodeToDelete == NULL) {
			return;
		}
		if (Head == NodeToDelete) {
			Head = Head->Next;
		}
		if (NodeToDelete->Next != NULL) {
			NodeToDelete->Next->Previous = NodeToDelete->Previous;
		}
		if (NodeToDelete->Previous != NULL) {
			NodeToDelete->Previous->Next = NodeToDelete->Next;
		}
		_Size--;
		delete NodeToDelete;

	}
	void DeleteFirstNode() {
		if (Head == NULL)
			return;
		Node* Temp = Head;

		if (Head->Next != NULL)
			Head->Next->Previous = NULL;
		Head = Temp->Next;
		_Size--;
		delete Temp;

	}
	void DeleteLastNode() {
		Node* Current = Head;
		if (Head == NULL)
			return;
		if (Head->Next == NULL) {
			delete Head;
			Head = NULL;
			return;
		}
		while ( Current->Next->Next != NULL) {
			Current = Current->Next;
		}

		delete Current->Next;
		Current->Next = NULL;
		_Size--;
	}
	void InsertAfter(Node* N1, T Value) {

		Node* NewNode = new Node;
		NewNode->Value = Value;
		NewNode->Previous = N1;

		if (N1 == NULL) {
			return;
		}

		if (N1->Next != NULL) {
			N1->Next->Previous = NewNode;
		}
		NewNode->Next = N1->Next;
		N1->Next = NewNode;
		_Size++;
		return;
	}
	void PrintList() {
		Node* Current = Head;

		while (Current != NULL) {
			cout << Current->Value << " ";
			Current = Current->Next;
		}
		cout << endl;
	}
	int Size() {
		return _Size;
	}
	bool IsEmpty() {
		return _Size == 0;
	}
	void Clear() {
		while (_Size > 0) {
			DeleteFirstNode();
		}
	}
	void Reverse() {
		Node* Current = Head;
		Node* Temp = nullptr;
		while (Current != nullptr) {
			Temp=Current->Previous;
			Current->Previous = Current->Next;
			Current->Next = Temp;
			Current = Current->Previous;
		}
		if (Temp != nullptr) {
			Head=Temp->Previous;
		}
	}
	Node* GetNode(int Index) {
		if (Index > _Size - 1 || Index < 0)
			return NULL;

		Node* Current = Head;
		int Counter = 0;
		while (Current != NULL) {

			if (Counter == Index)
				break;
			Counter++;
			Current = Current->Next;

		}
		return Current;
	}
	T GetItem(int Index) {
		Node* ItemNode = GetNode(Index);
		if (ItemNode == NULL) 
			return NULL;
		
		else
			return ItemNode->Value;
	}
	bool UpdateItem(int Index, T NewValue) {
		Node* ItemNode = GetNode(Index);

		if (ItemNode != NULL) {
			ItemNode->Value = NewValue;
			return true;
		}
		else
			return false;

	}
	bool InsertAfter(int Index, T Value) {
		Node* ItemNode = GetNode(Index);
		if (ItemNode != NULL) {
			InsertAfter(ItemNode, Value);
			return true;
		}
		else
			return false;
	}
};

