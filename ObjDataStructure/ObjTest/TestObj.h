#pragma once

#include <iostream>

using namespace std;

#include<windows.h>


#pragma once

#include<iostream>

namespace multiDeirve {
	class Base
	{
	public:

		Base(int i) :baseI(i) {};
		virtual ~Base() {}

		int getI() { return baseI; }

		static void countI() {};

		virtual void print(void) { cout << "Base::print()"; }

	private:

		int baseI;

		static int baseS;
	};
	class Base_2
	{
	public:
		Base_2(int i) :base2I(i) {};

		virtual ~Base_2() {}

		int getI() { return base2I; }

		static void countI() {};

		virtual void print(void) { cout << "Base_2::print()"; }

	private:

		int base2I;

		static int base2S;
	};

	class Drive_multyBase :public Base, public Base_2
	{
	public:

		Drive_multyBase(int d) :Base(1000), Base_2(2000), Drive_multyBaseI(d) {};

		virtual void print(void) { cout << "Drive_multyBase::print"; }

		virtual void Drive_print() { cout << "Drive_multyBase::Drive_print"; }

	private:
		int Drive_multyBaseI;
	};
}

using namespace std;

class Base 
{ 

public: 
	Base(int i) :iBase(i) {};
	virtual ~Base(void) { cout << "调用了析构函数"; };

	int getIBase() const { 
		cout << "调用了虚函数Base::print()"; 
		return iBase;
	}

	static int instanceCount() { 
		cout << "调用了虚函数instanceCount"; 
		return 1; 
	}

	virtual void print() const { cout << "调用了虚函数Base::print()"; } 
protected:
	int iBase;
	static int count;
};

class Derived_Overrite :	public Base
{
public:
	Derived_Overrite(int i) :Base(i) {};
	virtual ~Derived_Overrite(void) {};
	virtual void print(void) const { cout << "调用了虚函数Derived_Overrite::print()"; };

protected:
	int iDerived;
};





//class Base
//{
//public:
//
//	Base(int i) :baseI(i) {};
//
//	virtual void print(void) { cout << "调用了虚函数Base::print()"; }
//
//	virtual void setI() { cout << "调用了虚函数Base::setI()"; }
//
//	virtual ~Base() {}
//
//private:
//
//	int baseI;
//
//};

struct TypeDescriptor
{
	DWORD ptrToVTable;
	DWORD spare;
	char name[];
};

struct RTTICompleteObjectLocator
{
	DWORD signature; //always zero ?
	DWORD offset;    //offset of this vtable in the complete class
	 DWORD cdOffset;  //constructor displacement offset
	struct TypeDescriptor* pTypeDescriptor; //TypeDescriptor of the complete class
	 int * ptr;
	 //struct RTTIClassHierarchyDescriptor* pClassDescriptor; //describes inheritance hierarchy
};
