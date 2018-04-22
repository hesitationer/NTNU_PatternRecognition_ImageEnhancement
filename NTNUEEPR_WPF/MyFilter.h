#pragma once
#include "MyImage.h"

template<typename T>
class MyFilter {
public :
	MyFilter(){}
	~MyFilter() {}

	virtual MyImage<T>* Execute(MyImage<T>* input) = 0;
protected :
};