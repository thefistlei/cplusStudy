#pragma once

#include "zooanimal.h"

using namespace std;

class Bear : public ZooAnimal {
public:
	Bear() {};
	~Bear() {}; 
	void rotate() {};
	virtual void dance() {}; 
protected:
	enum Dances { }; 
	Dances dances_known;
	int cell_block;
};
 
void test_Bear()
{
	cout << "Bear������ڴ��С��" << sizeof(Bear) << endl; 
}

 

