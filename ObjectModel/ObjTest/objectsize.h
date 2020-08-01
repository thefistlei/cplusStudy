#pragma once

#include "zooanimal.h"

using namespace std;

namespace objectSize {
	class X {};
	class Y : public virtual X {};
	class Z : public virtual X {};
	class A : public Y, public Z {};

	// sizeof(X)�Ľ��Ϊ1
	// sizeof(Y)�Ľ��Ϊ8
	// sizeof(Z)�Ľ��Ϊ8
	// sizeof(A)�Ľ��Ϊ12


	void test()
	{
		cout << "����X���ڴ��С��" << sizeof(X) << endl;
		cout << "����Y���ڴ��С��" << sizeof(Y) << endl;
		cout << "����Z���ڴ��С��" << sizeof(Z) << endl;
		cout << "����A���ڴ��С��" << sizeof(A) << endl;

		cout << endl;
	}
}

 

