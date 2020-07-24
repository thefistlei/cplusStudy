#pragma once

#include <iostream>

using namespace std;

class ZooAnimal {
public:
	ZooAnimal() {}
	virtual ~ZooAnimal() {}
	virtual void rotate() {}
protected:
	int loc;
	char* psz;
	int nLen;
 	//string name;
};




void test_ZooAnimal()
{
	cout << "ZooAnimal对象的内存大小：" << sizeof(ZooAnimal) << endl;

	cout << endl;

	class NullObject {
	};

	cout << "空对象的内存大小：" << sizeof(NullObject) << endl;
}
