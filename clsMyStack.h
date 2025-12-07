#pragma once
#include<iostream>
#include"clsMyQueue.h"
using namespace std;
template<class T>
class clsMyStack:public clsMyQueue<T>
{

public:

	void pop() {
		clsMyQueue<T>::_MyQueueLinkedList.DeleteLastNode();
	}
	T Top() {
		return clsMyQueue<T>::back();
	}
	T Bottom() {
		return clsMyQueue<T>::front();
	}

};

