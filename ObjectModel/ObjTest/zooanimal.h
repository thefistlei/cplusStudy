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
	cout << "ZooAnimal������ڴ��С��" << sizeof(ZooAnimal) << endl;

	cout << endl;

	class NullObject {
	};

	cout << "�ն�����ڴ��С��" << sizeof(NullObject) << endl;
}
