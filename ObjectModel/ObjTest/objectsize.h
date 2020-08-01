#pragma once

#include "zooanimal.h"

using namespace std;

namespace objectSize {
	class X {};
	class Y : public virtual X {};
	class Z : public virtual X {};
	class A : public Y, public Z {};

	// sizeof(X)的结果为1
	// sizeof(Y)的结果为8
	// sizeof(Z)的结果为8
	// sizeof(A)的结果为12


	void test()
	{
		cout << "对象X的内存大小：" << sizeof(X) << endl;
		cout << "对象Y的内存大小：" << sizeof(Y) << endl;
		cout << "对象Z的内存大小：" << sizeof(Z) << endl;
		cout << "对象A的内存大小：" << sizeof(A) << endl;

		cout << endl;
	}
}

 

