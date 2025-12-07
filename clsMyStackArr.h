#pragma once
#include<iostream>
#include"clsMyQueueArr.h"

template<class T>
class clsMyStackArr:public clsMyQueueArr<T>
{
public:
	void pop() {
		clsMyQueueArr<T>::_MyArray.DeleteFirstItem();
	}
	T Top() {
		return clsMyQueueArr<T>::Back();
	}
	T Bottom() {
		return clsMyQueueArr<T>::Front();
	}


};

