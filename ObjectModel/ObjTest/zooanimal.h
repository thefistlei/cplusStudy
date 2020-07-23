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

 

